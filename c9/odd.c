#include <malloc.h>
#include <stdlib.h>


int main(){
    int n;
    scanf("%d",&n);
    /* int* tabie = malloc(sizeof(int)*n); */
    // 0... n-1
    int suma = 0;
    for(int i = 1;i<=n;i++){
        if (i %2 == 1) suma += i;
        else{
            int j = i/2;
            if (j%2==0) j--;
            for(;j > 0; j-=2){
                if(i%j == 0){
                    suma += j;
                    break;
                }
            }
        }
    }
    printf("%d",suma);
}
