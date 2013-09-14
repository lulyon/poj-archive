#include<stdio.h>   
int main()   
{   
    long n;   
    while(scanf("%ld",&n),n!=-1)   
    {   
        long s=6;   
        long t=n%7;   
        s=(s+t)%7;   
        long i,y,flag;  
        for(i=0;n>=0;i++)  
        {  
            if((i%4==0&&i%100!=0)||i%400==0)  
            {  
                flag=1;  
                n-=366;  
            }  
            else   
            {  
                flag=0;  
                n-=365;  
            }  
        }  
        i--;  
        if(flag)n+=366;  
            else n+=365;   
        y=2000+i;  
        n++;  
        long m,d;   
        if(flag)   
        {   
            if(n<=31){m=1;d=n;}   
            else if(n<=60){m=2;d=n-31;}   
            else if(n<=91){m=3;d=n-60;}   
            else if(n<=121){m=4;d=n-91;}   
            else if(n<=152){m=5;d=n-121;}   
            else if(n<=182){m=6;d=n-152;}   
            else if(n<=213){m=7;d=n-182;}   
            else if(n<=244){m=8;d=n-213;}   
            else if(n<=274){m=9;d=n-244;}   
            else if(n<=305){m=10;d=n-274;}   
            else if(n<=335){m=11;d=n-305;}   
            else {m=12;n=335;}   
        }   
        else   
        {   
            if(n<=31){m=1;d=n;}   
            else if(n<=59){m=2;d=n-31;}   
            else if(n<=90){m=3;d=n-59;}   
            else if(n<=120){m=4;d=n-90;}   
            else if(n<=151){m=5;d=n-120;}   
            else if(n<=181){m=6;d=n-151;}   
            else if(n<=212){m=7;d=n-181;}   
            else if(n<=243){m=8;d=n-212;}   
            else if(n<=273){m=9;d=n-243;}   
            else if(n<=304){m=10;d=n-273;}   
            else if(n<=334){m=11;d=n-304;}   
            else {m=12;n=334;}   
        }   
        printf("%ld-",y);   
        if(m<10)printf("0%ld-",m);   
        else printf("%ld-",m);   
        if(d<10)printf("0%ld",d);   
        else printf("%ld",d);   
        putchar(' ');   
        switch(s)   
        {   
            case 0:printf("Sunday");break;   
            case 1:printf("Monday");break;   
            case 2:printf("Tuesday");break;   
            case 3:printf("Wednesday");break;   
            case 4:printf("Thursday");break;   
            case 5:printf("Friday");break;   
            case 6:printf("Saturday");break;   
        }   
        putchar('\n');   
    }   
    return 0;   
}  
