/* File: ee */
#include <stdio.h>

int main (){
    /* KAMUS */
    /* Variabel */
    int Y;

    /* ALGORITMA */
    do
    {
       scanf("%d", &Y);
       if (Y <= 0){
        printf("Masukkan tidak valid\n");
    }
    } while (Y <= 0);

    if(Y % 400 != 0 && Y % 100 != 0 & Y % 4 == 0){
        printf("Kabisat\n");
    }

    if(Y % 4 != 0){
        printf("Bukan Kabisat\n");
    }

    if(Y % 400 == 0){
        printf("Kabisat\n");
    }

    if(Y % 400 != 0 && Y % 100 == 0){
        printf("Bukan Kabisat\n");
    }

    return 0;
}
