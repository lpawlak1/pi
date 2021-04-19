#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define ez punkty[i]
struct punkt{
    int x1, y1,x2,y2;
};

void swap(int *pInt, int *pInt1);

int abs(int i){
    if(i < 0) return i*(-1);
    return i;
}
void swap(int *pInt, int *pInt1) {
    int* sw = pInt;
    pInt = pInt1;
    pInt1 = sw;
}
void wypelnij(struct punkt *punkcik,int* tablica){
    if(punkcik->x1 > punkcik->x2) swap(&punkcik->x1,&punkcik->x2);
    if(punkcik->y1 > punkcik->y2) swap(&punkcik->y1,&punkcik->y2);
    for(int i = punkcik->x1;i<punkcik->x2;i++){
        for(int j = punkcik->y1;j<punkcik->y2;j++){
//            printf("%d %d\n",i,j);
            tablica[((i+100)*201)+(j+100)] = abs(-1+ tablica[((i+100)*201)+(j+100)]);
//            tablica[((i-minx)*n) + (j-miny)] = abs(tablica[((i-minx)*n) + (j-miny)]-1);
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);
    struct punkt* punkty = calloc(n,sizeof(struct punkt));
    for(int i = 0;i<n;i++){
        scanf("%d%d%d%d",&ez.x1,&ez.y1,&ez.x2,&ez.y2);
    }
    int* tablica = calloc(sizeof(int),201*201);
    memset(tablica,0,sizeof(int));
    for(int i = 0;i<n;i++){
        wypelnij(&ez,tablica);
    }
    int suma = 0;
    for(int i = 0;i<201*201;i++){
        if (tablica[i] == 1){
            suma += 1;
        }
    }
    printf("%d",suma);
    free(tablica);
    free(punkty);
    return 0;
}