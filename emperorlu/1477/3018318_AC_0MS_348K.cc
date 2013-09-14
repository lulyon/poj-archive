#include<iostream>
using namespace std;
int n,h[51];
int main()
{
    int cn=1;
    while(1)
    {
        cin>>n;
        if(!n)break;
        int sum=0,aver,move=0;
        for(int i=0;i<n;i++)
        {
            cin>>h[i];
            sum+=h[i];
        }
        aver=sum/n;
        for(int i=0;i<n;i++)
            if(h[i]>aver)move+=h[i]-aver;
        cout<<"Set #"<<cn++<<endl;
        cout<<"The minimum number of moves is "<<move<<'.'<<endl<<endl;
    }
    return 0;
}
