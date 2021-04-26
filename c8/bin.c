#include <stdlib.h>
#include <malloc.h>
enum{false, true};

int rekurencja(char* curr_cos,int curr_idx,int k, int *curr_k,int n,int last){
    if(curr_idx == n){
        (*curr_k)++;
        if (*curr_k == k){
            printf("%s",curr_cos);
            return true;
        }
        return false;
    }
    curr_cos[curr_idx] = '0';
    int a = rekurencja(curr_cos,curr_idx+1,k,curr_k,n,false);
    if(a){
        return true;
    }
    if (last == false){
        curr_cos[curr_idx] = '1';
        a = rekurencja(curr_cos,curr_idx+1,k,curr_k,n,true);
        if(a){
            return true;
        }

    }
    return false;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int cu = 0;
    int* curr_idx = &cu;
    char* jakas_tablica = malloc(sizeof(char)*n);
    int a = rekurencja(jakas_tablica,0,k,curr_idx,n,false);
    if (!a){
        printf("-1");
    }
    free(jakas_tablica);
}
