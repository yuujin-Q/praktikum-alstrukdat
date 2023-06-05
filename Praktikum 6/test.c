#include <stdio.h>

int main(){
    int orderedIdx[6]={4,1,3,6,3,6};
    int len =6;
    int temp;
    for(int batas=0; batas<len-1; batas++){
        for(int i=len;i>batas;i--){
            if(orderedIdx[i]<orderedIdx[i-1]){
                temp = orderedIdx[i-1];
                orderedIdx[i-1] = orderedIdx[i];
                orderedIdx[i] = temp;
            }
        }
    }
    for(int j=0; j<len; j++){
        printf("%d ", orderedIdx[j]);
    }
    return 0;
}