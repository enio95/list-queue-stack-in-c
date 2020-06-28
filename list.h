#ifndef LIST
#define LIST

#include <stdlib.h>
#include <stdio.h>

/* prev -> pointer to the previous Qnode
   next -> pointer to the next Qnode
   elm -> pointer to a piece of memory defined by the user*/
typedef struct Qnode
{
  void *elem;

  struct Qnode *prev, *next;

}Qnode;

/* size -> size of the list
   head and tail should not be used to get the first element
   because they do NOT hold read values, but are there
   for an easier insertion and remove*/
typedef struct List
{
  int size;

  Qnode *head, *tail;

}List;

/* Allocates memory for a list and return a pointer.
   On fail return NULL*/
List* allocList();

/* Allocates new momory for a Qnode and return its pointer,
   On fail return NULL*/
Qnode* allocQnode(void *elem);

/* Return the pointer of type Qnode for the first Qnode
   in the list. On fail return NULL*/
Qnode* topQnode(List *list);

/* Returns the pointer for the first element of the list.
   On fail return NULL*/
void* top(List *list);

/* Return the list size*/
int listIsEmpty(List *list);

/* Add (*elem) to the beginig of the list. This function
   return the pointer (*elem) on success, otherwise
   NULL is returned.*/
void* push(List *list, void *elem);

/* Add (*elem) to the end of the list. This function
   return the pointer (*elem) on success, otherwise
   NULL is returned.*/
void* enqueue(List *list, void *elem);

/* Removes the first element of the list and returns its
   pointer. On fail dequeue return NULL*/
void* dequeue(List *list);

/* Removes the first element of the list and returns its
   pointer. On fail dequeue return NULL*/
void* pop(List *list);

/* Print all the elements of the list. This function takes two
   arguments, (List *list) which is a pointer to the list and
   (void (*print)(const void *elem) which is a pointer to the
   function that prints an element saved by Qnode.*/
void printList(List *list, void (*print)(const void *elem));

/* This function frees all the memory allocated in *list.
   This function takes two arguments (List *list)
   which is a pointer to the list and (void (*print)(void *elem))
   which is a pointer to the function that frees an element
   (void *elem) save by each Qnode*/
void freeList(List *list, void (*freeElem)(void *elem));

#endif
