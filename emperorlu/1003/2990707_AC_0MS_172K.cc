#include "stdio.h"
float sum(int x)
{
    float s;
    s=0;
        for(int i=1;i<=x;i++)
        {
      
        s+=1.0/(float)(i+1);
        }
        return s;
}
int num(float y)
    {
        int i;
        for(i=1;;i++)
        {
        if(sum(i)>=y)break;
        }
    return i;
    }
int main()
{
    int i;
    float c;
    for(i=1;;i++)
    {
        scanf("%f",&c);
        if(c!=0)
        printf("%d card(s)\n",num(c));
        else break;
    }
    return 0;
}