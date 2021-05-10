#include <stdlib.h>
#include <stdio.h>

int check(long long int i){
    int len = 0;
    while(i != 0){
        i/=10;
        len+=1;
    }
    return len;
}

int main(){
    long long int S = 0;
    scanf("%lld",&S);
    long long int len = check(S);

    int i = 1;
    long long int cos= 1;
    while (i < len){
        cos *= 10;
        cos ++;
        i++;
    }

    int* N = malloc(sizeof(int)*len);
    for (int i = 0; i< len; i++){
        while (S-cos >= 0){
            S -= cos;
            N[i] ++;
            if (N[i] > 9){printf("-1"); free(N); return -1234567;}
        }
        cos/=10;
    }

    for(int i = (N[0] == 0) ? 1 : 0 ; i < len; i++){
        printf("%d",N[i]);
    }

    free(N);
}

