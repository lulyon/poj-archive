#include<iostream>
using namespace std;
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		int butt,sum;
		sum = n;
		butt = n;
		while(butt>=k){
			sum += butt/k;
			butt = butt/k + butt%k;
		}
		printf("%d\n",sum);
	}
	return 0;
}

