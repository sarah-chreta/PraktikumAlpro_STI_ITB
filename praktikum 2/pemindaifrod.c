/* File : pemindaifrod.c */
#include <stdio.h>

int isPrime(int p){
    int i;
    if(p < 2)
        return 0;

    for(i = 2; i * i <= p; i++){
        if(p % i == 0){
            return 0;
        }
    }

    return 1;
}

int main(){
    long long P;
    int D;
    int jumlah;

    scanf("%lld %d", &P, &D);
    jumlah = 0;
    for(long long i = P - D; i <= P + D; i++){
        if(isPrime(i)){
            jumlah++;
        }
    }

    printf("%d\n", jumlah);
    return 0;
}