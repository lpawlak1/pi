#include <stdio.h>


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

short is_uber_prime(int current){
    int last = 10;
    while(current != 0){
        int cyfra = current%10;
        if(cyfra > last){
            return 0;
        }
        else{
            last = cyfra;
        }
        current/=10;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    int current = 2;
    for(int current = 2; current < n; current = next_prime(current))
    {
        if(is_uber_prime(current)){
            printf("%d\n",current);
        }
    }
}


