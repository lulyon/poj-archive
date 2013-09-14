#include<iostream>
using namespace std;
char a[1000010];
bool Compare(int s1,int s2,int t1,int t2)
{
    for(int i=s1,j=t1;i<s2&&j<t2;++i,++j)
        if(a[i]!=a[j])return 0;
    return 1;
}

int main()
{
    while(1)
    {
        scanf("%s",a);
        if(a[0]=='.')break;
        int len= strlen(a),slen,i,j;
        for(i=len;i>1;--i)
        {
            if(len%i==0)
            {
                slen = len/i;
                for(j=1;(j+1)*slen<=len;++j)
                    if(!Compare(0,slen,j*slen,(j+1)*slen))break;
                if((j+1)*slen>len)
                {
                    printf("%d\n",i);
                    break;
                }
            }
        }
        if(i==1)printf("1\n");
    }
    return 0;
}
