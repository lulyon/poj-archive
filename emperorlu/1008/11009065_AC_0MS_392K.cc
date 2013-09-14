#include<stdio.h>
#include<string.h>

#include<assert.h>

#define MonthNameLen 20
#define MonthNum 20

char HaabMonth[MonthNum][MonthNameLen] = \
{ "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", 
	"yax", "zac","ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };

char TzolkinMonth[MonthNum][MonthNameLen] = \
{ "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", 
		"chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab",	"canac", "ahau" };

int compTheDay(int day, char *month, int year)
{
	int monthNum = -1;
	for(int i = 0; i < 19; ++i) {
		if(strcmp(month, HaabMonth[i]) == 0) {
			monthNum = i;
			break;
		}
	}
	assert(monthNum != -1);

	int order = year * 365 + monthNum * 20 + day;
	return order;
}


void compDate(int order, int &num, char *str, int &year)
{
	year = order / 260;
	int remainder = order % 260;
	num = remainder % 13 + 1;
	strcpy(str, TzolkinMonth[remainder % 20]);
}

int main(void) 
{
	int n;
	scanf("%d", &n);

	int Number;
	char NameOfTheDay[MonthNameLen];
	int Year;

	printf("%d\n", n);
	for(int i = 1; i <= n; ++i) {
		double tempNum;
		scanf("%lf%s%d", &tempNum, NameOfTheDay, &Year);
		Number = (int)tempNum;

		int order = compTheDay(Number, NameOfTheDay, Year);
		compDate(order, Number, NameOfTheDay, Year);

		printf("%d %s %d\n", Number, NameOfTheDay, Year);
	}
	return 0;
}
