#include<iostream>
using namespace std;
int n,d;
long long m,k;
long long a[550];
long long b[550][550];
long long tmp1[550][550];
long long tmp3[550][550];
long long re[550];

int main()
{
    scanf("%d %lld %d %lld",&n,&m,&d,&k);
    for(int i=1;i<=n;++i)
        scanf("%lld",a+i);
    int tmp;
    for(int i=1;i<=n;++i)
    {
        b[i][i]=1;
        for(int j=1;j<=d;++j)
        {
            tmp=i+j;
            if(tmp>n)tmp-=n;
            b[i][tmp]=1;
        }
        for(int j=1;j<=d;++j)
        {
            tmp=i-j;
            if(tmp<=0)
                tmp+=n;
            
            b[i][tmp]=1;
        }
    }
    
   if(k%2)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                tmp1[i][j]=b[i][j];
            }
        }
    }

   else
     {
        for(int i=1;i<=n;++i)
        {
            tmp1[i][i]=1;
        }
     }
   
            int s=1,cn=0;
            
           // int ttt;
            
            while(k)
            {
                cn++;
                k>>=1;
                if(k%2)
                {
                    for(int i=s;i<=cn;i++)
                    {
                        //for(int ii=1;ii<=n;++ii)
                        {
                            for(int jj=1;jj<=n;++jj)
                            {
                                tmp3[1][jj]=0;
                                for(int kk=1;kk<=n;++kk)
                                {
                                    //ttt=%m;
                                    tmp3[1][jj]+=b[1][kk]*b[kk][jj];
                                    //ttt)%m;
                                }
                                tmp3[1][jj]%=m;
                            }
                            for(int jj=1;jj<=n;++jj)
                            {
                                b[1][jj]=tmp3[1][jj];
                            }
                            for(int ii=2;ii<=n;++ii)
                            {
                                for(int jj=1;jj<=n;++jj)
                                {
                                    tmp=ii+jj-1;
                                    if(tmp>n)tmp-=n;
                                    b[ii][tmp]=b[1][jj];
                                }
                            }
                        }
                        
                        
                    }
                    s=cn+1;
                    
                    //for(int ii=1;ii<=n;++ii)
                        {
                            for(int jj=1;jj<=n;++jj)
                            {
                                tmp3[1][jj]=0;
                                for(int kk=1;kk<=n;++kk)
                                { 
                                    //ttt=tmp1[ii][kk]*b[kk][jj]%m;
                                    tmp3[1][jj]+=tmp1[1][kk]*b[kk][jj];
                                }
                                tmp3[1][jj]%=m;
                            }
                        }
                    for(int jj=1;jj<=n;++jj)
                    {
                        tmp1[1][jj]=tmp3[1][jj];
                    }
                    
                    for(int ii=2;ii<=n;++ii)
                            {
                                for(int jj=1;jj<=n;++jj)
                                {
                                    tmp=ii+jj-1;
                                    if(tmp>n)tmp-=n;
                                    tmp1[ii][tmp]=tmp1[1][jj];
                                }
                            }
                   /// tmp1*=tmp2;
                   // tmp1%=c;
                }
                //k>>1;
            }
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    //ttt=%m;
                    re[i]+=tmp1[i][j]*a[j];//(ttt+re[i])%m;
                }
                re[i]%=m;
            }
            printf("%lld",re[1]);
    for(int i=2;i<=n;++i)
    {
       printf(" %lld",re[i]);
    }
    printf("\n");
    return 0;
}
