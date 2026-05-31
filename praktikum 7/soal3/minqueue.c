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
    
}

void dequeue(MinQueue *mq, ElType *val){

}

