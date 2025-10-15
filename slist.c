#include "slist.h"

void init_slist(Slist *list){

    list->head = NULL;

}

void push_slist(Slist *list, SNode *x){

    if(list->head){
        x->next = list->head;
        list->head = x;
    }else{
        list->head = x;
        x->next = NULL;
    }

}

SNode *pop_slist(Slist *list){

    SNode *temp = list->head;
    list->head  = list->head->next;
    temp->next = NULL;//clean node
    return temp;

}

void slist_reverse(Slist *list){

    SNode *p = NULL, *c = list->head,*n;
    while(c)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    list->head = p;
}

bool search(Slist *list,SNode *y){
    
    SNode *x = list->head;
    while (x)
    {
        if(x==y)return true;
        x = x->next;
    }
    return false;
    
}

