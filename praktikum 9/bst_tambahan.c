#include "bst_tambahan.h"

boolean isInTree(BinTree p, int num){
    if(p == NIL){
        return false;
    }

    if(ROOT(p).key == num){
        return true;
    }
    else if(num < ROOT(p).key){
        // mengecek nilai kiri dulu yang lebih kecil dari akar
        return isInTree(LEFT(p), num);
    }
    else{
        return isInTree(RIGHT(p), num);
    }
}

int nbLeaf(BinTree p){
    if(p == NIL){
        return 0;
    }

    if(LEFT(p) == NIL && RIGHT(p) == NIL){
        return 1;
    }

    return nbLeaf(LEFT(p)) + nbLeaf(RIGHT(p));
    // rekursi terus sampe p = NIL
}

int sumLeaf(BinTree p){
    int sum = 0;

    if(p == NIL){
        return 0;
    }

    if(LEFT(p) == NIL && RIGHT(p) == NIL){
        return ROOT(p).key;
    } // return isi key rootnya karena mau menjumlahkan

    return sumLeaf(LEFT(p)) + sumLeaf(RIGHT(p));
}