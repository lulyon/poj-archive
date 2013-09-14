#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    double vr,vs,r,c,w;
    cin>>vs>>r>>c>>n;
    while(n--)
    {
        cin>>w;
        vr=vs/sqrt(r*r+1/(w*w*c*c))*r;
        printf("%.3f\n",vr);
    }
    return 0;
}