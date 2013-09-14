#include<iostream>
using namespace std;
int main()
{
    int x1,y1,x2,y2,tmp;
    double p1,p2,p;
    while(1)
    {
        cin>>x1>>y1>>x2>>y2;
        if(!x1&&!y1&&!x2&&!y2)break;
        if(x1>y1)
        {
            tmp=x1;
            x1=y1;
            y1=tmp;
        }
        if(x2>y2)
        {
            tmp=x2;
            x2=y2;
            y2=tmp;
        }
        if(x1<=x2&&y1<=y2)p=1;
        else
        {
            p1=(double)x2/(double)x1;
            p2=(double)y2/(double)y1;
            p=p1<p2?p1:p2;
        }
        cout<<(int)(100*p)<<'%'<<endl;
    }
    return 0;
}
