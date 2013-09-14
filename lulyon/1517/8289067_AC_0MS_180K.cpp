#include<iostream>
using namespace std;
int main(){
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	
	double sum = 1;
	int bottom = 1;
	for(int i=1; i<10; ++i){
		bottom = bottom * i;
		sum += 1.0/(double)bottom;
		
		if(i>2){
			printf("%d %.9lf\n",i, sum);
		}
	}
	return 0;
}

