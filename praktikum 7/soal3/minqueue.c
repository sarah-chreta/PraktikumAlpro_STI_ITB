#include "minqueue.h"

void CreateMinQueue(MinQueue *mq){
    CreateStack(&mq->sIn);
    CreateStack(&mq->sInMin);
    CreateStack(&mq->sOut);
    CreateStack(&mq->sOutMin);
}

boolean isMQEmpty(MinQueue mq){
    return isEmpty(mq.sIn) && isEmpty(mq.sOut);
}

boolean isMQFull(MinQueue mq){
    // return isFull(mq.sIn) + isFull(mq.sOut);
    // bukan gini karena bisa saja sIn masi ada slot atau sebaliknya
    // jadi harus cek length
    return length(mq.sIn) + length(mq.sOut) == CAPACITY;
}

// sInMin menyimpan minimum di setiap posisi
// misal sekarang 5 minimumnya, keep it
// trus masuk 2 -> bandingkan , keep 2
// trus masuk 8 -> bandingkan 2 dan 8, keep 2, gituu
void enqueue(MinQueue *mq, ElType val){
    push(&mq->sIn, val);

    if(isEmpty(mq->sInMin)){
        push(&mq->sInMin, val);
    }
    else{
        ElType currentMin = TOP(mq->sInMin);

        if(val < currentMin){
            push(&mq->sInMin, val);
        }
        else{
            push(&mq->sInMin, currentMin);
        }
    }
}


void dequeue(MinQueue *mq, ElType *val){
    if(isEmpty(mq->sOut)){

        while(!isEmpty(mq->sIn)){
            ElType x;
            ElType dummy;

            pop(&mq->sIn, &x);
            pop(&mq->sInMin, &dummy);

            push(&mq->sOut, x);

            if(isEmpty(mq->sOutMin)){
                push(&mq->sOutMin, x);
            }
            else{
                ElType currentMin = TOP(mq->sOutMin);
                if(x < currentMin){
                    push(&mq->sOutMin, x);
                }
                else{
                    push(&mq->sOutMin, currentMin);
                }
            }
        }
    }

    pop(&mq->sOut, val);

    ElType dummy;
    pop(&mq->sOutMin, dummy);
}

ElType getMin(MinQueue mq){
    if(isEmpty(mq.sIn)){
        return TOP(mq.sOutMin);
    }
    else if(isEmpty(mq.sOut)){
        return TOP(mq.sInMin);
    }
    else{
        if(TOP(mq.sInMin) < TOP(mq.sOutMin)){
            return TOP(mq.sInMin);
        }
        else{
            return TOP(mq.sOutMin);
        }
    }
}

