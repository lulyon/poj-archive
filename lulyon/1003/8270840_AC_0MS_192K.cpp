#include<iostream>
using namespace std;
int main(){
	int i;
	double s,sum;
	while(1){
		scanf("%lf",&s);
		if(s<1e-6)break;
		sum=0;
		for(i=2;;++i){
			sum += 1.0/(double)i;
			if(sum>=s)break;
		}
		printf("%d card(s)\n",i-1);
	}
	return 0;
}

