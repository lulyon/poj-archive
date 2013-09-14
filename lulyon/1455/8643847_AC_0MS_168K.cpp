// (n/2-1)*(n/2)/2 * 2
// (n/2-1)*(n/2)/2 + ((n-n/2)-1)*(n-n/2)/2


#include<iostream>

int main()
{
	int n, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n%2==0)printf("%d\n", (n/2-1)*(n/2));
		else printf("%d\n", (n/2-1)*(n/2)/2 + ((n-n/2)-1)*(n-n/2)/2 );
	}
	return 0;
}
