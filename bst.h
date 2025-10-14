#ifndef BST
#define BST
#include "utils.h"

typedef struct tnode BSTnode;

typedef struct bst Bstree;

struct tnode
{
    unsigned int KEY;
    BSTnode *parent;
    BSTnode *left;
    BSTnode *right;
};


struct bst
{
    BSTnode *root;
};

void init_bst(Bstree *);
void bstinsert(Bstree *, BSTnode *);
void bstremove(Bstree *, BSTnode *);
BSTnode *btreemin(BSTnode *);
BSTnode *btreemax(BSTnode *);







#endif