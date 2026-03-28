#include <stdio.h>

int hitungDigit(int N){
    int j;
    int jumlah;

    jumlah = 0;
    while(N > 0){
        j = N % 10;
        jumlah = jumlah + j;
        N = N / 10;
    }

    return jumlah;
} // 615 --> 12

int hitungJumlahDigit(int N){
    int count;

    count = 0;
    while(N > 0){
        count++;
        N = N / 10;
    }

    return count;
} // 615 --> 3

int cariKode(int N){
    int jumlah = hitungDigit(N);

    int hasillangkah = jumlah;
    for(int i = 0; i < hitungJumlahDigit(N); i++){
        hasillangkah = hasillangkah * 10;
    }

    hasillangkah = hasillangkah + N;

    int hasillangkah2 = hitungJumlahDigit(hasillangkah);

    int finish = hasillangkah2;

    for(int j = 0; j < hitungJumlahDigit(hasillangkah); j++){
        finish = finish * 10;
    }

    finish = finish + hasillangkah;

    return finish;
}

int main(){
    int n;

    scanf("%d", &n);
    printf("%d\n", cariKode(n));

    return 0;
}