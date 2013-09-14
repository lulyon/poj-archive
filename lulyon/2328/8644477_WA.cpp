#include<iostream>

char str[10];

int main(int argc, char ** argv){
	int n;
	while(1){
		scanf("%d", &n);
		if(n==0)break;
		
		int low, high;
		low = 0;
		high = 11;
		bool flag=0;
		while(1){
			int num;
			scanf("%d", &num);
			scanf("%s %s", str, str);
			if(str[0]=='h' && flag == 0){
				if(num<=low)flag=1;
				else high = num;
			}
			else if(str[0]=='l' && flag==0){
				if(num>=high)flag=1;
				else low = num;
			}
			else if(str[0]=='o'){
				if(num<=low || num>= high)flag=1;
				break;
			}
		}
		if(flag)printf("Stan is dishonest\n");
		else printf("Stan may be honest\n");
	}
	return 0;
}
