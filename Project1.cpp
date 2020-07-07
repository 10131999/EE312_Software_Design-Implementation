/*
 * Project1.cpp
 *
 * Name: Zane Zwanenburg
 * EE312 Summer 2020
 * SuperStrings
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types

/*
All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)

You must write this function (printSuperStrings). Do not change the way the function is declared (i.e., it has
exactly two parameters, each parameter is a standard (mundane) C string (see Instruction).
*/
void printString(int q, char stringmatch []){
    while (stringmatch[q] != '\n' && stringmatch[q] != ' ' && stringmatch[q] != '\0'){
        printf("%c", stringmatch[q]);
        q++;
    }
    printf("\n");
}

void checkCandidates(int y, int z, int n,char supstring[], char sstring[]){
    int sptr = y;
    z = 0;
    while (supstring[z] != '\0') {
        int r = 0;
        int t = z;
        while (supstring[z] != '\n' && supstring[z] != ' ' && supstring[z] != '\0') {
            if (supstring[z] == sstring[y]) {
                r++;
                y++;
            }
            z++;
        }
        if (r == n) {
            printString(t, supstring);
        }
        y = sptr;
        if (supstring[z] != '\0') {
            z++;
        }
    }

}


void printSuperStrings(char target [], char candidates []) {
    int x = 0;
    int n = 0;
    int p = 0;
                                //n finds the legnth of the target string
    while (target[x] != '\0'){      //goes to function checkCandidate with each target string to check with candidates
        while (target[p] != ' ' && target[p] != '\0' && target[p] != '\n'){
            n++;
            p++;
        }
        checkCandidates(x, 0, n, candidates,target);

        n = 0;
        x = p;
        if (target[p] != '\0'){
            x++;
            p++;

        }



    }
}
