#include <iostream>
#include <algorithm>

char str[10][10];

typedef struct{
	int cubic;
	char *str;
}InfoType;

InfoType Info[10];

bool cmp(const InfoType &a, const InfoType &b){
	if(a.cubic <= b.cubic)return 1;
	else return 0;
}

int main(){
	int n;
	while(1){
		scanf("%d", &n);
		if(n==-1)break;

		int a,b,c;
		for(int i=0; i<n; ++i){
			scanf("%d%d%d %s", &a, &b, &c, str[i]);
			Info[i].cubic = a * b * c;
			Info[i].str = str[i];
		}

		std::sort(Info, Info+n, cmp);
		printf("%s took clay from %s.\n", Info[n-1].str, Info[0].str);
	}
	return 0;
}
