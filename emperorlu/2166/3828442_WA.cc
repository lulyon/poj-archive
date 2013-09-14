#include<iostream>
using namespace std;
int n;
void max_heapify(int *a,int i)
{
    int l,r,lar;
    l = 2*i;
    r = 2*i+1;
    
    if(l<=n && a[l]>a[i])
        lar = l;
    else lar = i;
    
    if(r<=n && a[r]>a[lar])
        lar = r;
    
    if(lar!=i)
    {
        a[i]^=a[lar]^=a[i]^=a[lar];
        max_heapify(a,lar);
    }
}
void build_max_heap(int *a)
{
    for(int i=n/2;i;--i)
        max_heapify(a,i);
}
int main()
{
    int a[50010];
    scanf("%d",&n);
    for(int i=n;i;--i)
        a[i]=i;
    
    build_max_heap(a);
    
    printf("%d",a[1]);
    for(int i=2;i<=n;++i)
        printf(" %d",a[i]);
    
    printf("\n");
    return 0;
}
