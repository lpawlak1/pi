#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int __cmp__(char* a, char* b)
{
    while (*a && *b){
        if(*a-*b != 0) return *a-*b > 0 ? 0 : 1;
        ++a, ++b;
    }
    if (*a) return 0;
    else return 1;
}


void najwiekszy_substring(char* test, int idx, int size, char* max_str, char* curr, int curr_size,int index_test){
//    for(int i =0;i<curr_size;i++) printf("%c",curr[i]);
//    printf("\n");
    if (idx == size){
        if (curr_size > 0)
            if(__cmp__(max_str,curr)){
                strcpy(max_str,curr);
            }
        return;
    }
    najwiekszy_substring(test,idx+1,size,max_str,curr,curr_size,index_test+1);
    curr[curr_size] = test[idx];
    najwiekszy_substring(test,idx+1,size,max_str,curr,curr_size+1,index_test+1);
    curr[idx] = '\0';
}


int main(){
    char* test = malloc(sizeof(char)*51);
    scanf("%s",test);
    int size = strlen(test);
    char* curr = malloc(sizeof(char)*51);
    char* max_str= malloc(sizeof(char)*51);
    strcpy(max_str,test);
    memset(curr,'\0',51);
    najwiekszy_substring(test,0,size,max_str,curr,0,0);
    printf("%s",max_str);
    free(curr);
    free(test);
    free(max_str);
}
