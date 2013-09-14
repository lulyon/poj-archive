#include<iostream>
#include <algorithm> 
using namespace std; 
char str[201];
int main() 
{
    scanf("%s",str);
    char *Beg = str; 
    char *End = str + strlen(str);
    sort(Beg,End);
    do{
       printf("%s\n",str);
    }while(next_permutation(Beg, End)); 
    return 0;
} 
