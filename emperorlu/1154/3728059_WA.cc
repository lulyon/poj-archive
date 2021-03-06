#include<iostream>
using namespace std;
int r,c;
char a[25][25];
bool b[200];
void readin()
{
    cin>>r>>c;
    b[0]=1;
    for(int j='A';j<='Z';++j)
        b[j]=0;
    for(int j=0;j<=c+1;++j)
        a[0][j]=a[r+1][j]=0;
    for(int i=1;i<=r;++i)
    {
        scanf("%s",&a[i][1]);
        a[i][0]=a[i][r+1]=0;
    }
}

int dfs(int i,int j,bool *s)
{
    int max=0,temp;
    s[a[i][j]]=1;
    bool *p=new bool[200];
    memcpy(p,s,200);
    if(!p[a[i-1][j]])
    {
        temp=dfs(i-1,j,p);
        if(max<temp)
            max=temp;
    }
    memcpy(p,s,200);
    if(!p[a[i+1][j]])
    {
        temp=dfs(i+1,j,p);
        if(max<temp)
            max=temp;
    }
    memcpy(p,s,200);
    if(!p[a[i][j-1]])
    {
        temp=dfs(i,j-1,p);
        if(max<temp)
            max=temp;
    }
    memcpy(p,s,200);
    if(!p[a[i][j+1]])
    {
        temp=dfs(i,j+1,p);
        if(max<temp)max=temp;
    }
    delete []p;
    return max+1;
}

int main()
{
    readin();
    printf("%d\n",dfs(1,1,b));
    return 0;
}