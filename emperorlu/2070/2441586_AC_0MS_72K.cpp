#include<stdio.h>
int main()
{
    float a,b,c,x,y,z;
    while((scanf("%f%f%f",&a,&b,&c),a)!=0)
    {
         x=a<=4.5&&b>=150&&c>=200;
         y=a<=6.0&&b>=300&&c>=500;
         z=a<=5.0&&b>=200&&c>=300;
         if(x&&!y&&!z)printf("Wide Receiver");
         if(!x&&y&&!z)printf("Lineman");
         if(!x&&!y&&z)printf("Quarterback");
         if(x&&y&&!z)printf("Wide Receiver Lineman");
         if(!x&&y&&z)printf("Lineman Quarterback");
         if(x&&!y&&z)printf("Wide Receiver Quarterback");
         if(x&&y&&z)printf("Wide Receiver Lineman Quarterback");
         if(!x&&!y&&!z)printf("No positions");
         printf("\n");
    }
    printf("\n");
    return 0;
}
