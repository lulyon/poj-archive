#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double n,p,result;
    while(cin>>n>>p)
    {
        result = pow(p,1.0/n);
        cout<<dec<<result<<endl;
    }
    return 0;
}
