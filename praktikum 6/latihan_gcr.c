/* File: latihan_gcr.c */

#include "header_latihan.h"

bool isIn(Set S, int x){
    // ide : mencari, jika sudah nemu berhenti
    // versi terurut -> jadi kalau sudah nemu yg lbh besar
    // dan ternyata blm ada x, maka x tidak ada
    for(int i = 0; i < S.count; i++){
        if(S.data[i] == x){
            return true;
        }
        else if(S.data[i] > x){
            return false;
        }
    }
    return false;
}

bool add(Set *S, ElType x){
    // karena harus terurut maka harus cari posisi yang benar
    // tidak boleh duplikat
    if(S->count == 100){
        return false;
    }

    if(isIn(*S, x) == true){
        return false;
    }

    int i = S->count - 1;
    while(i >= 0 && S->data[i] > x){
        S->data[i + 1] = S->data[i]; 
        i--;
    } // 10, 20, 30, 40, 50

    S->data[i + 1] = x; // 10, 20, ..., 30, 40, 50 --> i nya skrg di 20, brarti x di i + 1
    S->count++;
    return true;
}

bool removeSet(Set *S, ElType x){
    // geser kiri untuk menutup lubang
    
}