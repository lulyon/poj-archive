#include<iostream>
using namespace std;
char str[1000010];
int main(){
	while(1){
		scanf("%s",str);
		if(str[0]=='.')break;
		int n,length = strlen(str);
		for(int i=length; i>0; --i){
			if(length%i)continue;
			n=length/i;
			bool success=1;
			for(int j=0; j<n; ++j){
				for(int k=j+n; k<length; k+=n){
					if(str[j]!=str[k]){
						success=0;
						goto leap;
					}
				}
			}
			leap:;
			if(success){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}

