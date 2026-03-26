/* File : sandicipher.c */
#include <stdio.h>

void cariSandi(int x, int y, char A, char B, int N){
    for(int i = 1; i <= N; i++){
        if(i % x == 0){
            printf("%c", A);        // A di input bisa berupa kata apa aja, nanti kalo %c itu bakal ngisi inputan tersebut
        }
        else if(i % y == 0){
            printf("%c", B);
        } 
        else{
            printf("@");
        }
    }
}

int main(){
    int x;
    int y;
    int N;
    char A;
    char B;

    scanf("%d %d %d\n", &x, &y, &N);
    scanf("%c %c", &A, &B);

    cariSandi(x, y, A, B, N);
    printf("\n");

    return 0;
}