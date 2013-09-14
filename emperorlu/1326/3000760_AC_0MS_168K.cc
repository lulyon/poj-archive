#include<stdio.h>
#include<stdlib.h>
int main()
{
    int miles,perk,sum;
    char means,a[20],b[20];
    sum=0;
    while(1)
    {
        scanf("%s",a);
        if(a[0]=='#')break;
        if(a[0]=='0')
        {
            printf("%d\n",sum);
            sum=0;
            continue;
        }
        scanf("%s",b);
        scanf("%d",&miles);
        getchar();
        scanf("%c",&means);
        //printf("a=%s,b=%s,miles=%d,means=%c",a,b,miles,means);
        //system("pause");
        if(means=='B')
        {
            perk=miles;
            if(miles%2)perk=perk+perk/2+1;
            else perk=perk+perk/2;
        }
        else if(means=='F')
        {
            perk=miles;
            perk=2*perk;
        }
        else if(means=='Y')
        {
            if(miles<500)miles=500;
            perk=miles;
        }
        sum+=perk;        
    }
    return 0;
}
