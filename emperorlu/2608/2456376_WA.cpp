#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char a[100000];
    while(scanf("%s",a)!=EOF)
    {
        int x[100000]={0};
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='B'||a[i]=='F'||a[i]=='P'||a[i]=='V')
                x[i]=1;
            if(a[i]=='C'||a[i]=='G'||a[i]=='J'||a[i]=='K'||a[i]=='Q'||a[i]=='S'||a[i]=='X'||a[i]=='Z')
                x[i]=2;
            if(a[i]=='D'||a[i]=='T')
                x[i]=3;
            if(a[i]=='L')x[i]=4;
            if(a[i]=='M'||a[i]=='N')x[i]=5;
            if(a[i]=='R')x[i]=6;
        }
        for(i=1;i<strlen(a);i++)
        {
            if(a[i-1]==a[i])x[i]=0;
        }
        for(i=0;i<strlen(a);i++)
        {
            if(x[i]!=0)printf("%d",x[i]);
        }
        printf("\n");
    }
    return 0;  
}

    
