#include "rangeSumBST.h"

int rangeSumBST(BinTree p, int L, int R){
    if(p == NIL){
        return 0;
    }

    int sum = 0;
    if(ROOT(p).key >= L && ROOT(p).key <= R){
        sum = sum + (ROOT(p).key * ROOT(p).count);
    }

    return sum + rangeSumBST(LEFT(p), L, R) + rangeSumBST(RIGHT(p), L, R);
}
