#include "list.h"

/*================LOCAL FUNCTIONS DECLARATION================*/
/* Allocates new memory for a Qnode and returns its pointer,
   On fail returns NULL*/
static Qnode* allocQnode(void *elem);
/* END: */

/* Return the pointer of type Qnode for the first Qnode
   in the list. On fail return NULL*/
static Qnode* topQnode(List *list);
/* END: */


/*================IMPLEMENTATION================*/
List* allocList()
{
  List *list = (List*)calloc(1, sizeof(List));

  if ( list == NULL )
    perror("allocList");

  list->size = 0;

  list->head = allocQnode(NULL);
  list->tail = allocQnode(NULL);

  list->head->next = list->tail;
  list->tail->prev = list->head;

  return list;
}

static Qnode* allocQnode(void *elem)
{
  Qnode *node = (Qnode*)calloc(1, sizeof(Qnode));

  if ( node == NULL )
    perror("allocQnode");

  node->elem = elem;

  return node;
}

static Qnode* topQnode(List *list)
{
  if ( !list->size )
    return NULL;

  return list->head->next;
}

void* top(List *list)
{
  Qnode *node = topQnode(list);

  return node == NULL ? NULL: node->elem;
}

int listIsEmpty(List *list)
{
  return list == NULL ? 0: list->size > 0;
}

void* push(List *list, void *elem)
{
  if ( list == NULL )
    return NULL;

  Qnode *node = allocQnode(elem);

  if ( node == NULL )
    return NULL;

  node->next = list->head->next;
  node->prev = list->head;

  list->head->next->prev = node;
  list->head->next = node;

  list->size++;

  return elem;
}

void* enqueue(List *list, void *elem)
{
  if ( list == NULL )
    return NULL;

  Qnode *node = allocQnode(elem);

  if ( node == NULL )
    return NULL;

  node->next = list->tail;
  node->prev = list->tail->prev;

  list->tail->prev->next = node;
  list->tail->prev = node;

  list->size++;

  return elem;
}

void* dequeue(List *list)
{
  if ( list == NULL || list->size == 0 )
    return NULL;

  void *elem = top(list);
  Qnode *first = topQnode(list);

  list->head->next = first->next;
  first->next->prev = list->head;

  list->size--;

  free(first);

  return elem;
}

void* pop(List *list) { return dequeue(list); }

void printList(List *list, void (*print)(const void *elem))
{
  if ( list == NULL )
    return;

  printf("Start of List Print. Size = %d\n", list->size);

  int i = 0;

  for( Qnode *cur = list->head->next; cur != list->tail; cur = cur->next )
    {
      printf("Index = %d\n", i++);

      print(cur->elem);
    }

  printf("End of List Print\n");
}

void freeList(List *list, void (*freeElem)(void *elem))
{
  if ( list == NULL )
    return;

  while ( list->size )
    freeElem(dequeue(list));

  free(list->head);
  free(list->tail);

  free(list);
}
