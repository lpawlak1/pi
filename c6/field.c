#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int reku(int* a,int i,int j,int k,int l,int n, int maxi, int* dp, int* dp_2){
    // w prawo
    if(l != n-1){
        short falg = 0;
        if(dp_2[(l*n*n)+(i*n)+k] != -1){
            falg = dp_2[(l*n*n)+(i*n)+k];
        }else
            for(int o = i;o<=k;o++){
                if (a[(o*n)+l+1] != 0){
                    falg = 1;
                    break;
                }
            }
        if(falg ==0){
            dp_2[(l*n*n)+(i*n)+k] = falg;
            maxi = max(reku(a,i,j,k,l+1,n,
                        (k-i+1)*(l+1-j+1),dp,dp_2),maxi);
        }
    }
    // w dol
    if(k != n-1){
        short falg = 0;
        k+=1;
        if(dp[(k*n*n)+(j*n)+l] != -1){
            falg = dp[(k*n*n)+(j*n)+l];
        }else
            for(int o = j;o<=l;o++){
                if (a[(k*n)+o] != 0){
                    falg = 1;
                    break;
                }
            }
        if(falg == 0){
            maxi = max(reku(a,i,j,k,l,n,
                        (k-i+1)*(l+1-j),dp,dp_2),maxi);
            dp[(k*n*n)+(j*n)+l] = falg;
        }
    }
    return maxi;
}

int main(){
    int n;
    scanf("%d",&n);
    int* a = malloc(sizeof(int)*n*n);
    short flasg = 0;
    short jedynki = 0;
    for(int i = 0; i<n*n;i++){
        scanf("%d",&a[i]);
        if(a[i] == 1)
            flasg = 1;
        else
            jedynki = 1;
    }
    if(flasg == 0){
        free(a);
        printf("%d",n*n);
        return 0;
    }
    if(jedynki == 0){
        free(a);
        printf("%d",0);
        return 0;
    }
    int maxi = 0;

    int* dp = malloc(sizeof(int)*n*n*n);
    memset(dp,-1,sizeof(int)*n*n*n);

    int* dp_2 = malloc(sizeof(int)*n*n*n);
    memset(dp_2,-1,sizeof(int)*n*n*n);

    for(int i =n-1;i>=0;i--){
        for(int j = n-1; j>=0;j--){
            if(a[(i*n)+j] != 1)
                maxi = max(reku(a,i,j,i,j,n,1,dp,dp_2),maxi);
        }
    }
    printf("%d",maxi);

    free(a);
    free(dp);
    free(dp_2);
    return 0;
}

