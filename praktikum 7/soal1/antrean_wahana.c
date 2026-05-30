/* File: antrean_wahana.c */

#include "antrean_wahana.h"
#include <stdio.h>

void CreateAntrean(AntreanWahana *aw, int startTime){
    CreateQueue(&aw->prioritas);
    CreateQueue(&aw->regular);

    aw->currentTime = startTime;
    aw->priorityServedCount = 0;
}

boolean isAllEmpty(AntreanWahana aw){
    return((isEmpty(aw.prioritas)) && (isEmpty(aw.regular)));
}

boolean isPrioritasEmpty(AntreanWahana aw){
    return(isEmpty(aw.prioritas));
}

boolean isRegularEmpty(AntreanWahana aw){
    return(isEmpty(aw.regular));
}

int totalLength(AntreanWahana aw){
    return length(aw.prioritas) + length(aw.regular);
}

int lengthPrioritas(AntreanWahana aw){
    return length(aw.prioritas);
}

int lengthRegular(AntreanWahana aw){
    return length(aw.regular);
}

void AddPengunjung(AntreanWahana *aw, Pengunjung p, boolean isPriority){
    
}
