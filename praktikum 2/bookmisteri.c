#include <stdio.h>

int hitungDigit(int N){
    int j;
    int jumlah;

    jumlah = 0;
    for(int i = 0; i > 0; i++){
        j = N % 10;
        jumlah = jumlah + j;
        j = j / 10;
    }

    return jumlah;
}

int cariKode(int N){
    int jumlah = hitungDigit(N);

    
}

int main(){
    int n;

    scanf("%d", &n);

    cariKode(n);

    return 0;
}