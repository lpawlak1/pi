#include <stdlib.h>
#include <malloc.h>


int zlicz(int **T,int** P,int k,int l,int n,int i,int j,int maxi){
    if (i+k > n || l+j > n){
        return maxi;
    }
    int suma = 0;
    for(int o = 0;o<k;o++){
        for(int u = 0;u<l;u++){
            if(P[o][u] == 1){
                suma += T[o+i][u+j];
            }
        }
    }
    return suma;
}

int main(){
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);

    int **T = malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        T[i] = malloc(sizeof(int)*n);
        for(int j = 0;j<n;j++)
            scanf("%d",&T[i][j]);
    }

    int **P = malloc(sizeof(int*)*k);
    for(int i = 0;i<k;i++){
        P[i] = malloc(sizeof(int)*l);
        for(int j = 0; j<l;j++){
            scanf("%d",&P[i][j]);
        }
    }

    int maxi = zlicz(T,P,k,l,n,0,0,0);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int a = zlicz(T,P,k,l,n,i,j,maxi);
            maxi = (a > maxi) ? a : maxi;
        }
    }

    printf("%d",maxi);

    for(int i = 0;i<n;i++) free(T[i]);
    free(T);

    for(int i = 0;i<k;i++) free(P[i]);
    free(P);

    return 0;
}

