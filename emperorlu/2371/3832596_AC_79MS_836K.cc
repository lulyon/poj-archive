#include<iostream>
#include<algorithm>
using namespace std;
int a[100010];
char b[10];
int main()
{
    int n,k,index;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    
    scanf("%s",b);
    
    cin>>k;
    while(k--)
    {
        scanf("%d",&index);
        printf("%d\n",a[index-1]);
    }
    
    
    return 0;
}
