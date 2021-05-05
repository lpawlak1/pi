#include <stdio.h>

int suma(int num){
    int suma=0;
    for(int i = num-1;i>0;i-=1)
    {
        if(num%i == 0){
            suma += i;
        }
    }
    return suma;
}

int main(){
    for(int i=0;i<=100000;i++){
        int suma_dzielnikow = suma(i);
        if(suma_dzielnikow < i)
            if(suma(suma_dzielnikow) == i){
                printf("%d %d\n",i,suma_dzielnikow);
            }
    }
}
