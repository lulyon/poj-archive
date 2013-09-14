#include "stdio.h" 
int a[10001]; 
int main() 
{ 
    int n,m,k; 
    while(1) 
    { 
		scanf("%d%d%d",&n,&k,&m);
		if(!n&&!k&&!m)break;
        int i,j,s=k-m+1; 
        for(i=1;i<n+1;i++) 
       		a[i]=i;
        for(i=n;i>1;i--) 
        { 
            s=(s+m-1)%i; 
            if(s==0) s=i;
            for(j=s;j<i;j++)a[j]=a[j+1]; 
        }
        printf("%d\n",a[1]); 
    }
    return 0;
}
