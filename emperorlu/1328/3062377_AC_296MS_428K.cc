#include<iostream>
#include<math.h>
using namespace std;
double x[1001],y[1001];
struct In
{
    double left,right;
}info[1001];
int cmp(const void *a,const void *b)
{
    struct In *c = (In *)a; 
    struct In *d = (In *)b; 
    return c->right > d->right ? 1:-1;
}
int main()
{
    int n,d,cn=1;
    while(1)
    {
        cin>>n>>d;
        if(!n&&!d)break;
        double dmax=0;
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
            if(dmax<y[i])dmax=y[i];
        }
        cout<<"Case "<<cn++<<": ";
        if(d<dmax)
        {
            cout<<"-1"<<endl;
            continue;
        }
        double tmp;
        for(int i=0;i<n;i++)
        {
            tmp = sqrt(d*d-y[i]*y[i]);
            info[i].left = x[i] - tmp;
            info[i].right = x[i] + tmp;
        }
        qsort(info,n,sizeof(info[0]),cmp);
        int sum=1;
        double right=info[0].right;
        for(int i=1;i<n;i++)
        {
            if(info[i].left > right)
            {
                sum++;
                right = info[i].right;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
