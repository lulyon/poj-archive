#include<stdio.h> 
int a[101][101],t,m,n,i,j; 
int main() 
{ 
    for(i=0;i<=1;i++) 
        for(j=0;j<=10;j++) 
            a[j][i]=a[i][j]=1; 
    for(i=2;i<=10;i++) 
        for(j=2;j<=10;j++) 
        { 
            if(j<=i)a[i][j]=a[i][j-1]+a[i-j][j]; 
            else a[i][j]=a[i][i]; 
        }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n); 
        printf("%d\n",a[m][n]); 
    }
    return 0; 
}