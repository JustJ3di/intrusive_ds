#ifndef SLIST
#define SLIST 
#include "utils.h"

typedef struct snode SNode;

struct snode{
    SNode *next;
};


typedef struct slist
{
    SNode *head;
}Slist;

void init_slist(Slist *);
void push_slist(Slist *,SNode *);
SNode *pop_slist(Slist *);
void slist_revere(Slist *);
bool search(Slist *,SNode *);



#endif 