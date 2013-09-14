#include<stdio.h>
int main()
{
    int a1,a2,a3,a4,a5,a6,total,tmp_1,tmp_2,tmp_3,tmp;
    while(1)
    {
        scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
        if(!a1&&!a2&&!a3&&!a4&&!a5&&!a6)break;
        total=a6+a5+a4+(a3+3)/4;
        tmp_2=5*a4;
        tmp_3=a3%4;
        if(tmp_3==0)tmp=0;
        if(tmp_3==1)
        {
            tmp_2+=5*a3;
            tmp=7;
        }
        else if(tmp_3==2)
        {
            tmp_2+=3*a3;
            tmp=6;
        }
        else
        {
            tmp_2+=a3;
            tmp=5;
        }
        if(a2>tmp_2)
        {
            a2-=tmp_2;
            total+=(a2+8)/9;
            if(a2%9)tmp_1=36-(a2%9)*4;
            else tmp_1=0;
            tmp_1+=a5*11+tmp;
        }
        else
        {
            if(tmp_3)tmp=36-9*tmp_3;
            else tmp=0;
            tmp_1=a5*11+a4*20+tmp-a2*4;
        }
        if(a1>tmp_1)
        {
            a1-=tmp_1;
            total+=(a1+35)/36;
        }
        printf("%d\n",total);
    }
    return 0;
}
