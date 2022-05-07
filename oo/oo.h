typedef struct object Object;
typedef int (*func_t)(Object *);

struct object {
  int a, b;
  func_t add, sub;
};

int add(Object *);
int sub(Object *);
