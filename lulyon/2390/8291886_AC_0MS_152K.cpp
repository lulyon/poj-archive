#include<iostream>
using namespace std;
int main(){
	double rate,money;
	int year;
	scanf("%lf%lf%d",&rate, &money, &year);
	
	for(int i=1; i<=year; ++i){
		money = money * (1+rate/100);
	}
	printf("%d\n",(int)money);
	return 0;
}

