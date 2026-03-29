/* File: angkaaneh.c */
#include <stdio.h>

int faktorial(int n){
    int angka = 1;
    for(int i = 0; i <= n; i++){
        angka = angka * i;
    }
    return angka;
}

int cekAngkaAneh(int x){
    int angka;

    int jumlah = 0;
    while(x >0){
        angka = x % 10;
        jumlah = jumlah + faktorial(angka);
        x = x / 10;
    }

    return jumlah;
}

int main(){
    int N;

    for(int i = 0; i <= N; i++){
        int F;
        scanf("%d", &F);

    }
}