/* File: hard.c */
#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    int Q;
    scanf("%d", &Q);

    int start = 0;

    for(int i = 0; i < Q; i++){
        char C;
        long long K;
        scanf(" %c %lld", &C, &K);

        K = K % N;

        if(C == 'L'){
            start = (start + K) % N;
        } else if(C == 'R'){
            start = (start - K + N) % N;
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d", A[(start + i) % N]);
        if(i != N - 1) printf(" ");
    }

    printf("\n");
    return 0;
}