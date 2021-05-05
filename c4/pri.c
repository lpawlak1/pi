#include <stdio.h>
#include <malloc.h>

short isprime(int num){
    if (num <= 1) return 0;
    if(num == 2 || num == 3){
        return 1;
    }
    if(num%2 ==0 || num%3==0) return 0;
    int i = 5;
    while (i*i<=num)
    {
        if(num%i==0 || num%(i+2)==0) return 0;
        i+=6;
    }
    return 1;
}

short check(int num){
    int cp = 0;
    int nowa = num;
    while(nowa != 0){
        cp+=(nowa%10)*(nowa%10);
        nowa/=10;
    }

    if (cp == 4) return 0;
    else if (cp > 1) return check(cp);
    else return 1;
}

int main(){
    int l,u,k;
    scanf("%d%d%d",&l,&u,&k);
    int last = 0;
    for(;l<=u && k>0;l++){
        if(isprime(l) == 1 && check(l) == 1){
            last = l;
            k-=1;
        }
    }
    if(k == 0) printf("%d",last);
    else printf("-1");

    return 0;
}
