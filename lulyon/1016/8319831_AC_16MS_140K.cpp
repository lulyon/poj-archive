#include<iostream>
using namespace std;

char a[16][100];
char stack[100];

int main(){
	while(1){
		scanf("%s",a[0]);
		if(a[0][0]=='-')break;
		
		int i;
		int sum[10];
		for(i=1; i<16; ++i){
			for(int j=0; j<10; ++j){
				sum[j]=0;
			}
			int length = strlen(a[i-1]);
			for(int j=0; j<length; ++j){
				sum[a[i-1][j]-'0']++;
			}
			int top=0;
			for(int j=0; j<10; ++j){
				if(sum[j]!=0){
					int sp=0;
					while(sum[j]!=0){
						stack[sp++] = sum[j]%10 + '0';
						sum[j]/=10;
					}
					for(int k=sp-1; k>=0; --k){
						a[i][top++]=stack[k];
					}
					a[i][top++]= j + '0';
				}
			}
			a[i][top]=0;
			
			int index = i;
			for(int j=0; j<i; ++j){
				if(strcmp(a[j],a[i])==0){
					index = j;
					break;
				}
			}
			if(index!=i){
				if(index==0){
					if(i==1)printf("%s is self-inventorying\n",a[0]);
					else printf("%s enters an inventory loop of length %d\n",a[0],i);
				}
				else{
					if(index+1==i){
						printf("%s is self-inventorying after %d steps\n", a[0], index);
					}
					else{
						printf("%s enters an inventory loop of length %d\n",a[0], i-index);
					}
				}
				break;
			}
		}
		if(i==16)printf("%s can not be classified after 15 iterations\n",a[0]);
	}
	return 0;
}

