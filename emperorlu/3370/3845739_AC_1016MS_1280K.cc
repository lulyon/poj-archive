#include<iostream>
using namespace std;
int a[100010];
int b[100010];
bool num[100010];
int main()
{
    int c,n;
    while(1)
    {
        scanf("%d%d",&c,&n);
        if(!c&&!n)break;
        
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        
        b[1]=a[0]%c;
        for(int i=2;i<=n;++i)
        {
            b[i]=(b[i-1]+a[i-1])%c;
            //cout<<b[i]<<' ';
        }
        
        //cout<<endl;
        
        if(c==n)
        {
            int i;
            int flag=1;
            for(i=1;i<=n;++i)
                if(b[i]==0)
                {
                    flag=0;
                    break;
                }
            if(flag==0)
            {
                printf("1");
                for(int j=1;j<i;++j)
                    printf(" %d",j+1);
                printf("\n");
            }
            else
            {
                memset(num,0,(c+5)*sizeof(bool));
                int i;
                for(i=n;i>0;--i)
                {
                    if(num[b[i]])break;
                    num[b[i]]=1;
                }
            
                for(int j=i+1;;++j)
                {
                    if(b[j]==b[i])
                    {
                        printf("%d\n",j);
                        break;
                    }
                    else
                        printf("%d ",j);
                
                }
            }      
        }
        else
        {
            memset(num,0,(c+5)*sizeof(bool));
            int i;
            for(i=n;i>0;--i)
            {
                if(num[b[i]])break;
                num[b[i]]=1;
            }
            
            for(int j=i+1;;++j)
            {
                if(b[j]==b[i])
                {
                    printf("%d\n",j);
                    break;
                }
                else
                    printf("%d ",j);
                
            }
        }
    }
    return 0;
}
