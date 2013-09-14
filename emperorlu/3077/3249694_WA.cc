#include<iostream>
using namespace std;
char a[20];
int main()
{
    freopen("out.txt","w",stdout);
    int t,lenth;
    cin>>t;
    while(t--)
    {
        scanf("%s",a);
        lenth = strlen(a);
        if(lenth == 1)
        {
            printf("%c\n",a[0]);
            continue;
        }
        
        for(int i=lenth-1;i>1;--i)
        {
            if(a[i]>='5'&&a[i-1]>='4')
                a[i-1]='5';
        }
        
        if(a[1]>='5')
        {
            if(a[0]=='9')
            {
                printf("10");
                while(--lenth)printf("0");
                printf("\n");
                continue;
            }
            else
            {
                printf("%c",a[0]+1);
                while(--lenth)printf("0");
                printf("\n");
            }
        }
        else
        {
            printf("%c",a[0]);
            while(--lenth)printf("0");
            printf("\n");
        }
    } 
    return 0;
}
