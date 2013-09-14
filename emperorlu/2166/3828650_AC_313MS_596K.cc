#include<iostream>
using namespace std;
int n;
int heapsize;
int a[50010];
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
void heap_increase_key(int *a,int i,int key)
{
    if(key<a[i])
        cerr<<"wrong"<<endl;
    a[i]=key;
    while(i>1 && a[i/2]<a[i])
    {
        a[i]^=a[i/2]^=a[i]^=a[i/2];
        i>>=1;
    }
}

void heap_insert(int *a,int key)
{
    heapsize++;
    a[heapsize]=-INT_MAX;
    heap_increase_key(a,heapsize,key);
}

int main()
{
    scanf("%d",&n);
    heapsize=0;
    for(int i=2;i<=n;++i)
        heap_insert(a,i);
    
    a[n]=1;
    
    printf("%d",a[1]);
    for(int i=2;i<=n;++i)
        printf(" %d",a[i]);
    
    printf("\n");
    
    return 0;
}
