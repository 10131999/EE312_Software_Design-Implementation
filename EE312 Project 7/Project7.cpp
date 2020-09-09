/*
 * Name:Zane Zwanenburg
 * EID: Zaz239
 * Project 7, CRM part 2
 * EE 312, Fall 2019
 */

#include <stdio.h>
#include <cstring>
#include "UTString.h"
#include "Customer.h"
#include "CustomerDB.h"

void readString(UTString&);
void readNum(int&);

CustomerDB database;


int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;

/* clear the inventory and reset the customer database to empty */
void reset(void) {
    database.clear();
    num_bottles = 0;
    num_rattles = 0;
    num_diapers = 0;
}

/*
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Bottles", "Diapers" or "Rattles"
 * for example the expression *selectInventItem("Bottles") returns the
 * current global variable for the number of bottls in the inventory
 */
int* selectInventItem(UTString word) {
    if (word == "Bottles") {
        return &num_bottles;
    } else if (word == "Diapers") {
        return &num_diapers;
    } else if (word == "Rattles") {
        return &num_rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(UTString word, Customer& cust) {
    if (word == "Bottles") {
        return &cust.bottles;
    } else if (word == "Diapers") {
        return &cust.diapers;
    } else if (word == "Rattles") {
        return &cust.rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Bottles", "Rattles" or "Diapers".
 *
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(UTString type) {
    Customer* result = 0;
    int max = 0;
    for (int k = 0; k < database.size(); k += 1) {
        Customer& cust = database[k];
        int *p = selectInventItem(type, cust);
        if (*p > max) {
            max = *p;
            result = &cust;
        }
    }

    return result;
}

void processPurchase() {
    // not done, your effort goes here
    UTString (Diapers) = "Diapers";
    UTString (Rattles) = "Rattles";
    UTString (Bottles) = "Bottles";
    int next1;
    UTString next;
    UTString name1;
    //code for determining the customer purchasing
    readString(name1);

    readString(next);
    readNum(next1);

    //code for removing purchase from inventory
    int x = *selectInventItem(next);
    if (next1 <= x){
        database[name1].name;
    }

    if (next1 > x){
        if (next == Bottles){
            printf("Sorry %s, we only have %d Bottles\n", name1.c_str(), x);
        }
        if (next == Diapers){
            printf("Sorry %s, we only have %d Diapers\n", name1.c_str(), x);
        }
        if (next == Rattles){
            printf("Sorry %s, we only have %d Rattles\n", name1.c_str(), x);
        }

    }else{
        if (next == Bottles){
            database[name1].bottles += next1;
            num_bottles -= next1;
        }else if (next == Rattles){
            database[name1].rattles += next1;
            num_rattles -= next1;
        }else if (next == Diapers){
            database[name1].diapers += next1;
            num_diapers -= next1;
        }else{
            printf("Something is fucked up\n");
        }
    }

}

void processSummarize() {
    // not done, your effort goes here
    UTString (Diapers) = "Diapers";
    UTString (Rattles) = "Rattles";
    UTString (Bottles) = "Bottles";
    UTString Sue = "Sue";
    UTString Craig = "Craig";
    printf("There are %d Bottles, %d Diapers and %d Rattles in inventory\n", num_bottles, num_diapers, num_rattles);
    printf("we have had a total of %d different customers\n", database.size());//fix the number input where 5 is
    if (findMax(Bottles) != NULL){
        printf("%s has purchased the most Bottles (%d)\n", findMax(Bottles)->name.c_str(), findMax(Bottles)->bottles);
    }else{
        printf("no one has purchased any Bottles\n");
    }
    if (findMax(Diapers) != NULL){
        printf("%s has purchased the most Diapers (%d)\n", findMax(Diapers)->name.c_str(), findMax(Diapers)->diapers);
    }else{
        printf("no one has purchased any Diapers\n");
    }
    if (findMax(Rattles) != NULL){
        printf("%s has purchased the most Rattles (%d)\n", findMax(Rattles)->name.c_str(), findMax(Rattles)->rattles);
    }else{
        printf("no one has purchased any Rattles\n");
    }


}

void processInventory() {
    // not done, your effort goes here
    //should work except might cause memory leak with the UTString
    UTString (Diapers) = "Diapers";
    UTString (Rattles) = "Rattles";
    UTString (Bottles) = "Bottles";
    int next1;
    UTString next;
    readString(next);
    if (next == Bottles){
        readNum(next1);

        num_bottles += next1;
        //printf("Inventory Bottles %d\n", num_bottles);
    }
    if (next == Rattles){
        readNum(next1);

        num_rattles += next1;
       // printf("Inventory Rattles %d\n", num_rattles);
    }
    if (next == Diapers){
        readNum(next1);

        num_diapers += next1;
        //printf("Inventory Diapers %d\n", num_diapers);
    }
    UTString();


}
