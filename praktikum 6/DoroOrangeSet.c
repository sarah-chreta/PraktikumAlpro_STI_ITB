/* File: DoroOrangeSet.c */

#include "DoroOrangeSet.h"
#include <stdio.h>

void CREATE_SET(DoroOrangeSet *S){
    S->count = 0;
}

bool IS_MEMBER(const DoroOrangeSet *S, int x){
    for(int i = 0; i < S->count; i++){
        if(S->data[i] == x){
            return true;
        }
    }
    return false;
}

bool ADD_ORANGE(DoroOrangeSet *S, int x){
    // menambah elemen yang belum ada, kalo duplikat, gagal
    // kita mau jaga agar urutan elemen tetap urut
    if(S->count >= MAX_ORANGE){
        return false;
    }

    if(IS_MEMBER(S, x)){
        return false;
    }

    int i = S->count - 1;
    while(i >= 0 && S->data[i] > x){
        S->data[i + 1] = S->data[i];
        i--;
        // contoh : 10 20 30 40
        // mau add : 25
        // cek dulu dari 40, akan dipindah ke index i + 1
        // sampe 20 kan udah ga lbh besar dari 25, jadi 20 ga dipindah
    }
    // keluar dari loop, i sekarang berada di yg index ke 20

    S->data[i + 1] = x;
    S->count++;

    return true;
}

bool REMOVE_ORANGE(DoroOrangeSet *S, int x){
    int idx = -1;

    for(int i = 0; i < S->count; i++){
        if(S->data[i] == x){
            idx = i;
            break;
        }
    }
    // nanti nemu tuh x nya dimana setelah break
    // misal : skrg idx nya = 2 karena x di index ke 2

    if(idx == -1){
        return false;
    }

    // mau geser elemen ke kiri dan nimpa elemen x nya
    for(int i = idx; i < S->count; i++){
        S->data[i] = S->data[i + 1];
    }

    S->count--;
    return true;
}

int CARDINALITY(const DoroOrangeSet *S){
    return S->count;
}

int TOTAL_ENERGY(const DoroOrangeSet *S){
    int sum = 0;
    for(int i = 0; i < S->count; i++){
        sum = sum + S->data[i];
    }
    return sum;
}

void PRINT_SET(const DoroOrangeSet *S){
    if(S->count == 0){
        printf("{}\n");
        return;
    }
    else{
        printf("{");
        for(int i = 0; i < S->count; i++){
            printf("%d", S->data[i]);
            if(i < S->count - 1){
                printf(", ");
            }
        }
        printf("}\n");
    }
}