#include<iostream>
#include<math.h>
using namespace std;
char str[10000];
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        if(str[0]=='0'&&str[1]=='\0')
        {
            printf("0 [8] = 0 [10]\n");
            continue;
        }
        
        if(str[0]=='1')
        {
            printf("1 [8] = 1 [10]\n");
            continue;
        }
        int n=strlen(str);
        n-=2;
        double sum=0.00000000000000000000000000000;
        double exp=1;
        for(int i=2;str[i];++i)
        {
            exp*=8;
            sum+=(str[i]-'0')/exp;
        }
        
        printf("%s [8] = 0.",str);
        double s;
        for(int i=1;i<=3*n;++i)
        {
            sum*=10;
            s=floor(sum);
            sum-=s;
            printf("%.0lf",s);
        }
        printf(" [10]\n");
    }
    return 0;
}
