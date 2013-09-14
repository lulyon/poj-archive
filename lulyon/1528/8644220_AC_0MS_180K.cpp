#include<iostream>
#include<math.h>
int main(int argc, char ** argv){
	int n;
	printf("PERFECTION OUTPUT\n");
	while(1){
		scanf("%d", &n);
		if(n==0)break;
		printf("%5d  ", n);
		
		if(n==1){
			printf("DEFICIENT\n");
			continue;
		}
		
		int m = (int)sqrt((double)n);
		int sum = 1;
		for(int i=2; i<=m; ++i){
			if(n%i==0){
				int temp = n/i;
				if(temp != i){
					sum += i+temp;
				}
				else{
					sum += i;
				}
				if(sum>n)break;
			}
		}
		if(sum>n){
			printf("ABUNDANT\n");
		}
		else if(sum==n){
			printf("PERFECT\n");
		}
		else{
			printf("DEFICIENT\n");
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
