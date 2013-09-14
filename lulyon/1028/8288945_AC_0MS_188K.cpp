#include<iostream>
using namespace std;

char com[3][10] = {"VISIT", "BACK", "FORWARD"};

typedef struct INFO{
	char str[110];
}InfoType;

InfoType stack[110];

char s[110];

bool equal(char *a, char *b){
	int lena = strlen(a);
	int lenb = strlen(b);
	
	if(lena!=lenb)return 0;
	for(int i=0; i<lena; ++i){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}

void copy(char *a, char *b){
	int lenb = strlen(b);
	
	for(int i=0; i<lenb; ++i){
		a[i] = b[i];
	}
	a[lenb] = '\0';
}

int main(){
	int top=0, pointer=0;
	
	char tmp[110] = {"http://www.acm.org/"};
	copy(stack[0].str,tmp);
	
	while(1){
		scanf("%s",s);
		int index=3;
		for(int i=0; i<4; ++i){
			if(equal(com[i], s)){
				index = i;
				break;
			}
		}
		
		if(index==3){
			break;
		}
		else if(index==0){
			scanf("%s",s);
			pointer = pointer+1;
			top = pointer;
			copy(stack[pointer].str, s);
			printf("%s\n",s);
		}
		else if(index==1){
			if(pointer==0){
				printf("Ignored\n");
			}
			else{
				pointer--;
				printf("%s\n",stack[pointer].str);
			}
		}
		else if(index==2){
			if(pointer==top){
				printf("Ignored\n");
			}
			else{
				pointer++;
				printf("%s\n",stack[pointer].str);
			}
		}
	}
	return 0;
}

