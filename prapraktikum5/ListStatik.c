/* File : ListStatik.c */
/* Kejadian anomali dicatat dalam bentuk angka */

#include "ListStatik.h"
#include <stdio.h>

void MakeEmptyList (TabInt *T){
    T->Neff = 0;
}

int Length (TabInt T){
    return T.Neff;
}

int MaxNbEl (TabInt T){
    return MaxCapacity;
}

IdxType GetFirstIdx (TabInt T){
    if (T.Neff == 0) return -1;
    return IdxMin;
}

IdxType GetLastIdx (TabInt T){
    if (T.Neff == 0) return -1;
    return T.Neff;
}

ElType GetElmtAt (TabInt T, IdxType i){
    if (T.Neff == 0) return ElUndef;
    return T.TI[i];
}

void SetTab (TabInt Tin, TabInt *Tout){
    *Tout = Tin;
}

void SetEl (TabInt *T, IdxType i, ElType v){
    T->TI[i] = v;
}

void SetNeff (TabInt *T, IdxType N){
    T->Neff = N;
}

boolean IsIdxValid (TabInt T, IdxType i){
    return (i >= IdxMin && i <= MaxCapacity);
}

boolean IsIdxEff (TabInt T, IdxType i){
    return (i >= IdxMin && i <= T.Neff);
}

boolean IsEmpty (TabInt T){
    return (T.Neff == 0);
}

boolean IsFull (TabInt T){
    return (T.Neff == MaxCapacity);
}

void ShowAll (TabInt T){
    if (T.Neff == 0){
        printf("Tabel kosong\n");
    }
    else {
        printf("[");
        for (int i = 1; i <= T.Neff; i++){
            printf("%d", T.TI[i]);
            if(i < T.Neff){
                printf(",");
            }
        }
        printf("]\n");
    }
}

TabInt PlusTab(TabInt T1, TabInt T2){
    TabInt T;
    MakeEmptyList(&T);

    for (int i = 1; i <= T1.Neff; i++){
        T.TI[i] = T1.TI[i] + T2.TI[i];
    }

    T.Neff = T1.Neff;
    return T;
}

TabInt MinusTab(TabInt T1, TabInt T2){
    TabInt T;
    MakeEmptyList(&T);

    for (int i = 1; i <= T1.Neff; i++){
        T.TI[i] = T1.TI[i] - T2.TI[i];
    }

    T.Neff = T1.Neff;
    return T;
}

ElType ValMax(TabInt T){
    ElType max = T.TI[1];
    for (int i = 2; i <= T.Neff; i++){
        if(T.TI[i] > max){
            max = T.TI[i];
        }
    }
    return max;
}

ElType ValMin(TabInt T){
    ElType min = T.TI[1];
    for (int i = 2; i <= T.Neff; i++){
        if(T.TI[i] < min){
            min = T.TI[i];
        }
    }
    return min;
}

IdxType IdxMaxTab(TabInt T){
    IdxType idx = 1;
    for (int i = 2; i <= T.Neff; i++){
        if (T.TI[i] > T.TI[idx]){
            idx = i;
        }
    }
    return idx;
}

IdxType IdxMinTab(TabInt T){
    IdxType idx = 1;
    for (int i = 2; i <= T.Neff; i++){
        if (T.TI[i] < T.TI[idx]){
            idx = i;
        }
    }
    return idx;
}

TabInt ConcatTable(TabInt T1, TabInt T2){
    TabInt T;
    MakeEmptyList(&T);

    int k = 1;

    for(int i = 1; i <= T1.Neff; i++){
        T.TI[k++] = T1.TI[i];
    }

    for(int i = 1; i <= T2.Neff; i++){
        T.TI[k++] = T2.TI[i];
    }

    T.Neff = T1.Neff + T2.Neff;
    return T;
}
