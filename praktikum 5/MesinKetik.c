#include "MesinKetik.h"

void CreateList(ListKetik *L){
    L->nEff = 0;
    L->cursor = 0; // cursor : orang lagi mau ngetik dimana
}

int length(ListKetik L){
    return L.nEff;
}

void typeChar(ListKetik *L, ElType x){
    if(L->nEff == CAPACITY)
        return;
    for(int i = L->nEff; i > L->cursor; i--){ // i : posisi index ke berapa
        // mulai dari nEff karena index yang awalnya terpakai : 0 1 2 3, cuman sampai nEff - 1
        L->contents[i] = L->contents[i - 1];
    }
    L->contents[L->cursor] = x;
    L->nEff++;
    L->cursor++;
    // awalnya : A|BCD -> | sebagai cursor
    // trus : AX|BCD 
    // tapi krn blm mengindikasikan bahwa cursor telah berpindah mknya ++
}

void backspace(ListKetik *L){
    if(L->cursor == 0) return;

    for(int i = L->cursor - 1; i < L->nEff - 1; i++){
        // bukan sampai i <= L->neff karena berarti menjalankan i <= 3, dimana saat content[3] = content[4] gaada
        L->contents[i] = L->contents[i+1];
    }
    L->nEff--;
    L->cursor--;
}

void deleteAll(ListKetik *L, ElType x){
    int write = 0;
    int newcursor = L->cursor;

    for(int read = 0; read < L->nEff; read++){
        if(L->contents[read] == x){ 
        // jadi kalo nemu x, nanti bakal diabaikan oleh program dan tidak masuk di write
        // jadi nanti x tidak ikut disalin
            if(L->contents[read] == x){
                newcursor--;
            }
        }
        else{
            L->contents[write] = L->contents[read];
            // karena tidak nemu x, makanya disalin di write
            write++;
        }
    }

    L->nEff = write;
    if(newcursor < 0) newcursor = 0;
    if(newcursor > L->nEff) newcursor = L->nEff;
    L->cursor = newcursor;
}

void cursorLeft(ListKetik *L){
    if(L->cursor > 0){
        L->cursor--;
    }
}
// contoh pemanggilan :
// L.cursor = 2
// cursorLeft(&L) --> nanti akan kegeser ke cursor = 1

void cursorRight(ListKetik *L){

}



