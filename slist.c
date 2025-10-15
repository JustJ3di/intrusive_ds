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
/*
void slist_revere(){

}
bool search(){

}*/

