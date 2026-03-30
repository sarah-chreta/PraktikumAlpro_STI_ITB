/* File: Menjumlahkan List Bilangan dari Minimum Setiap Bilangan pada Barisan */
#include <stdio.h>

int main(){
    int N;
    int jumlah;
    jumlah = 0;
    scanf("%d", &N);

    int A[N];

    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(A[i] < A[j]){
                jumlah = jumlah + A[i];
            }
            else{
                jumlah = jumlah + A[j];
            }
        }
    }

    printf("%d\n", jumlah);
    return 0;
}