#include <stdio.h>
int main()
{
    __int64 test,tol,cant,pos,t,i,n,res,temp; 
    
    scanf("%I64d",&test);
    for(t=1;t<=test;t++ )
    {
        scanf("%I64d%I64d%I64d",&tol,&cant,&pos);
        printf("Case %I64d:",t);
        if(pos>tol||pos+cant-1>tol )
            printf("It cannot be solved.\n");
        else
        {
            n = pos + cant;
            for(i=pos;i<n;i++)
            {
                res=0;temp=i;
                for(;temp;temp/=2 )
                    res+=temp%2; 
                printf(" %I64d",res);
            }    
            printf("\n");
        }       
    }  
    return 0;
}    
