#include<iostream>

int tmp[1000000];
int lentmp;

int tmp2[1000000];
int lentmp2;

int tmp3[1000000];
int lentmp3;

int num1[100];
int len1;

int num2[100];
int len2;

char str[100];

int result[1000000];
int lenr;



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


void Mul(int *a,int lena,int *b,int lenb, int *c, int &lenc){
	lenc = 1;
	c[0] = 0;
	
	for(int i=0;i<lenb;++i){
		
		for(int k=0;k<i;++k){
			tmp[k]=0;
		}
		int s=0;
		int j;
		for(j=0;j<lena;++j){
			tmp[i+j] = (a[j]*b[i]+s)%10;
			s = (a[j]*b[i]+s)/10;
		}
		if(s==0)lentmp = i+j;
		else{
			tmp[i+j]=s;
			lentmp = i+j+1;
		}

		Add(c,lenc, tmp, lentmp, tmp2, lentmp2);
		
		for(int k=0; k<lentmp2; ++k){
			c[k] = tmp2[k];
		}
		lenc = lentmp2;
	}
}

int main()
{
	scanf("%s",str);
	len1 = strlen(str);
	for(int i = len1-1, j=0; j<len1; i--, j++){
		num1[j] = str[i]-'0';
	}

	scanf("%s",str);
	len2 = strlen(str);
	for(int i = len2-1, j=0; j<len2; i--, j++){
		num2[j] = str[i]-'0';
	}
	Mul(num1, len1, num2, len2, result, lenr);
	int pos=-1;
	for(int i = lenr-1; i>=0; i--){
		if(result[i]!=0){
			pos = i;
			break;
		}
	}
	for(int i=pos; i>=0; i--){
		printf("%d", result[i]);
	}
	printf("\n");
}