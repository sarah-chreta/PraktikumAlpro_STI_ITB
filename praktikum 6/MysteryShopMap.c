/* File: MysteryShopMap.c */

#include "MysteryShopMap.h"
#include <stdio.h>

void CREATE_MAP(MysteryShopMap *M){
    M->count = 0;
}

bool IS_EMPTY(const MysteryShopMap *M){
    return M->count == 0;
}

bool SET_ITEM(MysteryShopMap *M, const char *key, int value){
    // karena yang dibandingkan adalah alamat memory bukan isi teks,
    // maka gabisa if(key 1 == key 2)
    // saat cek membandingkan string

    // strcmp untk membandingkan string
    // string tidak bisa dibandingkan dengan ==

    // 1. cek dulu apakah ada key yang ingin ditambahkan atau dimasukkan value
    for(int i = 0; i < M->count; i++){
        if(strcmp(M->data[i].key, key == 0)){ // karena string sama
            // update stok atau value
            M->data[i].value = value;
            return true;
        }
    }
    
    // nah, sekarang kalo ga ktmu string yang sama,
    // mau tambahin key baru, tp make sure dulu ga penuh slotnya
    if(M->count >= MAX_ITEM){
        return false;
    }


    strcpy(M->data[M->count].key, key);
    M->data[M->count].value = value;
    M->count++;

    return true;
}

bool UNSET_ITEM(MysteryShopMap *M, const char *key){
    int idx = -1;

    for(int i = 0; i < M->count; i++){
        // cari key nya gabisa pake
        // M->data[i] == key
        if(strcmp(M->data[i].key, key) == 0){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        return false;
    }

    // menghapus
    for(int i = 0; i < M->count; i++){
        M->data[i] = M->data[i + 1];
    }
    M->count--;
    return true;
}

bool FIND_ITEM(const MysteryShopMap *M, const char *key, int *value){
    
}