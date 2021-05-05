#include <stdio.h>

int main(){
    int f1=0;
    int f2=1;
    int n;
    scanf("%d",&n);
    while(f1*f2 < n){
        int temp = f1+f2;
        f1 = f2;
        f2 = temp;
    }
    if(f1*f2 == n) printf("YES");
    else printf("NO");
}
