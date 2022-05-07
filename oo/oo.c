#include <stdio.h>
#include <stdlib.h>

#include "oo.h"

static int add_impl(Object *obj)
{
    return obj->a + obj->b;
}

static int sub_impl(Object *obj)
{
    return obj->a - obj->b;
}

int init_object(Object **self)
{
    *self = malloc(sizeof(Object));
    if (*self == NULL) {
        printf("fail to allocate memory\n");
        return -1;
    }

    (*self)->a = 0;
    (*self)->b = 0;
    (*self)->add = add_impl;
    (*self)->sub = sub_impl;
    return 0;
}

int release_object(Object **self)
{
    free(*self);
    printf("release allocate memory\n");
    return 0;
}

int main(int argc, char *argv[])
{
  Object *obj = NULL;
  init_object(&obj);

  obj->a = 456; obj->b= 123;
  printf("add = %d, sub = %d\n", obj->add(obj), obj->sub(obj));
  release_object(&obj);

  return 0;
}
