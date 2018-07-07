//  Hackerrank 
//
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    /*
    int iMax = 0, iResult;
    
    for( int i=l; i<=r; i++ ){
        for( int j=i; j<=r; j++ ){
             iResult = i ^ j;
             if( iMax < iResult ) iMax = iResult;
        }
    }
    return iMax;
    */
    int res = l^r;
    
    res|=res>>1;
    res|=res>>2;
    res|=res>>4;
    res|=res>>8;
    
    return res;
}

int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
