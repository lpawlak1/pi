#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print(int *arr,int n){
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int get_min(int *arr,int *indexy,short *koniec, int n){
    int min = INT_MAX;
    int j = 0;
    for(int i = 0;i<n;i++){
        if(koniec[i] != 1){
            if(min > arr[(i*n) + indexy[i]]){
                min = arr[(i*n) + indexy[i]];
                j = i;
            }
        }
    }
    indexy[j]++;
    if(indexy[j] == n){
        koniec[j] = 1;
    }
    return min;
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = malloc(sizeof(int)*n*n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&arr[(i*n)+j]);
        }
    }

    int *wynik = malloc(sizeof(int)*n*n);
    int idx = 0;

    int *indexy = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++) indexy[i] = 0;

    short *koniec = malloc(sizeof(short)*n);
    for(int i=0;i<n;i++) koniec[i] = 0;

    int suma = 0; 
    while (suma < n*n){
        int min = get_min(arr,indexy,koniec,n);
        suma+=1;
        if (min != wynik[idx-1]){
            wynik[idx] = min;
            idx+=1;
        }
    }
    print(wynik,idx);

    free(arr);
    free(koniec);
    free(indexy);
    free(wynik);
    return 0;
}
