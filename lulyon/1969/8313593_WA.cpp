#include<iostream>
#include<math.h>
using namespace std;
int main(){
	long m;
	scanf("%ld",&m);
	double tmp = sqrt(2.0*m);
	int begin = (int)floor(tmp)-1;
	int end = (int)ceil(tmp)+1;
	
	printf("TERM %d IS ",m);
	for(int n=begin; n<=end; ++n){
		if(m>n*(n-1)/2 && m<=n*(n+1)/2){
			m-=n*(n-1)/2;
			if(n%2==1){
				printf("%d/%d\n", n+1-m, m);
			}
			else{
				printf("%d/%d\n", m, n+1-m);
			}
			break;
		}
	}
	//system("pause");
	return 0;
}

