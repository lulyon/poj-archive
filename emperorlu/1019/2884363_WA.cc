    #include<stdio.h>
    #include<math.h>
    int main()
    {
        int t;
        __int64 a,n,result;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%I64d",&a);
            n=(int)((sqrt(1+8*a)-1)/2.0);
            if(a==n*(n+1)/2)n--;
            result=a-(n+1)*n/2;
            printf("%I64d\n",result);
        }
        return 0;
    }
