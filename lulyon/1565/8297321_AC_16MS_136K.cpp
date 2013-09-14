#include<iostream>
using namespace std;
char s[110];
int main(){
	while(1){
		scanf("%s",s);
		int n = strlen(s);
		if(n==1 && s[0]=='0')break;
		
		int exp=2,sum=0;
		for(int i=0; i<n; ++i){
			sum += (exp-1)*(s[n-1-i]-'0');
			exp*=2;
		}
		printf("%d\n",sum);
	}
	return 0;
}

