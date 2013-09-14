#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		
		double v,t;
		double mint = 100000;
		while(n--){
			scanf("%lf%lf",&v,&t);
			if(t<0)continue;
			
			if(mint>4500*3.6/v+t)
				mint = 4500*3.6/v+t;
		}
		printf("%.0lf\n",ceil(mint));
	}
	return 0;
}

