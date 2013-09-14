#include<iostream>

char str[20];

int main(){
	scanf("%s", str);
	int pos, sum=0;
	for(int i=0, j=10; i<10; ++i, --j){
		if(str[i]=='?'){
			pos = j;
		}
		else if(str[i]=='X'){
			sum += j*10;
		}
		else{
			sum += j*(str[i]-'0');
		}
	}
	bool flag = 0;
	for(int i=0; i<=10; ++i){
		if((sum+i*pos)%11==0){
			flag = 1;
			if(i==10){
				if(pos==1)
					printf("X\n");
				else
					flag=0;
			}
			else{
				printf("%d\n", i);
			}
			break;
		}
	}
	if(flag==0){
		printf("-1\n");
	}
	return 0;
}
