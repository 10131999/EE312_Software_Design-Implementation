/* 
 * EE312 Simple CRM Project
 *
 * Zane Zwanenburg
 * zaz239
 */

#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"
#include <cstdio>
#include <cstdlib>

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

int next1;
String prev;
String bottlesname;
String rattlesname;
String diapersname;
String next;
String bottles;
String rattles;
String diapers;
int bottlesnum = 0;
int rattlesnum = 0;
int diapersnum = 0;
int j;
int i;
int bottlesmax;
int rattlesmax;
int diapersmax;
/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */


/* clear the inventory and reset the customer database to empty */
void reset(void) {
	/* your code here */
	j = 0;

    StringDestroy(&prev);
    prev.len = 0;
    StringDestroy(&next);
    next.len = 0;

	while (j < num_customers){
	    StringDestroy(&customers[j].name);
	    customers[j].name.len = 0;
	    customers[j].name.ptr = NULL;
	    customers[j].bottles = 0;
	    customers[j].rattles = 0;
	    customers[j].diapers = 0;
	    j++;
	}


	num_customers = 0;
    bottlesnum = 0;
    rattlesnum = 0;
    diapersnum = 0;
    bottlesmax = 0;
    rattlesmax = 0;
    diapersmax = 0;
    
}

void processSummarize() {
    int j = 0;

    rattlesmax = 0;
    bottlesmax = 0;
    diapersmax = 0;
    while (j < num_customers){
        if ( customers[j].bottles > bottlesmax){
            bottlesmax = customers[j].bottles;
            StringReAssign(&bottlesname, &customers[j].name);
        }
        if ( customers[j].rattles > rattlesmax){
            rattlesmax = customers[j].rattles;
            StringReAssign(&rattlesname, &customers[j].name);
        }
        if ( customers[j].diapers > diapersmax){
            diapersmax = customers[j].diapers;
            StringReAssign(&diapersname, &customers[j].name);
        }
        j++;
    }

    printf("\nThere are %d Bottles, %d Diapers and %d Rattles in inventory", bottlesnum, diapersnum, rattlesnum);
    printf("\nwe have had a total of %d different customers",num_customers);
    if ( bottlesmax == 0){
        printf("\nno one has purchased any Bottles");
    }else{
        printf("\n");
        StringPrint(&bottlesname);
        printf(" has purchased the most Bottles (%d)", bottlesmax);
    }
    if ( diapersmax == 0){
        printf("\nno one has purchased and Diapers");
    }else{
        printf("\n");
        StringPrint(&diapersname);
        printf(" has purchased the most Diapers (%d)", diapersmax);
    }
    if ( rattlesmax == 0){
        printf("\nno one has purchased the most Rattles");
    }else{
        printf("\n");
        StringPrint(&rattlesname);
        printf(" has purchased the most Rattles (%d)", rattlesmax);
    }


}

void processPurchase() {

    int exists = 0;
    bottles = StringCreate("Bottles");
    rattles = StringCreate("Rattles");
    diapers = StringCreate("Diapers");
    i = 0;
    readString(&next);
    while (i <= num_customers){
        if (StringIsEqualTo(&customers[i].name, &next)){
            //put data in correct spot
            readString(&next);

            if (StringIsEqualTo(&next, &bottles)) {
                readNum(&next1);
                if (next1 > bottlesnum) {
                    printf("\nSorry ");
                    StringPrint(&customers[i].name);
                    printf(", we only have %d bottles.", bottlesnum);
                } else {
                    customers[i].bottles += next1;
                    bottlesnum = bottlesnum - next1;
                    //printf("%d\n", customers[i].bottles);

                }
                StringDestroy(&bottles);
                StringDestroy(&rattles);
                StringDestroy(&diapers);
            }
            if (StringIsEqualTo(&next, &rattles)) {
                readNum(&next1);
                if (next1 > rattlesnum) {
                    printf("\nSorry ");
                    StringPrint(&customers[i].name);
                    printf(", we only have %d rattles.", rattlesnum);
                } else {
                    customers[i].rattles += next1;
                    rattlesnum = rattlesnum - next1;
                    //printf("%d\n", customers[i].rattles);

                }
                StringDestroy(&bottles);
                StringDestroy(&rattles);
                StringDestroy(&diapers);
            }
            if (StringIsEqualTo(&next, &diapers)) {
                readNum(&next1);
                if (next1 > diapersnum) {
                    printf("\nSorry ");
                    StringPrint(&customers[i].name);
                    printf(", we only have %d diapers.", diapersnum);
                } else {
                    customers[i].diapers += next1;
                    diapersnum = diapersnum - next1;
                    //printf("%d\n", customers[i].diapers);

                }
                StringDestroy(&bottles);
                StringDestroy(&rattles);
                StringDestroy(&diapers);
            }
            i = num_customers ;
            exists = 1;
        }else{
            i ++;
        }
    }
    //creating new customer
    if (exists == 0){
        StringReAssign(&prev, &next);



        readString(&next);

        if (StringIsEqualTo(&next, &bottles)) {
            readNum(&next1);
            if (next1 > bottlesnum) {
                printf("\nSorry ");
                StringPrint(&prev);
                printf(", we only have %d bottles.", bottlesnum);

            } else {
                customers[num_customers].bottles += next1;
                bottlesnum = bottlesnum - next1;
                StringReAssign(&customers[num_customers].name, &prev);
                num_customers ++;
                //printf("%d\n", customers[i].bottles);

            }
            StringDestroy(&bottles);
            StringDestroy(&rattles);
            StringDestroy(&diapers);
        }
        if (StringIsEqualTo(&next, &rattles)) {
            readNum(&next1);
            if (next1 > rattlesnum) {
                printf("\nSorry ");
                StringPrint(&prev);
                printf(", we only have %d rattles.", rattlesnum);
            } else {
                customers[num_customers].rattles += next1;
                rattlesnum = rattlesnum - next1;
                StringReAssign(&customers[num_customers].name, &prev);
                num_customers ++;
                //printf("%d\n", customers[i].rattles);

            }
            StringDestroy(&bottles);
            StringDestroy(&rattles);
            StringDestroy(&diapers);
        }
        if (StringIsEqualTo(&next, &diapers)) {
            readNum(&next1);
            if (next1 > diapersnum) {
                printf("\nSorry ");
                StringPrint(&prev);
                printf(", we only have %d diapers.", diapersnum);
            }else{
                customers[num_customers].diapers += next1;
                diapersnum = diapersnum - next1;
                StringReAssign(&customers[num_customers].name, &prev);
                num_customers ++;
                //printf("%d\n", customers[i].diapers);

            }

        }



    }

}

void processInventory() {

    bottles = StringCreate("Bottles");
    rattles = StringCreate("Rattles");
    diapers = StringCreate("Diapers");

    readString(&next);

    if (StringIsEqualTo(&next, &bottles)){
        readNum(&next1);
        bottlesnum += next1;


    }
    if (StringIsEqualTo(&next, &rattles)){
        readNum(&next1);
        rattlesnum += next1;


    }
    if (StringIsEqualTo(&next, &diapers)){
        readNum(&next1);
        diapersnum += next1;

    }
    StringDestroy(&bottles);
    StringDestroy(&rattles);
    StringDestroy(&diapers);
    StringDestroy(&next);










}
