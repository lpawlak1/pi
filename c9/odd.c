#include <malloc.h>
#include <stdlib.h>


int main(){
    int n;
    scanf("%d",&n);
    unsigned long long int suma = 0;
    int j=1;
    for(int i = 1;i<=n;i+=2){
        j = i;
        while (j <= n){
            suma += i;
            j*=2;
        }
    }
    printf("%llu",suma);
}
