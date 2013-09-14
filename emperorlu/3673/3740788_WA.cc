#include<iostream>
using namespace std;
char a[20],b[20];
int main()
{
    scanf("%s %s",a,b);
    int sum=0;
    for(int i=0;a[i];++i)
        for(int j=0;b[j];++j)
            sum+=(a[i]-'0')*(b[i]-'0');
    printf("%d\n",sum);
    return 0;
}