#include<iostream>
using namespace std;
int main(){
	long l,begin,end;
	int m;
	long sum;
	while(1){
		scanf("%ld%d",&l,&m);
		if(l==0 && m==0)break;
		
		sum = l+1;
		while(m--){
			scanf("%ld %ld",&begin,&end);
			sum -= (end-begin+1);
		}
		printf("%ld\n",sum);
	}
	return 0;
}

