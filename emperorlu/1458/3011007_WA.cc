#include<stdio.h>  
#include<memory.h>  
char a[10000],b[10000];  
int c[2000],d[2000];  
int main()  
{  
    while(memset(a,0,sizeof(a)),memset(b,0,sizeof(b)),scanf("%s%s",a,b)!=EOF)  
    {  
        memset(c,0,sizeof(c));  
        memset(d,0,sizeof(d));  
        for(int i=0;a[i];i++)  
            c[a[i]]=1;  
        for(int i=0;b[i];i++)  
            d[b[i]]=1;  
        int cn=0;  
        for(int i=0;i<1000;i++)  
            if(c[i]&&d[i])cn++;  
        printf("%d\n",cn);  
    }  
    return 0;  
} 
