#include<iostream>
using namespace std;

char key[50];

int main(){
	scanf("%s",key);
	getchar();
	char c;
	while(scanf("%c",&c)!=EOF){
		if(c>='A' && c<='Z'){
			printf("%c",key[c-'A']-32);
		}
		else if(c>='a' && c<='z'){
			printf("%c",key[c-'a']);
		}
		else{
			printf("%c",c);
		}
	}
	return 0;
}

