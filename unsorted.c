/* 
 * File:   unsorted.c
 * Author: Jake Day
 * Class: COEN 12
 * Instructor: Atkinson
 * Section: T 5:15-8pm
 * Created on April 5, 2016, 5:26 PM
 * Description: This program implements a set abstract data type for strings
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "set.h"

int findElement(SET *sp, char *elt, bool *found);

/*
 * Big O Notation: O(1)
 * Description!?
 */
struct set {
    int count;
    int length;
    char **elts;
};

/*
 * Big O Notation: O(1)
 * Returns a pointer to a new set with a maximum capacity of maxElts
 */
SET *createSet(int maxElts) {
    SET *sp;
    sp = malloc(sizeof (SET));
    assert(sp != NULL);
    sp->count = 0;
    sp->length = maxElts;
    sp->elts = malloc(sizeof (char*) * maxElts);
    assert(sp->elts != NULL);
    return sp;
}

/*
 * Big O Notation: O(n)
 * Deallocates memory associated with the set pointed to by sp
 */
void destroySet(SET *sp) {
    assert(sp != NULL);
    for (int i = 0; i < sp->count; i++) {
        free(sp->elts[i]); //destroy each string in the array
    }
    free(sp->elts); //destroy pointers   
    free(sp); //destroy set
}

/*
 * Big O Notation: O(1)
 * Returns the number of elements in the set pointed to by sp
 */
int numElements(SET *sp) {
    assert(sp != NULL);
    return sp->count;
}

/*
 * Big O Notation: O(n)
 * Returns the location of an element in an array using a linear search
 */
int findElement(SET *sp, char *elt, bool *found) {
    assert(sp != NULL && elt != NULL);
    for (int i = 0; i < sp->count; i++) {
        if (strcmp(elt, sp->elts[i]) == 0) {
            *found = true;
            return i;
        }
    }
    *found = false;
    return -1;
}

/*
 * Big O Notation: O(n)
 * Returns whether elt is a member of the set pointed to by sp
 */
bool hasElement(SET *sp, char *elt) {
    assert(sp != NULL && elt != NULL);
    bool f;
    findElement(sp, elt, &f);
    return f; //returns whether findElement() found the location of an element or not
}

/*
 * Big O Notation: O(n)
 * Add elt to the set pointed to by sp, and return whether the set changed
 */
bool addElement(SET *sp, char *elt) {
    assert(sp != NULL && elt != NULL);
    bool f;
    findElement(sp, elt, &f);

    if (sp->count == sp->length || f) { //doesn't add an element if there's no space or it already exists
        return false;
    }
    elt = strdup(elt); //creates a pointer to a new string, a duplicate of the string pointed to by elt
    assert(elt != NULL);
    sp->elts[sp->count++] = elt;
    return true;
}

/*
 * Big O Notation: O(n)
 * Remove elt from the set pointed to by sp, and return whether the set changed
 */
bool removeElement(SET *sp, char *elt) {
    assert(sp != NULL && elt != NULL);
    bool f;
    int pos = findElement(sp, elt, &f);
    if (sp->count == 0 || !f) {
        return false;
    }
    free(sp->elts[pos]);
    sp->elts[pos] = sp->elts[--sp->count];
    return true;
}