#include<iostream>
using namespace std;
char a[1000],b[1000];
int hash1[1000],hash2[1000];
int main()
{
    int t1,t2,t3,top;
    while(1)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        if(!t1&&!t2&&!t3)break;
        
        scanf("%s",a);
        
        top=0;
        for(int i=0;a[i];++i)
        {
            if(a[i]>='a'&&a[i]<='i')
                hash1[top++]=i;
        }
        
        for(int i=0;i<top;++i)
        {
            hash2[(i+t1)%top]=hash1[i];
        }
        
        for(int i=0;i<top;++i)
        {
            b[i]=a[hash2[i]];
        }
        for(int i=0;i<top;++i)
        {
            a[hash1[i]]=b[i];
        }
        //cout<<a<<endl;
        
        top=0;
        for(int i=0;a[i];++i)
        {
            if(a[i]>='j'&&a[i]<='r')
                hash1[top++]=i;
        }
        
        for(int i=0;i<top;++i)
        {
            hash2[(i+t2)%top]=hash1[i];
        }
        
        for(int i=0;i<top;++i)
        {
            b[i]=a[hash2[i]];
        }
        for(int i=0;i<top;++i)
        {
            a[hash1[i]]=b[i];
        }
        //cout<<a<<endl;
        
        top=0;
        for(int i=0;a[i];++i)
        {
            if(a[i]>='s'&&a[i]<='z'||a[i]=='_')
                hash1[top++]=i;
        }
        
        for(int i=0;i<top;++i)
        {
            hash2[(i+t3)%top]=hash1[i];
        }
        
        for(int i=0;i<top;++i)
        {
            b[i]=a[hash2[i]];
        }
        for(int i=0;i<top;++i)
        {
            a[hash1[i]]=b[i];
        }
        
        printf("%s\n",a);
        
    }
    return 0;
}
