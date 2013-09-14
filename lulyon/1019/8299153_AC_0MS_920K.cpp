#include<iostream>
using namespace std;

long long length[50010],sum[50010];

int stack[10];

int main(){
	length[0]=0;
	sum[0]=0;
	int inc=1;
	for(int i=1; i<50000; ++i){
		length[i] = length[i-1] + inc;
		sum[i] = sum[i-1] + length[i];
		if(i==9||i==99||i==999||i==9999){
			inc++;
		}
	}
	
	int t;
	scanf("%d",&t);
	
	while(t--){
		int m;
		scanf("%d",&m);
		int i=0;
		if(m>sum[19999])i=9999;
		else if(m>sum[999])i=999;
		else if(m>sum[99])i=99;
		else if(m>sum[9])i=9;
		
		while(m>sum[i])++i;
		m-= sum[i-1];
		
		i=0;
		if(m>length[9999])i=9999;
		else if(m>length[999])i=999;
		else if(m>length[99])i=99;
		else if(m>length[9])i=9;
		while(m>length[i])++i;
		m -= length[i-1];
		
		int top=0;
		while(i!=0){
			stack[top++]=i%10;
			i/=10;
		}
		printf("%d\n",stack[top-m]);
	}
	return 0;
}

