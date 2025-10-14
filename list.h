#ifndef LIST
#define LIST
#include <stdarg.h>

#define  NULL ((void *)0)

typedef enum{false ,true}bool;

typedef struct node {
    
    struct node *next;
    struct node *prev;

}Node;


typedef struct list{
    Node *tail;
    Node *head;
}List;


void init_list(List *);

void push_front(List *,Node *);
void push_back(List *, Node *);
void insert_before(List *, Node *,Node *);
void insert_after(List *, Node *, Node *);
Node *pop_back(List *);
Node *pop_front(List *);
bool erase(List *,Node *);



#endif