#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(n==-1)break;
        char name[20][10];
        int cub[20];
        int x,y,z;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y>>z>>name[i];
            cub[i]=x*y*z;
        }
        int max=0,smax,smin,min=10000;
        for(int i=0;i<n;i++)
        {
            if(cub[i]<min)
            {
                min=cub[i];
                smin=i;
            }
            if(cub[i]>max)
            {
                max=cub[i];
                smax=i;
            }
        }
        cout<<name[smax]<<" took clay from "<<name[smin]<<'.'<<endl;
    }
    return 0;
}
