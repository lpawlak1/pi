#include <stdio.h>
#include <math.h>
#include <malloc.h>

int main(){
    int m=0,b=0;
    scanf("%d%d",&m,&b);
    short are_there=0;
    char* c = malloc(sizeof(char)*m);
    for(int i = pow(b,m-1);i < pow(b,m); i+=1){
        int nowa = i;
        int suma = 0;
        int idx=m-1;
        while (nowa != 0){
            int nr = nowa%b;
            suma += pow(nr,m);
            if(nr < 10)
                c[idx] = '0' + nr;
            else{
                nr-=10;
                c[idx] = 'A' + nr;
            }
            idx-=1;
            nowa /= b;
        }
        if(suma == i){
            printf("%s ",c);
            are_there = 1;
        }
    }
    if(are_there == 0){
        printf("NO");
    }
    free(c);
    return 0;
}
