
#include <stdlib.h>
#include <stdio.h>

short check(int i , int S){
    int cp= i;
    int sum = 0;
    while(cp != 0){
        sum += cp;
        cp/=10;
    }
    if (sum == S)
        return 1;
    return 0;
}

int main(){
    int S;
    scanf("%d",&S);
    int i;
    for(i = 1;i<=S;i++) {
        if(check(i,S)){
            printf("%d",i);
            return 0;
        }
    }
    printf("%d",-1);
            
}
