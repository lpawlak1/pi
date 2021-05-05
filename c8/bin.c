#include <stdlib.h>
#include <malloc.h>

enum{false, true};

int rekurencja(char* tab,int curr_idx,int k, int *curr_k,int n,int last){
    if(curr_idx == n){
        (*curr_k)++;
        if (*curr_k == k){
            printf("%s",tab);
            return true;
        }
        return false;
    }

    tab[curr_idx] = '0';
    int a = rekurencja(tab,curr_idx+1,k,curr_k,n,false);

    if (last == false){
        tab[curr_idx] = '1';
        return rekurencja(tab,curr_idx+1,k,curr_k,n,true) | a;
    }

    return a;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    int cu = 0;
    int* curr_idx = &cu;

    char* tab = malloc(sizeof(char)*n);

    int a = rekurencja(tab,0,k,curr_idx,n,false);
    if (!a){
        printf("-1");
    }
    free(tab);
}
