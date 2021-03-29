#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int * arr = (int*) malloc(200*sizeof(int));
    for(int i = 0; i < 200; i++) arr[i] = 0;
    // 199 -> 0
    arr[0] = 1;
    for(int i = 1;i<=n;i++){
        int reszta = 0;
        for(int j = 0; j < 200; j++){
            int liczba = arr[j] * i + reszta;
            arr[j] = liczba%10;
            reszta = liczba/10;
        }
    }
    int i = 199;
    while (i > 0 && arr[i] == 0)
        i--;
    while(i >= 0){
        printf("%d",arr[i]);
        i-=1;
    }
    free(arr);
}
