#include<iostream>
using namespace std;

int cnt[10010];

int prime(int a[],int n)
{
    int i,j,k,x,num,*b;
    n++;
    n/=2;
    b=(int *)malloc(sizeof(int)*(n+1)*2);
    a[0]=2;a[1]=3;num=2;
    for(i=1;i<=2*n;i++)
        b[i]=0;
    for(i=3;i<=n;i+=3)
        for(j=0;j<2;j++)
            {
            x=2*(i+j)-1;
            while(b[x]==0)
                {
                a[num++]=x;
                for(k=x;k<=2*n;k+=x)
                    b[k]=1;
                }
            }
    return num;
}


int main(){
	int a[10010],num;
	num = prime(a,10000);
	for(int i=0; i<num; ++i){
		cnt[a[i]]++;
	}
	
	for(int i=1; i<num; ++i){
		a[i] = a[i-1]+a[i];
	}
	
	for(int i=0; i<num; ++i){
		for(int j=i+1; j<num; ++j){
			if(i>0){
				if(a[j]-a[i-1]<=10000)
					cnt[a[j]-a[i-1]]++;
			}
			else{
				if(a[j]<=10000)
					cnt[a[j]]++;
			}
		}
	}
	
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		
		printf("%d\n",cnt[n]);
	}
	return 0;
}

