#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int sprawdz(int a, int n, int m){
    if (a%m == 0) return 0;
    for(int i = 0; i < n;i++){
        a ^= 1 << i;
        if (a%m==0 && a!=0) {
            return 1;
        }
        a ^= 1 << i;
    }
    return 0;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int cnt = 0;
    for (int i = 1; i < 1 << n;i++){
        if(sprawdz(i,n,m)){
            cnt++;
        }

    }
    printf("%d",cnt);
}
