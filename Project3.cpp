/*
 * Copy the contents of header.txt (filled out) and paste here
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <cstdio>
#include "UTString.h"

/*
 * Helper macro to find the signature of a UTString
 * Treat this like a function that takes a UTString*
 * Accesses a uint32_t from where the signature should be located
 */
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
 * Checks if a UTString is valid or not.
 */
bool isOurs(const UTString* s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}

/*
 * Allocate a utstring on the heap.
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */
UTString* utstrdup(const char* src) {
    int x = 0;
    //int i = 0;
    int j = 0;
    UTString * strptr = (UTString*) malloc(sizeof(UTString));
    char* utstr = (char*) malloc(sizeof(char) * (strptr->capacity));
    strptr->string = utstr;
    while (src[x] != '\0'){
        x++;
    }
    if (x ==0){
        strptr->capacity = 1;
    }else {
        strptr->capacity = x;
    }
    while (src[j] != '\0'){
        strptr->string[j] = src[j];
        j++;
    }
    if (j ==0){
        strptr->string[j+1] = '\0';
    }else{
        strptr->string[j] = '\0';
    }
    //utstrcpy(strptr, src);
    //printf("%d", strptr->length); //used to test
    //strptr->length = utstrlen(strptr);// neccessary done in utstrcpy but utstrlen works
    //printf("%d", strptr->length); //*used to test

    return strptr;
}

/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */
uint32_t utstrlen(const UTString* s) {
    char* src;
    src = s->string;
    uint32_t w = 0;
    while (src[w] != '\0'){
        w++;
    }
    //printf("%d", w); used to test

    return w;
}

/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s.
 * Update the length of s.
 * Return s with the above changes. */
UTString* utstrcat(UTString* s, const char* suffix) {
    int j = 0;
    int i = 0;
    j = s->length;
    //while (s->string[j] != '\0'){
      //  j++;
    //}
    while (suffix[i] != '\0'){
        i++;
    }

    if (s->capacity < j + i -1){
        i = 0;
        while (s->capacity != j){
            s->string[j] = suffix[i];
            i++;
            j++;
        }
        s->string[j] = NULL;
    }

    if(s->capacity > j + i -1) {
        i = 0;

        //s->string[j] = suffix[i];
        while (suffix[i] != '\0') {
            s->string[j] = suffix[i];
            i++;
            j++;
        }
        s->string[j] = NULL;

    }
    s->length = j;
    return s;
}

/*
 * Copy src into dst.
 *  dst must be a valid UTString.
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst.
 * Return dst with the above changes.
 */
UTString* utstrcpy(UTString* dst, const char* src) {
    int x = 0;
    //char* oldstr = dst->string;


    if (dst->string != src) {
        while (src[x] != '\0') {
            dst->string[x] = src[x];
            x++;
        }
        dst->length = x;
        if (x ==0){
            dst->string[x+1] = NULL;
        }else {
            dst->string[x] = NULL;
        }


        if (x > dst->capacity){
            dst->string[dst->capacity] = '\0';
        }
    }
    return dst;
}

/*
 * Free all memory associated with the given UTString.
 */
void utstrfree(UTString* self) {
    free(self->string);
    free(self);
}

/*
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity,
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata.
 * Return s with the above changes.
 */
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    int w = 0;
    while (s->string[w] != '\0'){
        w++;
    }
    s->length = w;

    if (s->capacity < new_capacity){
        s->capacity = new_capacity;
        char* newstr = (char*) malloc(sizeof(char)*new_capacity + 5);
        char* oldstr = s->string;
        s->string = newstr;

        strcpy(newstr, oldstr);
        free(oldstr);

        //UTString * s = (UTString*)malloc(sizeof(UTString)); //confused on how to reallocate space
    }
    return s;
}
