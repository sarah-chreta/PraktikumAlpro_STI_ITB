/* File: rotasi.c */
#include <stdio.h>

int main(){
    int N;
    char C;
    int K;
    scanf("%d", &N);

    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    int Q;
    scanf("%d", &Q);

    for(int j = 0; j < Q; j++){
        scanf(" %c %d", &C, &K);
        for(int t = 0; t < K; t++){
            if(C == 'L'){
                int temp = A[0];
                for(int i = 0; i < N - 1; i++){
                    A[i] = A[i + 1];
                }
                A[N - 1] = temp;
            }
            else if(C == 'R'){
                int temp = A[N - 1];
                for(int i = N - 1; i >= 0; i--){
                    A[i] = A[i - 1];
                }
                A[0] = temp;
            }
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d", A[i]);
        if(i != N - 1){
            printf(" ");
        }
    }

    return 0;
}