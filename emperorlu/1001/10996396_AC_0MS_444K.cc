/*************************************************************************
  > File Name: 1001.c
  > Author: luliang
  > Mail: lulyon@126.com 
  > Created Time: 2012年11月07日 星期三 21时24分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRLEN 20
char str[STRLEN];
int num[STRLEN];
int tempAdd[STRLEN * 1000];
int tempResult[STRLEN * 1000];
int result[STRLEN * 1000];


void printResult(int *array, int arrayLen, int expCount)
{


		int allZeroFlag = 0;
		for(int i = 0; i < arrayLen; ++i) {
			if(array[i] != 0) {
				allZeroFlag = 1;
				break;
			}
		}

		if(allZeroFlag == 0) {
			printf("0\n");
			return;
		}
	int dotPos = arrayLen - expCount;
	if(dotPos <= 0) {
			printf(".");
			for(int i = dotPos; i < 0; ++i) {
				printf("0");
			}
			int firstNZeroIndex = -1;
			for(int i = arrayLen - 1; i >= 0; --i) {
				if(array[i] != 0) {
					firstNZeroIndex = i;
					break;
				}
			}
			if(firstNZeroIndex == -1) exit(-1);
			for(int i = 0; i <= firstNZeroIndex; ++i) {
				printf("%d", array[i]);
			}
			printf("\n");
	}
	else {
		int zeroFlag = 0;
		for(int i = 0; i < dotPos; ++i) {
			if(array[i] != 0) {
				zeroFlag = 1;
				break;
			}
		}

		if(zeroFlag == 0) {
			printf(".");
			int firstNZeroIndex = -1;
			for(int i = arrayLen - 1; i >= dotPos; --i) {
				if(array[i] != 0) {
					firstNZeroIndex = i;
					break;
				}
			}
			if(firstNZeroIndex == -1) exit(-1);
			for(int i = dotPos; i <= firstNZeroIndex; ++i) {
				printf("%d", array[i]);
			}
			printf("\n");
		}
		else {
			int firstNZeroIndex, lastNZeroIndex;
			firstNZeroIndex = lastNZeroIndex = -1;

			for(int i = 0; i < dotPos; ++i) {
				if(array[i] != 0) {
					firstNZeroIndex = i;
					break;
				}
			}
			if(firstNZeroIndex == -1) exit(-1);
			for(int i = firstNZeroIndex; i < dotPos; ++i) {
				printf("%d", array[i]);
			}

			int tailFlag = 0;
			for(int i = dotPos; i <= arrayLen; ++i) {
				if(array[i] != 0) {
					tailFlag = 1;
					break;
				}
			}
			if(tailFlag == 0) {
				printf("\n");
			}
			else {
				printf(".");
				for(int i = arrayLen - 1; i >= dotPos; --i) {
					if(array[i] != 0) {
						lastNZeroIndex = i;
						break;
					}
				}
				if(lastNZeroIndex == -1) exit(-1);
				for(int i = dotPos; i <= lastNZeroIndex; ++i) {
					printf("%d", array[i]);
				}
				printf("\n");
			}

		}

	}
}

void multiply(int *re, int *reLenPointer, int *aArray, int aLen, int *bArray, int bLen)
{
	for(int i = 0; i < bLen; ++i) {
		int tempAddLen = 0;
		int multiplier = bArray[i];
		int addUp = 0;
		for(int j = 0; j < aLen; ++j) {
			int singleMulNum =  addUp + multiplier * aArray[j];
			addUp = singleMulNum / 10;
			tempAdd[j] = singleMulNum % 10;
		}
		if(addUp == 0) {
			tempAddLen = aLen;
		}
		else {
			tempAdd[aLen] = addUp;
			tempAddLen = aLen + 1;
		}
		
		int addUp2 = 0;
		for(int j = 0; j < tempAddLen; ++j) {
			int singleAddNum = addUp2 + tempAdd[j] + re[i + j];
			addUp2 = singleAddNum / 10;
			re[i + j] = singleAddNum % 10;
		}

		for(int j = tempAddLen; addUp2 > 0; j++ ) {
			int singleAddNum = addUp2 + re[i + j];
			addUp2 = singleAddNum / 10;
			re[i + j] = singleAddNum % 10;
		}

	}
	if(re[aLen + bLen] == 0) {
		*reLenPointer = aLen + bLen;
	}
	else {
		*reLenPointer = aLen + bLen + 1;
	}

}

int main(void)
{
	int n;
	while(scanf("%s%d", str, &n) != EOF){
		int dotIndex = 0;
		int len = strlen(str);
		for(; dotIndex < len; dotIndex++) {
			if(str[dotIndex] == '.')break;
		}
		int expCount;
		if(dotIndex == len) expCount = 0;
		else expCount = len - dotIndex - 1;

		int totalExpCount = expCount * n;

		int numLen = 0;
		for(int i = 0; i < len; ++i){
			if(str[i] != '.') num[numLen++] = str[i] - '0';
		}

		if(n == 1) {
			printResult(num, numLen, totalExpCount);
		}
		else{
			for(int i = 0; i < numLen; ++i) {
				result[numLen -1 - i] = num[i];
			}
			int resultLen = numLen;

			for(int i = 0; i < numLen; ++i) {
				num[i] = result[i];
			}

			for(int i = 2; i <= n; ++i) {
				int tempResultLen = 0;
				memset(tempResult, 0, sizeof(int) * STRLEN * 1000);
				multiply(tempResult, &tempResultLen, result, resultLen, num, numLen);
				for(int j = 0; j < tempResultLen; ++j) {
					result[j] = tempResult[j];
				}
				resultLen = tempResultLen;
			}

			for(int j = 0; j < resultLen/2; ++j) {
				int tempSwap = result[j];
				result[j] = result[resultLen - 1 - j];
				result[resultLen - 1 - j] = tempSwap;

			}
			printResult(result, resultLen, totalExpCount);
		}

	}

	return 0;
}
