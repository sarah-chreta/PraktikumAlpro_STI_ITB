/* File: med.c : Menambahkan sebuah bilangan ke dalam barisan jika memang ada bilangan tersebut dalam barisannya */
#include <stdio.h>

int main(){
    int N;
    int X;

    scanf("%d %d", &N, &X);
    int A[N];

    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    int found;
    found = 0;
    for(int i = 0; i < N; i++){
        if(X == A[i]){
            found = 1;
            // tanda bahwa sudah ditemukan '1'
        }
    }

    if(found){
        printf("%d", X);
        for(int i = 0; i < N; i++){
            printf(" %d", A[i]);
        }
    }
    else{
        for(int i = 0; i < N; i++){
            printf("%d", A[i]);
        }
    }

    printf("\n");
    return 0;
}

