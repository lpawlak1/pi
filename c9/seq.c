#include <malloc.h>
#include <stdlib.h>
#include <string.h>
enum bool{false,true};

int __cmp__(char* a, char* b)
{
    while (*a && *b){
        if(*a-*b != 0) return *a-*b > 0 ? 0 : 1;
        ++a, ++b;
    }
    if (*a) return 0;
    else return 1;
}

int main(){
    char* test = malloc(sizeof(char)*51);
    scanf("%s",test);
    int size = strlen(test);

    if(size == 1){
        printf("%s",test);
        free(test);
        return 0;
    }



    int* t = malloc(sizeof(int)*size);
    int l = size-1;
    t[l] = true;

    for (int x = l-1;x > -1; x--){
        if (test[x] >= test[l]){
            l = x;
            t[x] = true;
        }
    }

    for(int i = 0; i < size; i++){
        if (t[i] == true)
            printf("%c",test[i]);
    }
    free(test);
}
