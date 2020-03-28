#include "objeto.h"

//Don't forget to define how to create your object
obj *newObject(int id)
{
  obj *new = (obj*)malloc(sizeof(obj));

  if ( new==NULL )
    errorMessageMem("newObject");

  new->id = id;
  
  return new;
}

/*Don't forget to define how to compare your object
  Return types:
  0  -> Means a==b
  >0 -> Means a>b
  <0 -> Means a<b */
int compare(obj *a, obj *b)
{
  return a->id - b->id;
}

/*Don't forget to define how to print your object */
void printObject(obj *a)
{
  printf("Value %d\n\n", a->id);
}

/* Error message, shall be left unchanged*/
void errorMessageMem(char *str)
{
  fprintf(stderr, "Memory allocation failed in %s\n", str);
  exit(EXIT_FAILURE);
}
