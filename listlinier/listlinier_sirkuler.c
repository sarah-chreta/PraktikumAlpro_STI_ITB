#include "listlinier_sirkuler.h"
#include <stdlib.h>

boolean addrSearch(List l, Address p){
    Address point;

    if(isEmpty(l)){
        return false;
    }
    else{
        point = FIRST(l);
        while(NEXT(point) != FIRST(l) && point != p){
            point = NEXT(point);
        }
        return point == p;
    }
}

void insertFirst(List *l, ElType x){
    Address p, prev;

    p = newNode(x);
    if(p != NIL){
        if(isEmpty(*l)){
            NEXT(p) = p;
        }
        else{
            prev = FIRST(*l);
            while(NEXT(prev) != FIRST(*l)){
                prev = NEXT(prev);
            }
            NEXT(p) = FIRST(*l);
            NEXT(prev) = p;
        }
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
            while(NEXT(prev) != FIRST(*l)){
                prev = NEXT(prev);
            }
            NEXT(prev) = p;
            NEXT(p) = FIRST(*l);
        }
    }
}

void deleteFirst(List *l, ElType *x){
    Address p, prev;

    p = FIRST(*l);
    *x = INFO(p);
    if(NEXT(FIRST(*l)) == FIRST(*l)){
        FIRST(*l) = NIL;
    }
    else{
        // kalo ada lebih daru 1 elemen
        prev = FIRST(*l); // karena tidak ada LAST(*l)
        while(NEXT(prev) != FIRST(*l)){
            prev = NEXT(prev);
        }
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(prev) = FIRST(*l);
    }
    free(p);
}

void deleteLast(List *l, ElType *x){
    Address p, loc;

    p = FIRST(*l);
    loc = NIL;
    while(NEXT(p) != FIRST(*l)){
        loc = p;
        p = NEXT(p);
    }
    if(loc == NIL){
        FIRST(*l) = NIL;
    }
    else{
        NEXT(loc) = FIRST(*l);
    }
    *x = INFO(p);
    free(p);
}

void displayList(List l){
    Address p;

    if(isEmpty(l)){
        printf("List kosong \n");
    }
    else{
        p = FIRST(l);
        printf("List: \n");
        do{
            printf("%d \n", INFO(p));
        } while(p != FIRST(l));
        // ga pake while do karena jika pake while do, nanti pas
        // pengecekan elemen pertama, langsung salah karena
        // jika elemen pertama 10, trus di cek dulu sama FIRST,
        // ternyata 10 = 10, langsung salah, jadi ga di print
        // jadinya ga print samsek
        // sedangkan kalo do while, dia bakal do print dulu
        // baru cek , jadi, elemen pertama (misal : 10), bakal ke print dulu
        // baru cek
    }
}