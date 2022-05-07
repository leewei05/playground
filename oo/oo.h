/**
 * \file oo.h
 */

typedef struct object Object;    //!< Object type

/**
 * Function pointer
 * @param obj a pointer to Object
 * @return an integer value.
 */
typedef int (*func_t)(Object * obj);

/**
 * A struct named object
 */
struct object {
  int a;            //!< int a
  int b;            //!< int b
  func_t add, sub;  //!< func
};


/**
 * adding member a and member b and returning an integer value.
 * @param obj is a pointer to Object.
 * @return The result
 */
int add(Object * obj);

/**
 * subtracting member a and member b and returning an integer value.
 * @param obj is a pointer to Object.
 * @return The result
 */
int sub(Object * obj);
