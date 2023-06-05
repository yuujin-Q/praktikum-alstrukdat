#include <stdio.h>
#include "matrix.h"

int main(){
    Matrix A, B;
    int n, m;
    scanf("%d %d",&n, &m);
    readMatrix(&A, n, m);
    putchar('\n');
    // scanf("%d %d",&n, &m);
    // readMatrix(&B, n, n);

    // if(isMatrixEqual(A,B)){
    //     printf("equal\n");
    // }
    // else{
    //     printf("not\n");
    // }
    // putchar('\n');
    
    // if(isMatrixNotEqual(A,B)){
    //     printf("not equal\n");
    // }
    // else{
    //     printf("not\n");
    // }

    // if(isMatrixSizeEqual(A,B)){
    //     printf("size equal\n");
    // }
    // else{
    //     printf("not\n");
    // }

    if (isSquare(A))
    {
        printf("is square");
    }
    else
    {
        printf("not square");
    }
    if (isSymmetric(A))
    {
        printf("is simetris");
    }
    else
    {
        printf("not simetris");
    }
    if (isIdentity(A))
    {
        printf("is identity");
    }
    else
    {
        printf("not identity");
    }
    return 0;
}