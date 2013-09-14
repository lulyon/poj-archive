#include<iostream>
using namespace std;
#define MAXN 500010
int a[MAXN];
long long sum;//记录一个sum，表示移动步数。

void merge(int p,int q,int r)
{
int i,j,k,n1=q-p+1,n2=r-q;
int *L=new int[n1+1];

int *R=new int[n2+1];

for(i=1;i<=n1;++i)
L[i]=a[p+i-1];

for(i=1;i<=n2;++i)
R[i]=a[q+i];

i=j=1;
k=p;
while(i<=n1&&j<=n2)
{
if(L[i]<=R[j])
{
a[k++]=L[i++];
}
else
{
a[k++]=R[j++];
sum+=q-p-i+2;
}
}
while(i<=n1)
a[k++]=L[i++];
while(j<=n2)
a[k++]=R[j++];

delete []L;
delete []R;


}

void merge_sort(int p,int r)
{
if(p<r)
{
int q=(p+r)/2;
merge_sort(p,q);
merge_sort(q+1,r);
merge(p,q,r);
}
}
int main()
{
    int t,n;
    cin>>t;
    for(int k=1;k<=t;++k)
    {
        scanf("%d",&n);
        
        for(int i=1;i<=n;++i)
            scanf("%d",a+i);

        sum=0;
        merge_sort(1,n);
        
        printf("Scenario #%d:\n",k);
        cout<<sum<<endl<<endl;
    }
    return 0;
}
