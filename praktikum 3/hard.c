/* File: hard.c */
#include <stdio.h>

int digitCount(int x){
    if(x == 0) return 1;
    int count = 0;
    while (x != 0){
        count++;
        x = x / 10;
    }
    return count;
}

int main(){
    int N;
    scanf("%d", &N);

    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    return 0;
}