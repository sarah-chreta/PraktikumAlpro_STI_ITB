#include "inverseBST.h"

void inverseTree(BinTree *p){
    if(*p != NIL){
        Address temp = LEFT(*p);
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = temp;
    }

    inverseTree(&LEFT(*p));
    inverseTree(&RIGHT(*p));
}