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
int reku(int* a,int i,int j,int k,int l,int n, int maxi){
    // w prawo
    if(l != n-1){
        short falg = 0;
        for(int o = i;o<=k;o++){
            if (a[(o*n)+l+1] != 0){
                falg = 1;
                break;
            }
        }
        if(falg ==0){
            maxi = max(reku(a,i,j,k,l+1,n,
                        (k-i+1)*(l+1-j+1)),maxi);
        }
    }
    // w dol
    if(k != n-1){
        short falg = 0;
        k+=1;
        for(int o = j;o<=l;o++){
            if (a[(k*n)+o] != 0){
                falg = 1;
                break;
            }
        }
        if(falg ==0){
            maxi = max(reku(a,i,j,k,l,n,
                        (k-i+1)*(l+1-j)),maxi);
        }
    }
    return maxi;
}

int main(){
    int n;
    scanf("%d",&n);
    int* a = malloc(sizeof(int)*n*n);
    for(int i = 0; i<n*n;i++){
        scanf("%d",&a[i]);
    }
    int maxi = 0;

    for(int i =n-1;i>=0;i--){
        for(int j = n-1; j>=0;j--){
            if(a[(i*n)+j] != 1)
                /* printf("%d %d %d\n",i,j,reku(a,i,j,i,j,n,1)); */
                maxi = max(reku(a,i,j,i,j,n,1),maxi);
        }
    }
    printf("%d",maxi);
    free(a);
}
