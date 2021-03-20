#include <stdio.h>
#include <malloc.h>



short recursive_weight(int* tab,int idx,int w,int n,int szukana){
    if(w == szukana)
        return 1;
    if (n == idx){
        return 0;
    }
    if (recursive_weight(tab, idx+1, w+tab[idx], n,szukana) == 1)
        return 1;
    if (recursive_weight(tab, idx+1, w-tab[idx], n,szukana) == 1)
        return 1;
    if (recursive_weight(tab, idx+1, w, n,szukana) == 1)
        return 1;
    return 0;
}

int main(){
    int n,w;
    scanf("%d%d",&n,&w);
    int *tab = malloc(sizeof(int)*n);
    int suma=0;
    for(int i =0; i< n; i++){
        scanf("%d",&tab[i]);
        suma += tab[i];
    }
    if (suma < w)
        printf("NO");
    else if(recursive_weight(tab,0,0,n,w) == 1)
        printf("YES");
    else
        printf("NO");
    free(tab);
    return 0;
}

