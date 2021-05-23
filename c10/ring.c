#include "stdlib.h"
#include "malloc.h"
#include "string.h"

int is_lt(char* first, char* second){
    int i = 0;
    int j = 0;
    while (i < strlen(first) && j < strlen(second) && first[i] == second[i]){
        i++;
        j++;
    }
    if (i == strlen(first)) return 0;
    else if (j == strlen(second)) return 1;
    return (first[i] < second[j]);
}

short is_prime(int n){
    if(n <= 1){
        return 0;
    }
    if(n==2 || n ==3){
        return 1;
    }
    if(n%2==0 || n%3==0){
        return 0;
    }
    for(int i = 5; i*i <= n; i+=6){
        if(n%i==0 || n%(i+2)==0) return 0;
    }
    return 1;
}

int next_prime(int current){
    current++;
    while(is_prime(current) == 0) current++;
    return current;
}

int main(){
    char* wejscie = malloc(sizeof(char)*51);
    scanf("%s",wejscie);

    int n = strlen(wejscie);

    char* maxi = malloc(sizeof(char)*51);
    char* curr = malloc(sizeof(char)*51);

    for (int o = 0; o < n; o++){
        for(int current = 2; current < n; current = next_prime(current))
        {
            for(int i = 0; i < n; i++){
                curr[i] = wejscie[(o+(i*current))%n];
            }
            if (is_lt(curr,maxi)){
                strcpy(maxi, curr);
            }
        }
    }
    printf("%s",maxi);
    free(maxi);
    free(wejscie);
    free(curr);
    return 0;
}


