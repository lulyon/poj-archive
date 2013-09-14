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

int dfs(int i,int j)
{
    int max=0,temp;
    int ii=0,jj=0;
    if(!b[a[i-1][j]])
    {
        b[a[i-1][j]]=1;
        temp=dfs(i-1,j);
        if(max<temp)
        {
            max=temp;
            ii=i-1;
            jj=j;
        }
        b[a[i-1][j]]=0;
    }
    if(!b[a[i+1][j]])
    {
        b[a[i+1][j]]=1;
        temp=dfs(i+1,j);
        if(max<temp)
        {
            max=temp;
            ii=i+1;
            jj=j;
        }
        b[a[i+1][j]]=0;
    }
    if(!b[a[i][j-1]])
    {
        b[a[i][j-1]]=1;
        temp=dfs(i,j-1);
        if(max<temp)
        {
            max=temp;
            ii=i;
            jj=j-1;
        }
        b[a[i][j-1]]=0;
    }
    if(!b[a[i][j+1]])
    {
        b[a[i][j+1]]=1;
        temp=dfs(i,j+1);
        if(max<temp)
        {
            max=temp;
            ii=i;
            jj=j+1;
        }
        b[a[i][j+1]]=0;
    }
    b[a[ii][jj]]=1;
    return max+1;
}

int main()
{
    readin();
    b[a[1][1]]=1;
    printf("%d\n",dfs(1,1));
    return 0;
}