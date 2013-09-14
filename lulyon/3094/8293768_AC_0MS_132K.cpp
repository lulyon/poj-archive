#include<iostream>
using namespace std;
char str[500];
int main(){
	while(1){
		gets(str);
		if(str[0]=='#')break;
		
		int sum=0;
		for(int i=0; str[i]; ++i){
			if(str[i]!=' '){
				sum += (i+1)*(str[i]-'A'+1);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}

