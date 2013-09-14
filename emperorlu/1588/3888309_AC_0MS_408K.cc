#include<iostream>
using namespace std;
char str[1000];
char aa[1000];
int stack[1000];
int flag[7]={-1,'I'-'V','I'-'X','X'-'L','X'-'C','C'-'D','C'-'M'};
int score[7]={1,5,10,50,100,500,1000};
int tran(char a)
{
    switch(a)
    {
        case('I'):return 0;
        case('V'):return 1;
        case('X'):return 2;
        case('L'):return 3;
        case('C'):return 4;
        case('D'):return 5;
        case('M'):return 6;
    }
}

int chartonum(char *str)
{
    int sum=0;
        for(int i=0;str[i];)
        {
            int tmp=i;
            int count=1;
            while(str[i+1]&&(str[i+1]+flag[tran(str[i+1])])==str[i])
            {
                i++;
                count++;
            }
            int tag=1;
            if(count%2==0)
                tag*=-1;
            for(int j=tmp;j<=i;j++)
            {
                sum+=(tag*score[tran(str[j])]);
                tag*=-1;
            }
            i++;
        }
    return sum;
}
void numtochar(int n)
{
    int tmp;
    tmp = n/1000;
    int top=0;
    for(int i=0;i<tmp;++i)
        str[top++]='M';
    
    n%=1000;
    if(n>=900)
    {
        str[top++]='C';
        str[top++]='M';
    }
    else if(n>=400&&n<500)
    {
        str[top++]='C';
        str[top++]='D';
    }
    else
    {
        if(n>=500)
        {
            str[top++]='D';
            n-=500;
        }
        tmp = n/100;
        for(int i=0;i<tmp;++i)
            str[top++]='C';
        
    }
    n%=100;
    if(n>=90)
    {
        str[top++]='X';
        str[top++]='C';
    }
    else if(n>=40&&n<50)
    {
        str[top++]='X';
        str[top++]='L';
    }
    else
    {
        if(n>=50)
        {
            str[top++]='L';
            n-=50;
        }
        tmp = n/10;
        for(int i=0;i<tmp;++i)
            str[top++]='X';
        
    }
    n%=10;
    if(n>=9)
    {
        str[top++]='I';
        str[top++]='X';
    }
    else if(n>=4&&n<5)
    {
        str[top++]='I';
        str[top++]='V';
    }
    else
    {
        if(n>=5)
        {
            str[top++]='V';
            n-=5;
        }
        tmp = n;
        for(int i=0;i<tmp;++i)
            str[top++]='I';
        
    }
    str[top++]=0;
}
int main()
{
    int a,b;
    int top=0;
    
    while(scanf("%s",aa)!=EOF)
    {
        if(aa[0]<='Z'&&aa[0]>='A')
        {
            stack[top++]=chartonum(aa);
            
        }
        else if(aa[0]=='=')
        {
            if(top==0)
            {
                printf("stack underflow\n");
                continue;
                
            }
            else
            {
                if(stack[top-1]<=0||stack[top-1]>=5000)
                {
                    printf("out of range exception\n");
                    continue;
                }
                numtochar(stack[top-1]);
                printf("%s\n",str);
                
            }
        }
        else
        {
            if(top<2)
            {
                printf("stack underflow\n");
                continue;
            }
            a = stack[top-2];
            b = stack[top-1];
            top-=2;
            switch(aa[0])
            {
                
            case '+': a+=b;;break;
            case '-':a-=b;break;
            case '*':a*=b;break;
            case '/':
                if(b==0)
                {
                    printf("division by zero exception\n");
                    
                }
                else
                {
                    a/=b;
                }
                break;
            
            }
            stack[top++]=a;
        }
        
    }
    return 0;
}

