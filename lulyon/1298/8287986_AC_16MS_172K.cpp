#include<iostream>
using namespace std;

char map[3][20] = {"START", "END", "ENDOFINPUT"};
char str[10];

bool equal(char *a, char *b){
	int lena = strlen(a);
	int lenb = strlen(b);
	
	if(lena!=lenb)return 0;
	for(int i=0; i<lena; ++i){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}

int main(){
	char c;
	while(1){
		gets(str);
		//getchar();
		if(equal(str, map[2]))break;
		while(1){
			c = getchar();
			if(c=='\n'){
				printf("\n");
				break;
			}
			if(c>='A' && c<='Z'){
				c = c - 5;
				if(c<'A')c=c+26;
			}
			printf("%c",c);
		}
		gets(str);
		//getchar();
	}
	return 0;
}

