#include <stdio.h>
#include <malloc.h>


int main(){
    int n=0;
    scanf("%d",&n);
    int* tab = malloc(sizeof(int)*n);
    int suma = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",&tab[i]);
        suma += tab[i];
    }
    int prefix_sum=0;
    for(int i = 0; i < n;i++){
        if(suma-prefix_sum-tab[i] == prefix_sum){
            printf("%d\n",i);
            free(tab);
            return 0;
        }
        prefix_sum+=tab[i];
    }
    free(tab);
    return 0;
}
