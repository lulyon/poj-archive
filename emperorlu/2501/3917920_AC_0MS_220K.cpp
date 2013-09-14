#include<iostream>
using namespace std;
char str[100],tmp[100];

double transfer(char *str)
{
    int i,exp=1;
    double time=0;
    for(i=0;;++i)
        if(str[i]==':')break;
    for(int j=i-1;j>=0;--j)
    {
        time+=(str[j]-'0')*exp;
        exp*=10;
    }
    time+=((str[i+1]-'0')*10+(str[i+2]-'0'))/60.000000;
    time+=((str[i+4]-'0')*10+(str[i+5]-'0'))/3600.0000000;
    return time;
}


int main()
{
    double s=0,start=0,time,v=0,v1;
    while(gets(tmp))
    {
        int i;
        for(i=0;;++i)
            if(tmp[i]==0||tmp[i]==' ')break;
        if(tmp[i]==' ')
        {
            sscanf(tmp,"%s %lf",str,&v1);
            time = transfer(str);
            s += v*(time-start);
            start = time;
            v = v1;
        }
        else
        {
            sscanf(tmp,"%s",str);
            time = transfer(str);
            s += v*(time-start);
            start = time;
            printf("%s ",str);
            printf("%.2lf km\n",s);
        }
    }
    return 0;
}
