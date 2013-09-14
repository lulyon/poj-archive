#include<iostream>
using namespace std;

char hmn[20][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", 
"chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu",
"uayet"};

char tmn[20][10] = {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat",
"muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"
};


bool equal(char *a, char *b){
	int lena, lenb;
	lena = strlen(a);
	lenb = strlen(b);
	if(lena!=lenb)return 0;
	for(int i=0;i<lena;++i){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}

int main(){
	int t;
	scanf("%d",&t);
	printf("%d\n",t);
	char day[10],month[10];
	int year;
	while(t--){
		scanf("%s%s%d",day, month, &year);
		int end;
		for(int i=0;;++i){
			if(day[i]=='.'){
				end = i;
				break;
			}
		}
		
		int exp=1;
		int daynum=0;
		for(int i=end-1;i>=0;--i){
			daynum += exp*(day[i]-'0');
			exp *= 10;
		}
		int monthnum;
		for(int i=0;i<19;++i){
			if(equal(month, hmn[i])){
				monthnum=i;
				break;
			}
		}
		
		int totalnum,remain;
		 totalnum = year*365+monthnum*20+daynum;
		 remain = totalnum%260;
		 year = totalnum/260;
		 
		 printf("%d %s %d\n", remain%13+1, tmn[remain%20], year);
	}
	return 0;
}

