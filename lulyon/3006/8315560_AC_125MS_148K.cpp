#include<iostream>
#include<math.h>
using namespace std;

bool prime(int n){
	if(n==1)return 0;
	if(n==2)return 1;
	if(n%2==0)return 0;
	int sq = (int)sqrt(n+0.0);
	for(int i=3; i<=sq; i+=2){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int a,b,c;
	while(1){
		scanf("%d%d%d",&a,&b,&c);
		if(a==0 && b==0 && c==0)break;
		
		while(1){
			while(1){
				if(prime(a)){
					c--;
					break;
				}
				else{
					a+=b;
				}
			}
			if(c==0)break;
			a+=b;
		}
		printf("%d\n",a);
	}
	return 0;
}

