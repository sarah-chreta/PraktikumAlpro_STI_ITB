#include "latihan_pohonbiner.h"
#include <stdlib.h>
#include "boolean.h"

Address newNode(ElType x){
    Address p = (Address) malloc (sizeof(TreeNode));

    if(p != NIL){
        INFO(p) = x;
        LEFT(p) = NIL;
        RIGHT(p) = NIL;
    }
    return p;
}

void CreateTree(BinTree *P, ElType x){
    *P = newNode(x);
}

boolean isEmpty(BinTree P){
    return (P == NIL);
}

boolean isOneElmt(BinTree P){
    return (P != NIL && LEFT(P) == NIL && RIGHT(P) == NIL);
}

boolean isLeaf(BinTree P){
    return (isOneElmt(P));
}

boolean isUnerLeft(BinTree P){
    return (P != NIL && LEFT(P) != NIL && RIGHT(P) == NIL);
}

boolean isUnerRight(BinTree P){
    return (P != NIL && RIGHT(P) != NIL && LEFT(P) == NIL);
}

boolean isBiner(BinTree P){
    return (P != NIL && LEFT(P) != NIL && RIGHT(P) != NIL);
}

void preOrder(BinTree P){
    if(P != NIL){
        printf("%d ", INFO(P));
        preOrder(LEFT(P));
        preOrder(RIGHT(P));
    }
} // akar, kiri, kanan

void inOrder(BinTree P){
    if(P != NIL){
        inOrder(LEFT(P));
        printf("%d ", INFO(P));
        inOrder(RIGHT(P));
    }
} // kiri, akar, kanan

void postOrder(BinTree P){
    if(P != NIL){
        postOrder(LEFT(P));
        postOrder(RIGHT(P));
        printf("%d ", INF(P));
    }
}

boolean search(BinTree P, ElType X){
    if(P == NIL){
        return false;
    }

    if (INFO(P) == X){
        return true;
    }
    
    return search(LEFT(P), X) || search(RIGHT(P), X);
}

boolean isSkewLeft(BinTree P){
    if(P == NIL){
        return true;
    }

    if(RIGHT(P) != NIL){
        return false;
    }

    return isSkewLeft(LEFT(P));
}

boolean isSkewRight(BinTree P){
    if(P == NIL){
        return true;
    }

    if(RIGHT(P) != NIL){
        return false;
    }

    return isSkewRight(RIGHT(P));
}

int levelRec(BinTree P, ElType X, int lvl){
    if(P == NIL){
        return false;
    }

    if(INFO(P) == X){
        return lvl;
    }

    int kiri = levelRec(LEFT(P), X, lvl + 1);

    if(kiri != 0){
        return kiri;
    }

    return levelRec(RIGHT(P), X, lvl + 1);
    // untuk pencairan biasa memang kiri dulu
}
// jadi kalau dipanggil kek untuk menjawab kalo dipanggil
// saya sekarang berada di level berapa
// contoh : levelRec(root, 3, 1) --> jadi root lagi di level 1

int level(BinTree P, ElType X){
    // butuh helper
    return levelRec(P, X, 1);
}

boolean addDaunRec(BinTree *P, ElType X, ElType Y, boolean Kiri){
    // sebagai mesin belakang
    if(*P == NIL){
        return false;
    }

    if(INFO(*P) == X && LEFT(*P) == NIL && RIGHT(*P) == NIL){
        Address baru = newNode(Y);

        if(Kiri){ // if true
            LEFT(*P) = baru;
        }
        else{ // if false
            RIGHT(*P) = baru;
        }
        return true;
    }

    // cari yang left dulu kalo root != X
    if(addDaunRec(&LEFT(*P), X, Y, Kiri)){
        return true;
    }

    return addDaunRec(&RIGHT(*P), X, Y, Kiri);
}

void addDaun(BinTree *P, ElType X, ElType Y, boolean Kiri){
    // butuh helper boolean supaya tinggal true false
    return addDaunRec(P, X, Y, Kiri);
}

void delDaun(BinTree *P, ElType X){
    if(*P == NIL){
        return;
    }

    delDaun(&LEFT(*P), X);
    delDaun(&RIGHT(*P), X);
    // jadi rekursi mulu sampe nemu info(p) == x, baik itu akar, kiri, atau kanan

    if(LEFT(*P) == NIL && RIGHT(*P) == NIL && INFO(*P) == X){
        free(*P);
        *P = NIL;
    } // trus kalo udah nemu x, baru free
}

