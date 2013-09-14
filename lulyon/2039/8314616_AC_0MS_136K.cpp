#include<iostream>
using namespace std;

char str[250];

char a[25][25];

int main(){
	int column, row;
	while(1){
		scanf("%d",&column);
		if(column==0)break;
		
		scanf("%s",str);
		int length = strlen(str);
		row = (length+column-1)/column;
		int k=0;
		for(int i=0; i<row; ++i){
			if(i%2==0){
				for(int j=0; j<column; ++j){
					if(k<length){
						a[i][j] = str[k++];
					}
					else{
						a[i][j] = 'x';
					}
				}
			}
			else{
				for(int j=column-1; j>=0; --j){
					if(k<length){
						a[i][j] = str[k++];
					}
					else{
						a[i][j] = 'x';
					}
				}
			}
			
		}
		for(int j=0; j<column; ++j){
			for(int i=0; i<row; ++i){
				printf("%c",a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}

