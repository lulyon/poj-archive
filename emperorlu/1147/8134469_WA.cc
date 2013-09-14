#include<iostream>
#include<stdio.h>
using namespace std;
int cn[2];
int main(){
	int n,a;
	cn[0] = cn[1] = 0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		if(a==1)cn[1]++;
		else cn[0]++;
	}
	
	
	
	if(cn[1]){
		for(int i=0; i<cn[0]; ++i){
			printf("0 ");
		}
		for(int i=1; i<cn[1]; ++i)
			printf("1 ");
		printf("1\n");
	}
	else{
		printf("0");
		for(int i=1; i<cn[0]; ++i){
			printf(" 0");
		}
		printf("\n");
	}
	
	return 0;
}
