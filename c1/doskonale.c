#include <stdio.h>

int main(){
    for(int i=1;i<=10000;i+=1){
        int suma=0;
        for(int j=i-1;j>0;j-=1){
            if(i%j==0){
                suma+=j;
                if(suma > i)
                    break;
            }
        }
        if(suma == i){
            printf("%d\n",i);
        }
    }
}
