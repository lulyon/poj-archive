#include<iostream>
using namespace std;

char str[10000];

int compute(int n){
	int sum=0;
	while(n!=0){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main(){
	int n;
	while(1){
		scanf("%s",str);
		n=0;
		for(int i=0; str[i]; ++i){
			n += str[i]-'0';
		}
		if(n==0)break;
		
		while(1){
			if(n<10)break;
			n=compute(n);
		}
		printf("%d\n",n);
	}
	return 0;
}

