#include<iostream>
using namespace std;
long long a[10] = {0};
void init()
{
    a[0] = 0;
    for(int i=1;i<=5;i++)
    {
        long long exp = 1;
        for(int j=1;j<i;j++)
        {
            a[i] += j*exp;
            exp *= 10;
        }
        a[i] *= 81*exp;
        a[i] += i*(9*exp + 1)*9*exp/2+a[i-1];
        /*
        cout<<i<<"  "<<a[i]<<endl;
        system("pause");
        */
    }
}
int main()
{
    init();
    int t,i;
    long long n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(1)
        {
            for(i=0;i<=4;i++)
                if(n>a[i]&&n<=a[i+1])break;
            n -= a[i];
            /*
            cout<<n<<endl;
            system("pause");
            */
            if(n <= 45)break;
        }
        int m;
        for(i=1;;i++)
        {
            m = i*(i-1)/2;
            if(n>m&&n<=m+i)break;
        }
        n -= m;
        cout<<n<<endl;
    }
    return 0;
}
