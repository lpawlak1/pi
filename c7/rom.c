#include <malloc.h>
#include <stdlib.h>
#include <string.h>
 
char t1[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
char * t2[] = {"CM", "CD", "XC", "XL", "IX", "IV", "I"};
int t3[] = {1000, 500, 100, 50, 10, 5, 1};
int t4[] = {900, 400, 90, 40, 9, 4, 1};
 
int f1(char * num)
{
    u_int32_t len = strlen(num);
    int suma = 0;
    int j = 0, i = 0;
    while (i < len)
    {
        if (num[i] == t1[j])
        {
            suma += t3[j];
            i++;
        }
        else if (i < len-1 && num[i] == t2[j][0] && num[i+1] == t2[j][1])
        {
            suma += t4[j];
            i += 2;
        }
        else
            j++;
    }
    return suma;
}
 
void f2(int n)
{
    char* wynik = malloc(sizeof(char)*10);
    int wynik_idx = 0;

    int j = 0;
    while (n > 0)
    {
        if (n >= t3[j])
        {
            n -= t3[j];
            wynik[wynik_idx++] =  t1[j];
        }
        else if (n >= t4[j]) {
            n -= t4[j];
            wynik[wynik_idx++] = t2[j][0];
            wynik[wynik_idx++] = t2[j][1];
        }
        else
            j++;
    }
    printf("%s",wynik);
    free(wynik);
}

int main()
{
    char *tab1=malloc(sizeof(char)*7), *tab2=malloc(sizeof(char)*7);
    scanf("%s %s",tab1,tab2);
    f2(f1(tab1) + f1(tab2));
    free(tab1);
    free(tab2);
    return 0;
}
