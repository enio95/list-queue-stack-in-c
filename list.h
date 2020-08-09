#ifndef LIST
#define LIST

#include <stdlib.h>
#include <stdio.h>

/* START: Qnode data structure.
   prev -> pointer to the previous Qnode.
   next -> pointer to the next Qnode.
   elm -> pointer to a piece of memory defined by the user. */
typedef struct Qnode
{
  void *elem;

  struct Qnode *prev, *next;

}Qnode;
/* END: Qnode data structure. */

/* START: List data structure.
   size -> size of the list.
   head and tail should not be used to get the first element.
   because they do NOT hold read values, but are there.
   for an easier insertion and remove. */
typedef struct List
{
  int size;

  Qnode *head, *tail;

}List;
/* END: */

/* START: Allocates memory for a list and returns a pointer.
   On fail return NULL*/
List* allocList();
/* END: */

/* START: Returns the pointer for the first element of the list.
   On fail return NULL*/
void* top(List *list);
/* END: */

/* START: Return 1 if list is empty otherwise 0.*/
int listIsEmpty(List *list);
/* END: */

/* START: Add (*elem) to the beginig of the list. This function
   returns the pointer (*elem) on success, otherwise
   NULL is returned.*/
void* push(List *list, void *elem);
/* END: */

/* START: Add (*elem) to the end of the list. This function
   return the pointer (*elem) on success, otherwise
   NULL is returned.*/
void* enqueue(List *list, void *elem);
/* END: */

/* START: Removes the first element of the list and returns its
   pointer. On fail dequeue return NULL*/
void* dequeue(List *list);
/* END: */

/* START: Removes the first element of the list and returns its
   pointer. On fail dequeue return NULL*/
void* pop(List *list);
/* END: */

/* START: Print all the elements of the list. This function takes two
   arguments, (List *list) which is a pointer to the list and
   (void (*print)(const void *elem) which is a pointer to the
   function that prints an element saved by Qnode.*/
void printList(List *list, void (*print)(const void *elem));
/* END: */

/* START: This function frees all the memory allocated in *list.
   This function takes two arguments (List *list)
   which is a pointer to the list and (void (*print)(void *elem))
   which is a pointer to the function that frees an element
   (void *elem) save by each Qnode*/
void freeList(List *list, void (*freeElem)(void *elem));
/* END: */

#endif
