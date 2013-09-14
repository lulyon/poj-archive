#include<iostream>
using namespace std;
int a[20010];
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    sort(a,a+n);
    int cn=0;
    for(int i=0,j=n-1;i<j;++i)
    {
       
            while(i<j&&a[i]+a[j]>s)
                --j;
            if(i<j)cn+=j-i;
    }
    printf("%d\n",cn);
    return 0;
}