#include<stdio.h>
int main()
{
    float a,b,c;
    while((scanf("%f%f%f",&a,&b,&c),a)!=0)
    {
         if(a<=4.5&&b>=150&&c>=200)
            printf("Wide Receiver ");
         if(a<=6.0&&b>=300&&c>=500)
            printf("Lineman ");
         if(a<=5.0&&b>=200&&c>=300)
            printf("Wide Receiver ");
         if(!(a<=4.5&&b>=150&&c>=200)&&!(a<=6.0&&b>=300&&c>=500)&&!(a<=5.0&&b>=200&&c>=300))
            printf("No positions");
         printf("\n");
    }
    printf("\n");
    return 0;
}
