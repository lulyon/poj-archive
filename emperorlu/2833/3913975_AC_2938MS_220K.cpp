#include<algorithm>
using namespace std;
int a[20],b[20];
int asize,bsize;

void heap_increase_key(int *b,int i,int key)
{
    b[i]=key;
    while(i>1&&b[i/2]<b[i])
    {
        b[i]^=b[i/2]^=b[i]^=b[i/2];
        i/=2;
    }
}

void max_heap_insert(int *b,int key)
{
    b[++bsize]=-INT_MAX;
    heap_increase_key(b,bsize,key);
}

void max_heapify(int *b,int i)
{
    int l,r,lar;
    l = i+i;
    r = l+1;
    if(l<=bsize && b[l]>b[i])
        lar = l;
    else
        lar = i;
    
    if(r<=bsize && b[r]>b[lar])
        lar = r;
    
    if(lar!=i)
    {
        b[i]^=b[lar]^=b[i]^=b[lar];
        max_heapify(b,lar);
    }
}

void extract_max(int *b)
{
    b[1]=b[bsize--];
    max_heapify(b,1);
}

void heap_decrease_key(int *a,int i,int key)
{
    a[i]=key;
    while(i>1&&a[i/2]>a[i])
    {
        a[i]^=a[i/2]^=a[i]^=a[i/2];
        i/=2;
    }
}

void min_heap_insert(int *a,int key)
{
    a[++asize]=INT_MAX;
    heap_decrease_key(a,asize,key);
}

void min_heapify(int *a,int i)
{
    int l,r,small;
    l = i+i;
    r = l+1;
    if(l<=asize && a[l]<a[i])
        small = l;
    else
        small = i;
    
    if(r<=asize && a[r]<a[small])
        small = r;
    
    if(small!=i)
    {
        a[i]^=a[small]^=a[i]^=a[small];
        min_heapify(a,small);
    }
}

void extract_min(int *a)
{
    a[1]=a[asize--];
    min_heapify(a,1);
}


int main()
{
    int n1,n2,n;
    while(1)
    {
        scanf("%d%d%d",&n1,&n2,&n);
        if(!n1&&!n2&&!n)break;
        
        
        asize = bsize = 0;
        long long sum,sum1,sum2;
        sum = sum1 = sum2 = 0;
        int tmp;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&tmp);
            sum+=tmp;
            
            if(asize<n1)
            {
                min_heap_insert(a,tmp);
            }
            else
            {
                min_heap_insert(a,tmp);
                extract_min(a);
            }
            
            if(bsize<n2)
                max_heap_insert(b,tmp);
            else
            {
                max_heap_insert(b,tmp);
                extract_max(b);
            }
        }
        
        for(int i=1;i<=n1;++i)
        {
            sum1+=a[i];
        }
        
        for(int i=1;i<=n2;++i)
        {
            sum2+=b[i];
        }
        
        printf("%.6lf\n",(sum-sum1-sum2)/(double)(n-n1-n2));
    }
    return 0;
}
