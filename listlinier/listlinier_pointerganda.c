#include "listlinier_pointerganda.h"
#include <stdlib.h>

void insertFirst(List *l, ElType x){
    Address p;

    p = newNode(x);
    if(p != NIL){
        NEXT(p) = FIRST(*l);
        if(!isEmpty(*l)){
            PREV(FIRST(*l)) = p;
        }
        else{
            LAST(*l) = p;
        }
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType x){
    Address p;

    p = newNode(x);
    if(p != NIL){
        PREV(p) = LAST(*l);
        if(!isEmpty(*l)){
            NEXT(LAST(*l)) = p;
        }
        else{
            FIRST(*l) = p;
        }
        LAST(*l) = p;
    }
}

void deleteFirst(List *l, ElType *x){
    Address p;

    p = FIRST(*l);
    *x = INFO(p);
    if(FIRST(*l) == LAST(*l)){
        LAST(*l) = NIL;
    }
    else{
        PREV(NEXT(FIRST(*l))) = NIL;
    }
    FIRST(*l) = NEXT(FIRST(*l));
    free(p);
}

void deleteLast(List *l, ElType *x){
    Address p;

    p = LAST(*l);
    *x = INFO(p);
    if(FIRST(*l) == LAST(*l)){
        FIRST(*l) = NIL;
    }
    else{
        NEXT(PREV(LAST(*l))) = NIL;
    }
    LAST(*l) = PREV(LAST(*l));
    free(p);
}