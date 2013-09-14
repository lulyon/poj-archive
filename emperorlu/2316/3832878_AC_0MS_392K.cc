#include<iostream>
using namespace std;
void add(char *a,char *b)
{
    for(int i=0;a[i];++i)
    {
        a[i]=(a[i]-'0'+b[i]-'0')%10+'0';
    }
}

int main()
{
    char a[15];
    char b[15];
    scanf("%s",a);
    while(scanf("%s",b)!=EOF)
    {
        add(a,b);
    }
    printf("%s",a);
    return 0;
}
