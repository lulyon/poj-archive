#include<iostream>
using namespace std;
int main()
{
    int tmp,i,a,b,c;
    int bin[10000][4];
    int tag=0;
    //freopen("1543.txt","w",stdout);    
    for(i=6;i<=100;i++)
        for(a=2;a<=i;a++)
        {
            for(b=a;a*a*a+b*b*b<=i*i*i;b++)
                for(c=b;a*a*a+b*b*b+c*c*c<=i*i*i;c++)
                    if(i*i*i==a*a*a+b*b*b+c*c*c)
                    {
                        bin[tag][0]=i;
                        bin[tag][1]=a;
                        bin[tag][2]=b;
                        bin[tag][3]=c;
                        tag++;
                        goto leap;
                    }
            leap:
                ; 
        }
    int n;
    int len=tag;
    while(cin>>n)
    {
        for(tag=0;tag<len;tag++)
        {
            if(bin[tag][0]>n)break;
            printf("Cube = %d, Triple = (%d,%d,%d)\n",
            bin[tag][0],bin[tag][1],bin[tag][2],bin[tag][3]);
        }
    }
    return 0;
}
