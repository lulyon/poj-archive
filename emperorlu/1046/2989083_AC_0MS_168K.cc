#include<stdio.h>
struct In
{
    int r,g,b;
}data[16];
int main()
{
    int r,g,b,d;
    for(int i=0;i<16;i++)
        scanf("%d%d%d",&data[i].r,&data[i].g,&data[i].b);
    while(scanf("%d%d%d",&r,&g,&b),r+1||g+1||b+1)
    {
        int min=65530,s=0;
        for(int i=0;i<16;i++)
        {
            d=(data[i].r-r)*(data[i].r-r)+
            (data[i].g-g)*(data[i].g-g)+
            (data[i].b-b)*(data[i].b-b);
            if(min>d)
            {
                s=i;
                min=d;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",
        r,g,b,data[s].r,data[s].g,data[s].b);
    }
    return 0;
}
