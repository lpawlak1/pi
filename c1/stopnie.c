#include <stdio.h>

int main() {
    //?Wypisz zestawienie temperatur Far-Cel dla f =0,20,40,...,300
    int f=0;
    while(f<=300){
        int c = (5.0f/9.0f) *(f-32.0f);
        printf("%d F ->",f);
        printf("%d C\n",c);
        f+=20;
    }

    return 0;
}
