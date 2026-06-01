#include "listlinierdummy.h"
#include <stdlib.h> // untuk strcpy, NULL

boolean isEmpty(List l){
    return (FIRST(l) == LAST(l));
}

void CreateList(List *l){
    Address Dummy;

    Dummy = newNode(0);
    if(Dummy != NIL){
        FIRST(*l) = Dummy;
        LAST(*l) = Dummy;
    }
    else{ // list gagal terbentuk
        FIRST(*l) = NIL;
        LAST(*l) = NIL;
    }
}

int indexOf(List l, ElType x){
    Address p;
    int idx = 0;

    p = INFO(FIRST(l));

    while(INFO(p) != x){
        p = NEXT(p);
        idx++;
    }

    if(p != LAST(l)){
        return idx;
    }
    else{
        return IDX_UNDEF;
    }
}

void insertFirst(List *l, ElType x){
    Address p;
    p = newNode(x);

    if(p != NIL){
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType x){
    Address p, prev;

    if(isEmpty(*l)){
        insertFirst(l, x);
    }
    else{
        p = newNode(x);
        if(p != NIL){
            prev = FIRST(*l);
            while(NEXT(prev) != LAST(*l)){
                prev = NEXT(prev);
            }
            NEXT(prev) = p;
            NEXT(p) = LAST(*l);
        }
    }
}

void deleteFirst(List *l, ElType *x){
    Address p;

    p = FIRST(*l);
    *x = INFO(p);
    FIRST(*l) = NEXT(FIRST(*l));
    free(p);
}

void deleteLast(List *l, ElType *x){
    Address p, loc;

    p = FIRST(*l);
    loc = NIL;

    while(NEXT(p) != LAST(*l)){
        loc = p;
        p = NEXT(p);
    }

    if(loc == NIL){
        FIRST(*l) == LAST(*l);
    }
    else{
        NEXT(loc) = LAST(*l);
    }
    *x = INFO(p);
    free(p);
}

