#include "list.h"

Address newNode(ElType val){
    Address p = (Address) malloc(sizeof(Node));

    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void dealokasi(Address p){
    free(p);
}

void CreateList(List *l){
    *l = NULL;
}

bool isEmpty(List l){
    return l == NULL;
}

int indexOf(List l, ElType val){
    int idx = 0;
    Address p = l;

    while(p != NULL){
        if(INFO(p) == val){
            return idx;
        }
        idx++;
        p = NEXT(p);
    }
    return IDX_UNDEF;
}

int length(List l){
    int count = 0;
    Address p = l;

    while(p != NULL){
        count++;
        p = NEXT(p);
    }
    return count;
}

ElType getElmt(List l, int idx){
    // ambil elemen l, pada index sekian
    int count = 0;
    Address p = l;

    // ga pake traversal, sekalinya udah nemu, langsung stop
    while(p != NULL){
        if(count < idx){
            count++;
            p = NEXT(p);
        }
    }
    return INFO(p);
}

void setElmt(List l, int idx, ElType val){
    int count = 0;
    Address p = l;

    while(p != NULL){
        if(count < idx){
            count++;
            p = NEXT(p);
        }
    }

    INFO(p) = val;
}

void insertFirst(List *l, ElType val){
    
}