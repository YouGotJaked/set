/* 
 * File:   set.h
 * Author: jakeday
 *
 * Created on April 5, 2016, 5:22 PM
 */

#ifndef SET_H
#define SET_H

typedef struct set SET;

SET *createSet(int maxElts);

void destroySet(SET *sp);

int numElements(SET *sp);

bool hasElement(SET *sp, char *elt);

bool addElement(SET *sp, char *elt);

bool removeElement(SET *sp, char *elt);

# endif /* SET_H */

