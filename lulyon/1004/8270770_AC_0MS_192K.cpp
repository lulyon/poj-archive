#include<iostream>
using namespace std;
int main(){
	double a,sum=0;
	for(int i=0;i<12;i++){
		scanf("%lf",&a);
		sum += a;
	}
	sum /= 12;
	printf("$%.2lf\n",sum);
	return 0;
}
