#include<iostream>
using namespace std;
int main(){
	char s1[110],s2[110];
	
	scanf("%s%s",s1,s2);
	int sum1,sum2;
	sum1=sum2=0;
	for(int i=0; s1[i]; ++i){
		sum1 += (s1[i]-'0');
	}

	for(int i=0; s2[i]; ++i){
		sum2 += (s2[i]-'0');
	}
	printf("%d\n",sum1*sum2);
	return 0;
}

