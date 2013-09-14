#include<iostream>
using namespace std;

const int maxn =  1000000;

bool b[maxn+maxn];
int a[maxn];

int prime(int a[],bool b[],int n)
{
    int i,j,k,x,num;
    n++;
    n/=2;
    //b=(int *)malloc(sizeof(int)*(n+1)*2);
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
	int num = prime(a, b, maxn);
	for(int i=1;i<=maxn;i++)
        b[i]=0;
	for(int i=0; i<num; ++i){
		b[a[i]]=1;
	}
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		
		for(int i=0; i<num; ++i){
			if(b[n-a[i]]){
				printf("%d = %d + %d\n", n, a[i], n-a[i]);
				break;
			}
		}
	}
	return 0;
}


