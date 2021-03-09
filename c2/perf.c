//
// Created by lukas on 09.03.2021.
//
#include <stdio.h>
#include <math.h>
#include <malloc.h>

int main(){
    int* a = malloc(sizeof(int)*10);
    int poczatek, koniec;
    scanf("%d %d",&poczatek, &koniec);
    int ile_ich_jest=0;
    int one[10];
    if(poczatek % 2 ==1){
        poczatek++;
    }
    for(int i=poczatek;i<=koniec;i+=2){
        int suma=0;
        suma += 1;
        for(int j=2;j<=sqrt(i);j+=1){
            if(i%j==0){
                suma+=j;
                suma+=(i/j);
            }
        }
        if(suma == i){
            one[ile_ich_jest] = i;
            ile_ich_jest++;
        }
    }
    printf("%d\n",ile_ich_jest);
    for(int i = 0; i < ile_ich_jest-1; i++){
        printf("%d ",one[i]);
    }
    if(ile_ich_jest >= 1)
        printf("%d\n",one[ile_ich_jest-1]);
    free(a);
}

