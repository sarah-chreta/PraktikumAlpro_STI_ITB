/* File: angkaaneh.c */
#include <stdio.h>

int faktorial(int n){
    int angka = 1;
    for(int i = 1; i <= n; i++){
        angka = angka * i;
    }
    return angka;
}

int cekAngkaAneh(int x){
    int angka;
    int asli = x;

    int jumlah = 0;
    while(x >0){
        angka = x % 10;
        jumlah = jumlah + faktorial(angka);
        x = x / 10;
    }

    if(jumlah == asli){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int F;
        scanf("%d", &F);

        if(cekAngkaAneh(F)){
            printf("BAHAYA\n");
        }
        else{
            printf("AMAN\n");
        }
    }

    return 0;
}