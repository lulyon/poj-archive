#include<iostream>
using namespace std;
int main(){
	int i;
	double a[5];
	for(i=1; i<=3; ++i){
		scanf("%lf",&a[i]);
	}
	for(i=1; i<=3; ++i){
		if(a[i]<=168.0){
			printf("CRASH %g\n",a[i]);
			break;
		}
	}
	if(i==4)printf("NO CRASH\n");
	system("pause");
	return 0;
}

