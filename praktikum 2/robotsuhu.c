/* File: robotsuhu.c : Konversi Suhu secara acak */
#include <stdio.h>

float konversiSuhu(float suhu, char asal, char tujuan){
    float temperature;

    //ubah ke celcius dulu
    if(asal == tujuan){ // ini kalau tujuannya sama
        return suhu;
    }

    if(asal == 'K'){   // K ke C
        temperature = suhu - 273.15;
    }
    else if(asal == 'F'){   // F ke C
        temperature = (suhu - 32) * 5.0 / 9.0;
    }
    else{   // C = C aja
        temperature = suhu;
    }

    //celcius ke tujuan
    if(tujuan == 'K'){  // C ke K
        temperature = temperature + 273.15;
    }
    else if(tujuan == 'F'){ // C ke F
        temperature = (temperature * 9.0 / 5.0) + 32;
    }

    return temperature;
}

int main(){
    float T;
    char Y;
    int N;

    scanf("%f %c %d", &T, &Y, &N);
    
    for(int i = 0; i < N; i++){
        char cmd;
        scanf(" %c", &cmd);

        if(cmd == 'C' || cmd == 'F' || cmd == 'K'){
            T = konversiSuhu(T, Y, cmd);
            Y = cmd;
            // tulis cmd agar di akhir keluaran ada cmdnya apa
            // hanya khusus buat C, K, F
        }
        else if(cmd == 'A'){
            float x;
            scanf(" %f", &x);
            T = T + x;
        }
        else if(cmd == 'S'){
            float y;
            scanf(" %f", &y);
            T = T - y;      
// harus tetap pakai T agar saat mengulang loop, 
// T nya keubah sesuai cmd yang sudah dilakukan
        }
    }

    printf("%.2f %c\n", T, Y);

    return 0;
}