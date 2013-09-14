#include<iostream>
using namespace std;
char a[20][100000],b[20][100000],c[100000];
int clen,alen[20],blen[20];
void m(char *aa,int index,int m)
{
    int s=0,n=alen[index];
    for(int i=1;i<=n;++i)
    {
        c[i] = (m*(aa[i]-'0')+s)%10+'0';
        s = (m*(aa[i]-'0')+s)/10;
    }
    if(s)
    {
        clen=alen[index]+1;
        c[clen]=s+'0';
    }
    else
    {
        clen=alen[index];
    }
    /*
    for(int i=c[0];i>0;--i)
        printf("%c",c[i]);
    cout<<endl;
     */
}

void add(char *aa,int index,int j)
{
    int i,s=0,n=clen,m=alen[index];
    char tmp;
    for(i=1;i<=n&&i+j-1<=m;++i)
    {
        tmp = aa[i+j-1];
        aa[i+j-1]=(c[i]-'0'+tmp-'0'+s)%10+'0';
        s = (c[i]-'0'+tmp-'0'+s)/10;
    }
    
    for(;i<=n;++i)
    {
        aa[i+j-1]=(c[i]-'0'+s)%10+'0';
        s = (c[i]-'0'+s)/10;
    }
    for(;i+j-1<=m;++i)
    {
        tmp = aa[i+j-1];
        aa[i+j-1]=(tmp-'0'+s)%10+'0';
        s = (tmp-'0'+s)/10;
    }
    
    if(n>m+1-j)
    {
        i=n;
    }
    else
    {
        i=m+1-j;
    }
    
    alen[index]=i+j-1;
    
    if(s)
    {
        alen[index]++;
        aa[alen[index]]=s+'0';
    }
}

void f(int i)
{
    int n=blen[i-1];
    
    for(int j=1;j<=n;++j)
    {
        clen=0;    
        m(a[i-1],i-1,b[i-1][j]-'0');
        add(a[i],i,j);
    }
}

void g(int i)
{
    int s=1,n=alen[i];
    for(int j=1;j<=n;++j)
    {
        b[i][j] = (a[i][j]-'0'+s)%10+'0';
        s = (a[i][j]-'0'+s)/10;
    }
    
    if(s)
    {
        blen[i]=alen[i]+1;
        b[i][blen[i]]=s+'0';
    }
    else
    {
        blen[i]=alen[i];
    }
}

void init()
{
    alen[1]=1;
    a[1][1]='1';
    
    blen[1]=1;
    b[1][1]='2';
    
    for(int i=2;i<=18;++i)
    {
        //a[i]=a[i-1]*b[i-1];
        f(i);
        g(i);
        //cout<<"hello,world"<<endl;
       // b[i]=a[i]+1;
    }
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    
    for(int i=1;i<=n;++i)
    {
        for(int j=blen[i];j>0;--j)
            printf("%c",b[i][j]);
        cout<<endl;
    }
     
    return 0;
}

