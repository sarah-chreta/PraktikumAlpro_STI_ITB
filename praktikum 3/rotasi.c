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
    }

    if(C == 'L'){
        for(int i = 0; i < K; i++){
            for(int i = N - 1; i >= 0; i--){
                printf("%d", A[i]);
            }
        }
    }
    else if(C == 'R'){
        for(int i = 0; i < K; i++){
            for(int i = 0; i < N; i++){
                printf("%d", A[i + 1]);
                printf(" %d", A[i]);
            }
        }
    }

    printf("\n");
    return 0;
}