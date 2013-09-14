#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double n,p;
    while(cin>>n>>p)
        cout<<(int)ceil(pow(p,1.0/n))<<endl;
    return 0;
}