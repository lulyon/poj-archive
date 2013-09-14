#include<iostream>
using namespace std;

char str[10];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		
		int length = strlen(str);
		int mid;
		for(int i=0; i<length; ++i){
			if(str[i]==':'){
				mid=i;
				break;
			}
		}
		int exp=1;
		int hour=0;
		for(int i=mid-1; i>=0; --i){
			hour += exp*(str[i]-'0');
			exp*=10;
		}
		exp=1;
		int minite=0;
		for(int i=length-1; i>mid; --i){
			minite += exp*(str[i]-'0');
			exp*=10;
		}
		if(minite!=0)printf("0\n");
		else{
			hour+=12;
			if(hour>24)hour-=24;
			printf("%d\n",hour);
		}
	}
	return 0;
}

