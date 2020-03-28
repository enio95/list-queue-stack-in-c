#ifndef OBJETO
#define OBJETO
#include <stdio.h>
#include <stdlib.h>

/* Change the following structure to adapt to you code 
   You can change it to hold any information vital to
   you program. list.c and heap.c will Handle*/
typedef struct obj
{
  int id;
  
}obj;

/* Also change the following function in objeto.h and objeto.c*/
obj *newObject(int);
int compare(obj *, obj *);
void printObject(obj *);
void errorMessageMem(char *);

#endif
