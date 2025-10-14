#include "bst.h"

static void transplant(Bstree *bst, BSTnode *u, BSTnode *v){

    if(!u->parent)bst->root = v;
    else if(u == u->parent->left)u->parent->left = v;
    else u->parent->right = v;
    if(!v)v->parent = u->parent;

}

static BSTnode *successor(BSTnode *x){

    if(x->right)
        return btreemin(x->right);
    BSTnode *y = x->parent;
    while (y && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
    
}

static BSTnode *predecessor(BSTnode *x){

    if(x->left)
        return btreemax(x->left);
    BSTnode *y = x->parent;
    while(y && x == y->left){
        x = y;
        y = y->parent;
    }
    return y;
}

static void shiftnode(Bstree *T, BSTnode *u, BSTnode *v){

    if (!u->parent)
        T->root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else if(u==u->parent->right)
        u->parent->right = v;
    if(v)
        v->parent = u->parent;
}

void init_bst(Bstree *bst){

    bst->root = NULL;

}

BSTnode *btreemin(BSTnode *x){
    while (!x->left)
        x = x->left;
    return x;
}

BSTnode *btreemax(BSTnode *x){
    while(!x->right)
        x = x->right;
    return x;
}

void bstinsert(Bstree *bst, BSTnode *new){
    //case 0: no node in the root.
    BSTnode *curr = bst->root;
    BSTnode *pred = NULL;
    while (curr)
    {
        pred = curr;
        if(new->KEY <= curr->KEY) curr = curr->left;
        else curr = curr->right;
    }
    new->parent = pred;
    if(!pred)bst->root = new;
    else if(new->KEY <= pred->KEY)pred->left = new;
    else pred->right = new;

}

void bstremove(Bstree *T, BSTnode *z){

    if (!z->left)transplant(T, z , z->right);
    else if(!z->right)transplant(T, z, z->left);
    else{
        BSTnode *y = btreemin(z->right);
        if (y->parent != z)
            shiftnode(T,y,y->right);
            y->right = z->right;
            y->right->parent = y;
        shiftnode(T,z,y);
        y->left = z->left;
        y->left->parent = y;  
    }
    
}

bool search(Bstree *T, BSTnode *node){

    BSTnode *x = T->root;
    while(x && node->KEY != x->KEY){
        if (node->KEY < x->KEY)
            x = x->left;
        else if(node->KEY > x->KEY)
            x = x->right;
        else
            return true;
    }

    return false;
}
