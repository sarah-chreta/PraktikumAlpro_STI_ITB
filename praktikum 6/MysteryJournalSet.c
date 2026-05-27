/* File: MysteryJournalSet.c */

#include "MysteryJournalSet.h"

void CREATE_SET(MysteryJournalSet *S){
    S->count = 0;
}

bool IS_EMPTY(const MysteryJournalSet *S){
    return S->count == 0;
}

bool IS_MEMBER(const MysteryJournalSet *S, int x){
    for(int i = 0; i < S->count; i++){
        if(S->data[i] == x){
            return true;
        }
    }
    return false;
}
bool INSERT_PAGE(MysteryJournalSet *S, int x){
    if(S->count >= MAX_PAGE){
        return false;
    }

    if(IS_MEMBER(S, x)){ // gaperlu &S karena parameter di insert page sudah *
        return false;
    }
    
    S->data[S->count] = x; // input x di satu data setelah data terakhir
    S->count++;
    return true;
}

bool DELETE_PAGE(MysteryJournalSet *S, int x){
    int idx = -1;

    for(int i = 0; i < S->count; i++){
        if(S->data[i] == x){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        return false;
    }

    for(int i = idx; i < S->count - 1; i++){
        S->data[i] = S->data[i + 1];
    }
    S->count--;
    return true;
}

int CARDINALITY(const MysteryJournalSet *S){
    return S->count;
}

MysteryJournalSet UNION_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2){
    MysteryJournalSet S3;
    S3.count = 0; // == CREATE_SET(&S3)

    for(int i = 0; i < S1->count; i++){
        INSERT_PAGE(&S3, S1->data[i]);
    }

    for(int i = 0; i < S2->count; i++){
        INSERT_PAGE(&S3, S2->data[i]);
    }

    return S3;
}

MysteryJournalSet INTERSECTION_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2){
    MysteryJournalSet S3;
    CREATE_SET(&S3);

    for(int i = 0; i < S1->count; i++){ // kalau yang di cek di i loop itu S1, maka yang di cek tuh data S1
        if(IS_MEMBER(S2, S1->data[i])){
            INSERT_PAGE(&S3, S1->data[i]);
        }
    }
    return S3;
}

MysteryJournalSet DIFFERENCE_SET(const MysteryJournalSet *S1, const MysteryJournalSet *S2){
    MysteryJournalSet S3;
    CREATE_SET(&S3);

    for(int i = 0; i < S1->count; i++){
        if(!IS_MEMBER(S2, S1->data[i])){
            INSERT_PAGE(&S3, S1->data[i]);
        }
    }
    return S3;
}

void swap(int *a, int *b){ // butuh pointer agar mengubah variabel asli, bukan hanya copy untuk di prosedur aja
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sorting(int data[], int n){
    // mau sort data sebanyak n kali
    for(int i = 0; i < n - 1; i++){
        int min = i; // set dulu sekarang minimumnya di siapa
        for(int j = i + 1; j < n; j++){
            if(data[j] < data[min]){
                min = j;
                // min disini menyimpan index/posisi elemen terkecil
            }
        }
        // kalo sudah bener minimumnya di i, maka akan swap dengan dirinya sendiri
        swap(&data[i], &data[min]);
    }
}

void PRINT_SET(const MysteryJournalSet *S){ // karena harus menarik : yang berarti terurut, maka mending bikin prosedur baru
    if(S->count == 0){
        printf("{}\n");
        return;
    }

    // siapkan dulu slot data sebanyak MAX PAGE, walaupun nantinya hanya dipake beberapa elemen
    // harus copas dulu isi setnya ke temp
    // supaya isi aslinya ga berubah
    // kalo langsung sort, misalnya isi asli : 10 5 20 
    // langsung sort --> 5 10 20
    // --> nanti isi aslinya berubah jadi : 5 10 20
    int temp[MAX_PAGE];

    for(int i = 0; i < S->count; i++){
        temp[i] = S->data[i];
    }

    // melakukan sort sebanyak berapa jumlah elemen di S
    sorting(temp, S->count);

    for(int i = 0; i < S->count; i++){
        printf("%d", temp[i]);
        if(i < S->count - 1){
            printf(", ");
        }
    }
    printf("}");
}