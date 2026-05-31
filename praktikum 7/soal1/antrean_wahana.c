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
    if(isPriority){
        enqueue(&aw->prioritas, p);
    }

    if(!isPriority){
        enqueue(&aw->regular, p);
    }
}

boolean ServeNext(AntreanWahana *aw, Pengunjung *served){
    if(isAllEmpty(*aw)){
        return false;
    }

    if(aw->priorityServedCount < STARVATION_THRESHOLD && (!isPrioritasEmpty(*aw))){
        dequeue(&aw->prioritas, served); // diambil supaya dilayani mulai dari prioritas
        aw->priorityServedCount++;
        return true;
    }

    if(aw->priorityServedCount >= STARVATION_THRESHOLD && (!isRegularEmpty(*aw))){
        dequeue(&aw->regular, served);
        aw->priorityServedCount = 0;
        return true;
    }

    if(isPrioritasEmpty(*aw) && !isRegularEmpty(*aw)){
        dequeue(&aw->regular, served);
        aw->priorityServedCount = 0;
        return true;
    }

    if(!isPrioritasEmpty(*aw) && isRegularEmpty(*aw)){
        dequeue(&aw->prioritas, served);
        aw->priorityServedCount++;
        return true;
    }
    return false;
}

boolean RemoveTimedOut(AntreanWahana *aw){
    Queue tempprio;
    Queue tempreg;

    // Queue tidak bisa menghapus elemen sembarangan di tengah
    CreateQueue(&tempprio);
    CreateQueue(&tempreg);

    Pengunjung p;

    // harus mengecek antrian satu per satu (isempty)
    // gabisa langsung prioritas dan regular disimpulkan (isallempty)
    // karena what if pake isallempty tapi ternyata regular ada isi
    while(!isEmpty(aw->prioritas)){
        dequeue(&aw->prioritas, &p);

        int waitTime = aw->currentTime - p.arrivalTime;
        // misal :
        // currentTime : 100
        // arrivalTime : 80
        // waitTime : 20
        // patience : 10
        // 20 > 10 -> hapuskan
        // kalau waitime <= patience : masukkan kembali, tp ke temp
        if(waitTime <= p.patience){
            enqueue(&tempprio, p);
        }
    }

    aw->prioritas = tempprio;

    while(!isEmpty(aw->regular)){
        dequeue(&aw->regular, &p);

        int waitTime = aw->currentTime - p.arrivalTime;

        if(waitTime <= p.patience){
            enqueue(&tempreg, p);
        }
    }

    aw->regular = tempreg;
}

void UpdateTime(AntreanWahana *aw, int newTime){
    aw->currentTime = newTime;
}

Pengunjung PeekNextPrioritas(AntreanWahana aw){
    return front(aw.prioritas);
}

Pengunjung PeekNextRegular(AntreanWahana aw){
    return front(aw.regular);
}
