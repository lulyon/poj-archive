#include<iostream>
using namespace std;

int main()
{
    long n;
    while(scanf("%ld",&n)!=EOF)
    {
        while(1)
        {
            if(n==2)
            {
                printf("YES\n");
                break;
            }
            if(n%2)
            {
                printf("NO\n");
                break;
            }
            n>>=1;
        }
    }
    return 0;
}
