#include <stdio.h>
#include <malloc.h>

void insert(int *tab, int n){
    // na idx 0 jest wartosc do przestawienia
    for (int i = 0;i<n-1 && tab[i] < tab[i+1];i++){
        int temp = tab[i];
        tab[i] = tab[i+1];
        tab[i+1] = temp;
    }
}

int partition(int *tab,int left,int right){
    int j = left;
    for (int i = left;i<right;i++){
        if (tab[i] > tab[right]){
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            j++;
        }
    }
    int temp = tab[right];
    tab[right] = tab[j];
    tab[j] = temp;
    return j;
}

void quicksort(int *tab,int left,int right){
    if (left < right){
        int q = partition(tab,left,right);
        quicksort(tab,left,q-1);
        quicksort(tab,q+1,right);
    }
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    int *tab = malloc(sizeof(int)*n);
    for(int i =0;i<n;i++) scanf("%d",&tab[i]);

    quicksort(tab,0,n-1);

    for (int j = 0;j<k;j++){
        tab[0] = tab[0]/2;
        insert(tab,n);
    }

    int suma = 0;
    for(int i =0;i<n;i++) suma += tab[i];
    printf("%d",suma);

    free(tab);
    return 0;
}
