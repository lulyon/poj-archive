#include<cstdio>
using namespace std;
int n,pos1,pos2,sum[110][110],store[110][110];
char a[110],b[110];

void workout()
{
    int temp,i,j;
    for(i=0;i<pos1+1;i++)
    {
        for(j=0;j<pos2+1;j++)
        {
            if(i==0&&j==0)sum[i][j]=0;
            else if(i==0)sum[i][j]=store[b[j-1]][' ']+sum[i][j-1];
            else if(j==0)sum[i][j]=store[a[i-1]][' ']+sum[i-1][j];
            else
            {
                temp=sum[i-1][j]+store[a[i-1]][' '];
                if(temp<sum[i][j-1]+store[b[j-1]][' '])
                    temp=sum[i][j-1]+store[b[j-1]][' '];
                if(temp<sum[i-1][j-1]+store[a[i-1]][b[j-1]])
                    temp=sum[i-1][j-1]+store[a[i-1]][b[j-1]];
                sum[i][j]=temp;
            }
            //cout << sum[i][j]<< ' ';
        }
        //cout << endl;
    }
    printf("%d\n",sum[pos1][pos2]);
}
int main()
{
store['A']['A']=5;
store['A']['C']=store['C']['A']=-1;
store['A']['G']=store['G']['A']=-2;
store['A']['T']=store['T']['A']=-1;
store['A'][' ']=store[' ']['A']=-3;
store['C']['C']=5;
store['C']['G']=store['G']['C']=-3;
store['C']['T']=store['T']['C']=-2;
store['C'][' ']=store[' ']['C']=-4;
store['G']['G']=5;
store['G']['T']=store['T']['G']=-2;
store['G'][' ']=store[' ']['G']=-2;
store['T']['T']=5;
store['T'][' ']=store[' ']['T']=-1;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %s",&pos1,a);
        scanf("%d %s",&pos2,b);
        workout();
    }
    return 0;
}
