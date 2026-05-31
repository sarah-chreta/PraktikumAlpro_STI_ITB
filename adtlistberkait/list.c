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
    Address p = newNode(val);

    if(p != NULL){
        NEXT(p) = *l;
        *l = p;
    }
}

void insertAt(List *l, ElType val, int idx){
    if(idx == 0){
        insertFirst(l, val);
    }
    else{
        Address p = newNode(val);

        if(p != NULL){
            Address loc = *l;
            int count = 0;
            
            while(count < idx - 1){
                count++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

void insertLast(List *l, ElType val){
    if(isEmpty(*l)){
        insertFirst(l, val);
    }
    else{
        Address p = newNode(val);

        if(p != NULL){
            Address last = *l;
            while(NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Address p = *l;

    *val = INFO(p);
    *l = NEXT(p);

    dealokasi(p);
}

void deleteAt(List *l, int idx, ElType *val){
    if(idx == 0){
        deleteFirst(l, val);
    }
    else{
        Address loc = *l;
        int count = 0;

        while(count < idx - 1){
            count++;
            loc = NEXT(loc);
        }

        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        dealokasi(p);
    }
}

void deleteLast(List *l, ElType *val){
    Address p = *l;
    Address loc = NULL;

    while(NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }

    // kalo udah nemu p.next = NULL :
    if(loc = NULL){
        *l = NULL;
    }
    else{
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    dealokasi(p);
}

List concat(List l1, List l2){
    // menggabungkan dua buah list
    // l2 ditaruh di belakang l1
    List l3;
    CreateList(&l3);

    Address p = l1;

    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    p = l2;

    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}