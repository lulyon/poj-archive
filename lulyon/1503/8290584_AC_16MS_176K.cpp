#include<iostream>
using namespace std;

void Add(int *a, int lena, int *b, int lenb, int *c, int &lenc){
	int i,s=0;
	for(i=0;i<lena&&i<lenb;++i){
		c[i] = (a[i]+b[i]+s)%10;
		s = (a[i]+b[i]+s)/10;
	}
	for(;i<lena;++i){
		c[i] = (a[i]+s)%10;
		s = (a[i]+s)/10;
	}
	for(;i<lenb;++i){
		c[i] = (b[i]+s)%10;
		s = (b[i]+s)/10;
	}
	if(s==0)lenc = i;
	else{
		c[i] = s;
		lenc = i+1;
	}
}


int main(){
	int a[110];
	int b[110];
	int r[110];
	char str[110];
	
	int lena, lenb, lenr;
	lenr = 1;
	r[0] = 0;
	lena = 1;
	a[0] = 0;
	
	while(scanf("%s",str)!=EOF){
		int lenstr = strlen(str);
		for(int i=0; i<lenstr; ++i){
			b[lenstr-1-i] = str[i]-'0';
		}
		lenb = lenstr;
		
		Add(a,lena,b,lenb,r,lenr);
		for(int i=0; i<lenr; ++i){
			a[i] = r[i];
		}
		lena = lenr;
	}
	int begin;
	for(begin=lenr-1;begin>0; --begin){
		if(r[begin]!=0)break;
	}
	for(int i=begin; i>=0; --i){
		printf("%d",r[i]);
	}
	printf("\n");
	return 0;
}

