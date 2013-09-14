#include <stdio.h>
#include <string.h>

#include <assert.h>

#include <algorithm>

#define MAXN 100010
#define STRLEN 200

char str[MAXN][STRLEN];

char mapTable[30];

char *list[MAXN];

void initMapTable(void)
{
	mapTable['A' - 'A'] = '2';
	mapTable['B' - 'A'] = '2';
	mapTable['C' - 'A'] = '2';
	mapTable['D' - 'A'] = '3';
	mapTable['E' - 'A'] = '3';
	mapTable['F' - 'A'] = '3';
	mapTable['G' - 'A'] = '4';
	mapTable['H' - 'A'] = '4';
	mapTable['I' - 'A'] = '4';
	mapTable['J' - 'A'] = '5';
	mapTable['K' - 'A'] = '5';
	mapTable['L' - 'A'] = '5';
	mapTable['M' - 'A'] = '6';
	mapTable['N' - 'A'] = '6';
	mapTable['O' - 'A'] = '6';
	mapTable['P' - 'A'] = '7';
	mapTable['R' - 'A'] = '7';
	mapTable['S' - 'A'] = '7';
	mapTable['T' - 'A'] = '8';
	mapTable['U' - 'A'] = '8';
	mapTable['V' - 'A'] = '8';
	mapTable['W' - 'A'] = '9';
	mapTable['X' - 'A'] = '9';
	mapTable['Y' - 'A'] = '9';
}

char queryMapTable(char key)
{
	if(key == 'Q' || key == 'Z') return 0;
	if(key <='Z' && key >= 'A')
		return mapTable[key - 'A'];
	else if(key <='9' && key >= '0')
		return key;
	else
		return 0;
}


bool cmp(char* const&a, char* const&b) 
{
	if(strcmp(a, b) < 0) return 1;
	else return 0;
}

bool printStr(char * s)
{
	int sLen = strlen(s);
	assert(sLen == 7) ;

	for(int i = 0; i < 3; ++i) {
		printf("%c", s[i]);
	}
	printf("-");
	for(int i = 3; i<sLen; ++i) {
		printf("%c", s[i]);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);

	char tempStr[STRLEN];

	initMapTable();
	for(int i = 0; i < n; ++i) {
		scanf("%s", tempStr);
		int incre = 0;
		for(int j = 0; tempStr[j] != '\0'; ++j) {
			char value = queryMapTable(tempStr[j]);
			if(value != 0)
				str[i][incre++] = value;
		}
		str[i][incre] = '\0';
		list[i] = str[i];
	}

/****************************************************
 * * print str
 * *
	for(int i = 0; i < n; ++i) {
		printf("%s\n", str[i]);
	}
 * *
****************************************************/


	std::sort(list, list + n, cmp);

	int dupFlag = 0;
	int counter = 1;
	for(int i = 1; i < n; ++i) {
		if(strcmp(list[i-1], list[i]) == 0) {
			dupFlag = 1;
			counter++;
		}
		else {
			if(counter > 1) {
				printStr(list[i-1]);
				printf(" %d\n", counter);
				counter = 1;
			}
		} 
	}
	if(counter > 1) {
		printStr(list[n-1]);
		printf(" %d\n", counter);
	}

	if(dupFlag == 0) printf("No duplicates.\n");

	return 0;
}
