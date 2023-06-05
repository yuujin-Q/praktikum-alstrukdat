#include <stdio.h>
#include "matrix.h"

int main(){
    int n;
    scanf("%d", &n);
    Matrix m;
    readMatrix(&m,n,n);
    printf("%f",AvgCol(m, 0));
    return 0;
}