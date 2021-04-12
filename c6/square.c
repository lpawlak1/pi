#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int min(int a,int b){
    if (a < b)
        return a;
    return b;
}
int max(int a, int b){
    if (a>b) return a;
    return b;
}
void print(int* piony,int* poziomy, int idx){
    printf("%d\n",idx);
    for (int i = 0; i < idx;i ++){
        printf("%d %d\n",piony[i],poziomy[i]);
    }

}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int* a = malloc(sizeof(int)*n*n);
    for(int i = 0; i<n*n;i++){
        scanf("%d",&a[i]);
    }
    int* piony = malloc(sizeof(int)*n*n);
    int* poziomy = malloc(sizeof(int)*n*n);
    int idx = 0;
    for(int i =1;i<n-1;i++){
        for(int j = 1; j<n-1;j++){
            for(int l = 1;;l++){
                if (i + l >= n || j+l >= n || i-l < 0 || j-l <0)
                    break;
                int suma = 0;
                for(int p = i-l;p<=i+l;p++){
                    suma += a[(p*n)+(j-l)];
                    suma += a[(p*n)+(j+l)];
                }
                for(int p = j-l+1;p<=j+l-1;p++){
                    suma += a[((i-l)*n)+(p)];
                    suma += a[((i+l)*n)+(p)];
                }
                if (suma == k){
                    piony[idx] = i;
                    poziomy[idx] = j;
                    idx++;
                }
            }
        }
    }
    print(piony,poziomy,idx);
    free(a);
    free(piony);
    free(poziomy);
}
