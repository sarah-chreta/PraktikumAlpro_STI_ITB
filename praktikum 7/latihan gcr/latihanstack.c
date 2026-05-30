#include "latihanstack.h"

void CreateStack(Stack *s){
    s->idxTop = IDX_UNDEF;
}

bool isEmpty(Stack s){
    return (s.idxTop == IDX_UNDEF);
}

bool isFull(Stack s){
    return (s.idxTop == CAPACITY - 1);
}

void push(Stack *s, ElType val){
    if(!isFull(*s)){
        s->idxTop++;
        s->buffer[s->idxTop] = val;
    }
}

void pop(Stack *s, ElType *val){
    if(!isEmpty(*s)){
        *val = s->buffer[s->idxTop];
        s->idxTop--;
    }
}

void copyStack(Stack sIn, Stack *sOut){
    // awalnya -> SIn : 1 2 3 , SOut : kosong
    // mau jadi -> SIn : 1 2 3 , SOut : 1 2 3
    // SIn tidak boleh berubah
    Stack temp;
    CreateStack(&temp);
    CreateStack(sOut);
    ElType x; //stack menyimpan data bertipe ElType

    while(!isEmpty(sIn)){
        pop(&sIn, &x);
        push(&temp, x);
    }

    while(!isEmpty(temp)){
        pop(&temp, &x);

        push(&sIn, x);
        push(sOut, x);
    }
}

void inverseStack(Stack *s){
    Stack temp;
    ElType x;

    CreateStack(&temp);

    while(!isEmpty(*s)){
        pop(s, &x); // tidak perlu * lagi karena di parameter sudah mengatakan s ke pointer
        push(&temp, x);
    }

    *s = temp;
}

Stack mergeStack(Stack s1, Stack s2){
    Stack s3;
    Stack temp1;
    Stack temp2;
    ElType x;

    CreateStack(&s3);
    CreateStack(&temp1);
    CreateStack(&temp2);

    while(!isEmpty(s1)){
        pop(&s1, &x);
        push(&temp1, x);
    }

    while(!isEmpty(s2)){
        pop(&s2, &x);
        push(&temp2, x);
    }

    while(!isEmpty(temp1)){
        pop(&temp1, &x);
        push(&s3, x);
    }

    while(!isEmpty(temp2)){
        pop(&temp2, &x);
        push(&s3, x);
    }
    return s3;
}

