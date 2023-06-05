#include <stdio.h>
#include "matrix.h"

int main(){
    int n;
    scanf("%d", &n);
    Matrix m;
    readMatrix(&m,n,n);
    RotateMat(&m);
    displayMatrix(m);
    return 0;
}