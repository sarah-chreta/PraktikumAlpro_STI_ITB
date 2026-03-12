/* File : Memvalidasi Tiga Sisi Segitiga dan Mengklasifikasikan Jenis Segitiga */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(){
    /* KAMUS */
    double a;       //double bisa sampe ~15 - 16 digit belakang koma
    double b;
    double c;

    /* ALGORITMA */
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
        return 0;   //supaya balik ke user input
    
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a){
        printf("Tidak valid\n");
        return 0;
    }

    //sebuah sisi dianggap "sama" kalo selisih antara kedua sisi < 0.001
    bool ab = fabs(a-b) < 0.001;    //fabsf buat input berbentuk float
    bool bc = fabs(b-c) < 0.001;    //fabst buat input berbentuk double
    bool ac = fabs(a-c) < 0.001;
    bool siku = (fabs(a*a + b*b - c*c) < 0.001) || (fabs(b*b + c*c - a*a) < 0.001) || (fabs(a*a + c*c - b*b) < 0.001);
    // perhatikan tanda kurungnya

    if((ab && bc) || (ab && ac) || (bc && ac)){
        printf("Segitiga Sama Sisi\n");     //masukin yang paling utama dlu (yang berpengaruh ke if lain)
    } else if (siku){
        if(ab || bc || ac){
            printf("Segitiga Siku-Siku Sama Kaki\n");
        } else {
            printf("Segitiga Siku-Siku\n");
        }
    } else if(ab || bc || ac) {
        printf("Segitiga Sama Kaki\n");
    } else {
        printf("Segitiga Sembarang\n");
    }

    return 0;
}