#include<iostream>
using namespace std;
bool a[13];
int main()
{
    long long s,d,sum;
    while(cin>>s>>d)
    {
        //memset(a,0,sizeof(a));
        if(4*s<d)
        {
            a[1]=1;
            a[2]=1;
            a[3]=1;
            a[4]=1;
            a[5]=0;
        }
        else if(3*s<2*d)
        {
            a[1]=1;
            a[2]=1;
            a[3]=1;
            a[4]=0;
            a[5]=0;
        }
        else if(2*s<3*d)
        {
            a[1]=1;
            a[2]=1;
            a[3]=0;
            a[4]=0;
            a[5]=0;
        }
        else if(s<4*d)
        {
            a[1]=1;
            a[2]=0;
            a[3]=0;
            a[4]=0;
            a[5]=0;
        }
        else
        {
            a[1]=0;
            a[2]=0;
            a[3]=0;
            a[4]=0;
            a[5]=0;
        }
        for(int i=2;i<=8;i++)
        {
            sum=0;
            for(int j=i;j<i+4;j++)
            {
                if(a[j])
                    sum += s;
                else
                    sum -= d;
            }
            if(sum+s<0)
                a[i+4]=1;
            else
                a[i+4]=0;
        }
        sum=0;
        for(int i=1;i<=12;i++)
        {
            if(a[i])
                sum += s;
            else 
                sum -= d;
        }
        if(sum<0)
            cout<<"Deficit"<<endl;
        else
            cout<<sum<<endl;
    }
    return 0;
}
