#include<iostream>
using namespace std;
char a[100010],b[100010];
int main()
{
    int i,j,k;
    while(scanf("%s%s",a,b)!=EOF)
    {
        for(i=0,j=0;b[i]&&a[j];)
        {
            if(a[j]==b[i])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if(!b[i]&&a[j])
            puts("No");
        else if(!a[j])
            puts("Yes");
    }
    return 0;
}
