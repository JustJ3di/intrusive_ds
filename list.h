#ifndef LIST
#define LIST
#include "utils.h"

typedef struct lnode {
    
    struct lnode *next;
    struct lnode *prev;

}LNode;


typedef struct list{
    LNode *tail;
    LNode *head;
}List;


void init_list(List *);

void push_front(List *,LNode *);
void push_back(List *, LNode *);
LNode *pop_back(List *);
LNode *pop_front(List *);
bool erase(List *,LNode *);



#endif