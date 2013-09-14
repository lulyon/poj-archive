#include<iostream>
#include<math.h>
#define PI 3.1415926

double R, r;
int n;

int main(){
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; ++i){
		scanf("%lf %d", &R, &n);
		double con = sin(PI/n);
		printf("Scenario #%d:\n", i);
		printf("%.3lf\n\n", con*R/(con+1));
	}
	return 0;
}
