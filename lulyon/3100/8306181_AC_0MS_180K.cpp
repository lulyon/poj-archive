#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int a,b,n;
	while(1){
		scanf("%d%d",&b,&n);
		if(b==0 && n==0)break;
		
		double result = pow(b+0.0, 1.0/n);
		double f = floor(result);
		double c = ceil(result);
		double fr = pow(f,n);
		double cr = pow(c,n);
		if(b-fr<=cr-b)printf("%.0lf\n",f);
		else printf("%.0lf\n",c);
	}
	return 0;
}

