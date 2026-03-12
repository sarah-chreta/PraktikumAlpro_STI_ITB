/* File : Mencetak Setiap Nilai dalam Barisan, Mencetak Jumlah Langkah, Mencetak Nilai Maksimum */
#include <stdio.h>

int main(){
    /* KAMUS */
    long long input;
    int langkah;
    int max;

    /* ALGORITMA */
    scanf("%lld", &input);
    
    langkah = 0;
    max = 1;

    while(input != 1){
        printf("%lld\n", input);
        if(input % 2 == 0){
            input = input / 2;
            langkah++;
        } else {
            input = (3 * input) + 1;
            langkah++;
        }
        if(input > max){
            max = input;
        }
    }

    printf("1\n");
    printf("Langkah: %d\n", langkah);
    printf("Nilai maksimum: %d\n", max);

    return 0;
}