#include<iostream>
using namespace std;

bool b[30000];

char str[100];

int stack[1000];

char hash[5]={"udlr"};

int buffer[16];

typedef struct
{
    int i,j;
    int data[4][4];
    long long qnum;
}node;

node que[10000000];

long long cal(int aa[4][4])
{
    long long ans=0,EXP=100000000;
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            ans+=EXP*(aa[i][j]);
            EXP /= 10;
        }
    }
    return ans%29989;
}

void print(long long num)
{
    int top=0;
    while(num)
    {
        stack[top++]=num%4;
        num/=4;
    }
    for(int i=top-1;i>=0;--i)
    {
        printf("%c",hash[stack[i]]);
    }
    
}

void copy(int aa[4][4],int bb[4][4])
{
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            aa[i][j]=bb[i][j];
        }
    }
}

int main()
{
    gets(str);
    int top=0;
    for(int i=1;str[i];++i)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            buffer[top++]=str[i]-'0';
        }
        else if(str[i]=='x')
            buffer[top++]=0;
    }
    int low=0;
    for(int i=1;i<=3;++i)
    {
        for(int j=1;j<=3;++j)
        {
            que[0].data[i][j]=buffer[low];
            if(buffer[low]==0)
            {
                que[0].i=i;
                que[0].j=j;
            }
            ++low;
        }
    }
    
    que[0].qnum=0;
    int i,j,head,tail;
    long long num,qnum;
    num=cal(que[0].data);
    if(num==22056)
    {
        printf("\n");
        return 0;
    }
    b[num]=1;
    head=tail=0;
    
    
    while(head<=tail)
    {
        cout<<head<<' '<<tail<<endl;
        i=que[head].i;
        j=que[head].j;
        qnum=que[head].qnum;
        if(i>1)
        {
            que[head].data[i][j]=que[head].data[i-1][j];
            que[head].data[i-1][j]=0;
            num=cal(que[head].data);
            
            if(!b[num])
            {
                ++tail;
                copy(que[tail].data,que[head].data);
                que[tail].i=i-1;
                que[tail].j=j;
                que[tail].qnum=4*qnum;
                
                
                b[num]=1;
                
                if(num==22056)
                {
                    print(qnum);
                    printf("u\n");
                    break;
                }
            }
            que[head].data[i-1][j]=que[head].data[i][j];
            que[head].data[i][j]=0;
        }
        if(i<3)
        {
            que[head].data[i][j]=que[head].data[i+1][j];
            que[head].data[i+1][j]=0;
            num=cal(que[head].data);
            
            if(!b[num])
            {
                ++tail;
                copy(que[tail].data,que[head].data);
                que[tail].i=i+1;
                que[tail].j=j;
                que[tail].qnum=4*qnum+1;
                
                
                b[num]=1;
                
                if(num==22056)
                {
                    print(qnum);
                    printf("d\n");
                    break;
                }
            }
            
            que[head].data[i+1][j]=que[head].data[i][j];
            que[head].data[i][j]=0;
        }
        
        if(j>1)
        {
            que[head].data[i][j]=que[head].data[i][j-1];
            que[head].data[i][j-1]=0;
            num=cal(que[head].data);
            
            if(!b[num])
            {
                ++tail;
                copy(que[tail].data,que[head].data);
                que[tail].i=i;
                que[tail].j=j-1;
                que[tail].qnum=4*qnum+2;
                
                
                
                b[num]=1;
                
                if(num==22056)
                {
                    print(qnum);
                    printf("l\n");
                    break;
                }
            }
            
            que[head].data[i][j-1]=que[head].data[i][j];
            que[head].data[i][j]=0;
        }
        
        if(j<3)
        {
            que[head].data[i][j]=que[head].data[i][j+1];
            que[head].data[i][j+1]=0;
            num=cal(que[head].data);
            
            if(!b[num])
            {
                ++tail;
                copy(que[tail].data,que[head].data);
                que[tail].i=i;
                que[tail].j=j+1;
                que[tail].qnum=4*qnum+3;
                
                
                
                b[num]=1;
                
                if(num==22056)
                {
                    print(qnum);
                    printf("r\n");
                    break;
                }
            }
            
            que[head].data[i][j+1]=que[head].data[i][j];
            que[head].data[i][j]=0;
            
        }
        ++head;
    }
    if(head>tail)
        printf("unsolvable\n");
    
    return 0;
}
