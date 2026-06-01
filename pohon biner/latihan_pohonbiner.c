#include "latihan_pohonbiner.h"
#include <stdlib.h>

Address newNode(ElType x){
    Address p = (Address) malloc (sizeof(TreeNode));

    if(p != NIL){
        INFO(p) = x;
        LEFT(p) = NIL;
        RIGHT(p) = NIL;
    }
    return p;
}

void CreateTree(BinTree *P, ElType x){
    *P = newNode(x);
}

boolean isEmpty(BinTree P){
    return (P == NIL);
}

boolean isOneElmt(BinTree P){
    
}
