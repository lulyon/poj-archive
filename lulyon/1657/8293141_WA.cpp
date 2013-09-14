#include<iostream>
using namespace std;

char s1[5],s2[5];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",s1,s2);
		int a,b;
		a = s2[0]-s1[0];
		if(a<0)a=-a;
		b = s2[1]-s1[1];
		if(b<0)b=-b;
		if(a>b)a^=b^=a^=b;
		printf("%d ",b);
		if(a==b){
			if(a==0)printf("0 ");
			else printf("1 ");
		}
		else{
			if(a==0)printf("1 ");
			else printf("2 ");
		}
		
		if(a==0){
			if(b==0)printf("0 ");
			else printf("1 ");
		}
		else{
			printf("2 ");
		}
		
		if(a==b){
			if(a==0)printf("0\n");
			else printf("1\n");
		}
		else{
			printf("Inf\n");
		}
	}
	
	
	return 0;
}

