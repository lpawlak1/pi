#include <stdio.h>

int main() {
    //Wypisz zestawienie temperatur Celc-Faren dla f -100, -90, -80,...,100, 
    //a następnie zestawienie w odwrotnej kolejności.
    int c = 0;
    int farenheit=-100;
    while(farenheit<=100){
        c = (farenheit-32.0)/1.8f;
        printf("%d F ->",farenheit);
        printf("%d C\n",c);
        farenheit+=10;
    }
    printf("przerwa");
    c=-100;
    while(c<=100){
        farenheit = (c*1.8) +32;
        printf("%d F ->",farenheit);
        printf("%d C\n",c);
        c+=10;
    }
    return 0;
}
