#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void print(int *arr,int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j<n;j++){
            printf("%d ",arr[(i*n)+j]);
        }
        printf("\n");
    }
}

short check(int n,int i,int j){
    return (i >= 0 && j >= 0 && i < n && j < n) ? 1 : 0;
}

int suma(int * arr,int n,int i,int j,int r){
    int sum = 0;
    for(int k = i-r;k<=i+r;k++){
        if(check(n,k,0) == 1)
            for (int l = j-r;l <= j+r;l++){
                if(check(n,k,l) == 1)
                    sum += arr[(k*n) + l];
            }
    }
    return sum;
}

int main(){
    int n,r;
    scanf("%d %d",&n,&r);

    int *arr = malloc(sizeof(int)*n*n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&arr[(i*n)+j]);
        }
    }

    int *nowa = malloc(sizeof(int)*n*n);
    for(int i = 0;i<n;i++)
        for(int j = 0 ; j < n; j++)
            nowa[(i*n) + j] = suma(arr,n,i,j,r);

    print(nowa,n);

    free(nowa);
    free(arr);
    return 0;
}

