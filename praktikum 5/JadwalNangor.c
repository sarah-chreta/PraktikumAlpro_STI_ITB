#include "JadwalNangor.h"

void CreateList(ListEkspedisi *L){
    L->nEff = 0;
}

int length(ListEkspedisi L){
    return L.nEff;
}

void insertFirst(ListEkspedisi *L, ElType x){
    for(int i = L->nEff; i > 0; i--){
        L->contents[i] = L->contents[i - 1];
    }
    L->contents[0] = x;
    L->nEff++;
}

void insertLast(ListEkspedisi *L, ElType x){
    L->contents[L->nEff] = x;
    L->nEff++;
}

void deleteFirst(ListEkspedisi *L, ElType *e){
    *e = L->contents[0];

    for(int i = 0; i < L->nEff - 1; i++){
        L->contents[i] = L->contents[i+1];
    }
    L->nEff--;
}

void deleteLast(ListEkspedisi *L, ElType *e){
    *e = L->contents[L->nEff];
    L->nEff--;
}

int TotalJarak(ListEkspedisi L){
    if(L.nEff == 0) return 0;

    int jumlah = 0;
    for(int i = 0; i < L.nEff; i++){
        jumlah = jumlah + L.contents[i];
    }

    return jumlah;
}

void printList(ListEkspedisi L){
    if(L.nEff == 0){
        printf("[]\n");
        return;
    }

    printf("[");
    for(int i = 0; i < L.nEff; i++){
        printf("%d", L.contents[i]);
        if(i != L.nEff - 1){
            printf(", ");
        }
    }
    printf("]\n");
}