#include<iostream>
using namespace std;
int main()
{
    //freopen("/export/home/acm/Desktop/1.dat","r",stdin);
    char c;
    bool b=0;
    
    while(scanf("%c",&c)!=EOF)
    {
        if(c=='\"')
        {
            if(!b)
            {
                b=1;
                printf("``");
            }
            else
            {
                b=0;
                printf("\'\'");
            }
        }
        else
            printf("%c",c);
    }
    return 0;
}

