#include "list.h"


void init_list(List *list){

    list->head =NULL;
    list->tail = NULL;

}


void push_back(List *list, Node *new){
    if(!erase(list, new)){
        if(list->tail){
            list->tail->next = new;
            new->next = NULL;
            new->prev = list->tail;
            list->tail = new;
        }else{
            list->tail = new;
            list->head = new;
            new->next = NULL;
            new->prev = NULL;
        }
    }
}

void push_front(List *list, Node *new){

    if(!erase(list,new)){
        if(list->head){
            list->head->prev = new;
            new->prev = NULL;
            new->next = list->head;
            list->head = new;

        }else{
            list->head = new;
            list->tail = new;
            new->next = NULL;
            new->prev = NULL;
        }
    }
}

Node *pop_back(List *list){

    //No node
    if(!list->tail)
        return NULL;

    Node *pop=list->tail;
    list->tail = pop->prev;
    //2 ore more node
    if(list->tail){
         list->tail->next = NULL;
    }//one node
    else{
        list->head = NULL;
    }
    //clean node
    pop->next = pop->prev = NULL;
    return pop;
}

Node *pop_front(List *list){

    //No node
    if(!list->head)
        return NULL;

    Node *pop=list->head;
    list->head = pop->next;
    //More node
    if(list->head){
        list->head->prev = NULL;
    }//One node
    else{
        list->tail = NULL;
    }
    //clean node
    pop->next = pop->prev = NULL;
    return pop;
}

//if node is in the list return true; else return false;
bool erase(List *list, Node *node){

    if(!node)
        return false;
    if(node->next)
        node->next->prev = node->prev;
    if(node->prev)
        node->prev->next = node->next;
    if(list->head == node)
        list->head = list->head->next;
    if(list->tail == node)
        list->tail = list->tail->prev;
    
    node->next = node->prev = NULL;

    return true;

}


void insert_before(List *list, Node *before,Node *node){

    before->prev = node;
    node->next = before;


}
void insert_after(List *list, Node *after, Node *node){

}
