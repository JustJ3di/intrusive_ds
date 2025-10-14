#ifndef  UTILS
#define UTILS

#define  NULL ((void *)0)

#define offsetof(TYPE, MEMBER) ((unsigned long) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({ \
    (type *)( (char *)(ptr) - offsetof(type, member) ); \
}

typedef enum{false ,true}bool;



#endif