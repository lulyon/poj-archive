#include<iostream>

char str[1010];
int count[1010];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", str);
		count[0]=1;
		int i;
		for(i=1; str[i]; ++i){
			if(str[i]!=str[i-1]){
				count[i] = 1;
				printf("%d", count[i-1]);
				printf("%c", str[i-1]);
			}
			else{
				count[i] = count[i-1]+1;
			}
		}
		printf("%d", count[i-1]);
		printf("%c\n", str[i-1]);
	}
	return 0;
}
