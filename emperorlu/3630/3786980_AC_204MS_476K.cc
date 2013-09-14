#include <iostream>
using namespace std;
int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
int main()
{
	int test, n, i;
	char code[10000][11];
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for(i = 0; i != n; i++)
			scanf("%s", code[i]);
		qsort(code[0], n, sizeof(code[0]), compare);
		for(i = 0; i != n - 1; i++)
		{
			int len = strlen(code[i]);
			if(strncmp(code[i], code[i+1], len) == 0)
			{
				printf("NO\n");
				break;
			}
		}
		if(i == n-1)
			printf("YES\n"); 
	}
	return 1;
}