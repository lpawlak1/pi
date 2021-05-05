#include <stdlib.h>
#include <malloc.h>

	
#define max(X, Y)  ((X) > (Y) ? (X) : (Y))


int zlicz(int **T,int n,int k,int i,int j){
    //sprawdzam tylko w prawo, dol, po skosie w prawo dol
    int maxi = 0;
    //prawo
    int suma = 0;
    for(int l = 0;l<k;l++){
        suma += T[i][(j+(l+n))%n];
    }
    maxi = suma;
    //dol
    suma = 0;
    for(int l = 0;l<k;l++){
        suma += T[(i+(l+n))%n][j];
    }
    maxi = max(maxi,suma);
    //prawo dol
    suma = 0;
    for(int l = 0;l<k;l++){
        suma += T[(i+(l+n))%n][(j+(l+n))%n];
    }
    maxi = max(maxi,suma);
    // lewy dol
    suma = 0;
    for(int l = 0;l<k;l++){
        suma += T[(i-l+n+n)%n][(j-l+n+n)%n];
    }
    maxi = max(maxi,suma);

    //lewo
    suma = 0;
    for(int l = 0;l<k;l++){
        suma += T[i][(j-l+n)%n];
    }
    maxi = max(maxi,suma);
    //gora
    suma = 0;
    for(int l = 0;l<k;l++){
        suma += T[(i-l+n)%n][j];
    }
    maxi = max(maxi,suma);
    //prawo gora
    suma = 0;
    for(int l = 0;l<k;l++){
        suma += T[(i-l+n)%n][(j+l+n)%n];
    }
    maxi = max(maxi,suma);
    // lewy gora
    suma = 0;
    for(int l = 0;l<k;l++){
        suma += T[(i-l+n)%n][(j-l+n)%n];
    }
    maxi = max(maxi,suma);
    return maxi;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    int **T = malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        T[i] = malloc(sizeof(int)*n);
        for(int j = 0;j<n;j++){
            scanf("%d",&T[i][j]);
        }
    }
    int maxi = zlicz(T,n,k,0,0);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            maxi = max(maxi,zlicz(T,n,k,i,j));
        }
    }
    printf("%d",maxi);

    for(int i = 0;i<n;i++)
        free(T[i]);
    free(T);

    return 0;
}
