#include "HiddenFace.h"

void CreateFaces(HiddenFaces *f){
    for(int i = 0; i < CAPACITY; i++){
        f->contents[i] = MARK;
    }
}

boolean isEmpty(HiddenFaces f){
    for(int i = 0; i < CAPACITY; i++){
        if(f.contents[i] != MARK){
            return false;
        }
    }
    return true;
}

boolean isFull(HiddenFaces f){
    for(int i = 0; i < CAPACITY; i++){
        if(f.contents[i] == MARK){
            return false;
        }
    }
    return true;
}

int length(HiddenFaces f){
    int jumlah = 0;
    for(int i = 0; i < CAPACITY; i++){
        if(f.contents[i] != MARK){
            jumlah++;
        }
    }
    return jumlah;
}

IdxType getFirstIdx(HiddenFaces f){
    for(int i = 0; i < CAPACITY; i++){
        if(f.contents[i] != MARK){
            return i;
        }
    }
    return IDX_UNDEF;
}

IdxType getLastIdx(HiddenFaces f){
    for(int i = CAPACITY; i > 0; i--){
        if(f.contents[i] != MARK){
            return i;
        }
    }
    return IDX_UNDEF;
}

ElType getElmt(HiddenFaces f, IdxType i){
    return ELMT(f, i);
}

void setElmt(HiddenFaces f, IdxType i, ElType val){
    ELMT(f, i) = val;
}

boolean isIdxValid(HiddenFaces f, IdxType i){
    
}