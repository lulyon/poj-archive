/*************************************************************************
  > File Name: 1009.cpp
  > Author: luliang
  > Mail: lulyon@126.com 
  > Created Time: 2012年11月16日 星期五 10时51分28秒
 ************************************************************************/

#include<stdio.h>
#include<algorithm>

#include<assert.h>

#define MAXPAIR 1010

typedef struct {
	int pos;
	int code;
	int length;
}pixelType;

pixelType srcimage[MAXPAIR];
pixelType dstimage[MAXPAIR * 100];

int poslist[MAXPAIR][2];

bool cmp(const pixelType &a, const pixelType &b) 
{
	if(a.pos < b.pos) return 1;
	else return 0;
}

int abs(int value)
{
	if(value < 0) return -value;
	else return value;
}

int getCode(pixelType *src, int pos, int n)
{
	for(int i = 0; i < n; ++i) {
		if(pos < src[i].pos) {
			assert(i != 0);
			return src[i-1].code;
		}
	}
	return src[n-1].code;
}

int compCode(pixelType *src, int row, int col, int width, int height, int n)
{
	int maxDiff = 0;

	int centerPos = row * width + col;
	int centerCode = getCode(src, centerPos, n);

	for(int i = row - 1; i <= row + 1; ++i) {
		for(int j = col - 1; j <= col + 1; ++j) {
			if( i >= 0 && i < height && j >= 0 && j < width) {
				int pos = i * width + j;
				int diff = getCode(src, pos, n) - centerCode;
				diff = abs(diff);
				if(maxDiff < diff) maxDiff = diff;
			}
		}
	}
	return maxDiff;
}

int main(void)
{
	int width;
	while(1) {
		scanf("%d", &width);
		printf("%d\n", width);
		if(width == 0) break;

		int n = -1;
		int totalPos = 0;
		for(int i = 0; ; ++i) {
			scanf("%d%d", &srcimage[i].code, &srcimage[i].length);
			if(srcimage[i].code == 0 && srcimage[i].length == 0) {
				n = i;
				break;
			}
			srcimage[i].pos = totalPos;
			totalPos += srcimage[i].length;
		}

		int height = totalPos / width;

		assert(totalPos % width == 0);

		int counter = 0;
		for(int i = 0; i < n; ++i) {
			int listCount = 0;

			if(i > 0) {
				int row0 = srcimage[i-1].pos / width;
				int col0 = srcimage[i-1].pos % width;

				int row1 = srcimage[i].pos / width;
				int col1 = srcimage[i].pos % width;

				if(row1 - row0 == 0) {

					poslist[listCount][0] = row1;
					poslist[listCount][1] = col1;
					listCount ++;
				}
				else if(row1 - row0 == 1) {

					poslist[listCount][0] = row1;
					poslist[listCount][1] = col1;
					listCount ++;

					poslist[listCount][0] = row1;
					poslist[listCount][1] = 0;
					listCount ++;

					poslist[listCount][0] = row0;
					poslist[listCount][1] = width - 1;
					listCount ++;
				}
				else if(row1 - row0 == 2) {

					poslist[listCount][0] = row1;
					poslist[listCount][1] = col1;
					listCount ++;

					poslist[listCount][0] = row1;
					poslist[listCount][1] = 0;
					listCount ++;

					poslist[listCount][0] = row0 + 1;
					poslist[listCount][1] = 0;
					listCount ++;

					poslist[listCount][0] = row0 + 1;
					poslist[listCount][1] = width - 1;
					listCount ++;

					poslist[listCount][0] = row0;
					poslist[listCount][1] = width - 1;
					listCount ++;

				}

				else if(row1 - row0 >= 3) {

					poslist[listCount][0] = row1;
					poslist[listCount][1] = col1;
					listCount ++;

					poslist[listCount][0] = row1;
					poslist[listCount][1] = 0;
					listCount ++;

					poslist[listCount][0] = row1 - 1;
					poslist[listCount][1] = 0;
					listCount ++;

					poslist[listCount][0] = row1 - 1;
					poslist[listCount][1] = width - 1;
					listCount ++;

					poslist[listCount][0] = row0 + 1;
					poslist[listCount][1] = 0;
					listCount ++;

					poslist[listCount][0] = row0 + 1;
					poslist[listCount][1] = width - 1;
					listCount ++;

					poslist[listCount][0] = row0;
					poslist[listCount][1] = width - 1;
					listCount ++;

				}

			}
			else {

				poslist[listCount][0] = srcimage[i].pos / width;
				poslist[listCount][1] = srcimage[i].pos % width;
				listCount ++;
			}

			for(int q = 0; q < listCount; ++q) {
				int row = poslist[q][0];
				int col = poslist[q][1];

				for(int j = row - 1; j <= row + 1; ++j) {
					for(int k = col - 1; k <= col + 1; ++k) {
						if(j >= 0 && j < height && k >= 0 && k < width) {
							int tempPos = j * width + k;
							dstimage[counter].pos = tempPos;
							dstimage[counter].code = compCode(srcimage, j, k, width, height, n);
							counter++;
						}
					}
				}

			}
		}

		while(1);
		std::sort(dstimage, dstimage + counter, cmp);

		int lastPos = 0;
		for(int i = 1; i < counter; ++i) {
			if(dstimage[i].code != dstimage[i-1].code) {
				printf("%d %d\n", dstimage[i-1].code, dstimage[i].pos - lastPos);
				lastPos = dstimage[i].pos;
			}
		}
		printf("%d %d\n", dstimage[counter-1].code, totalPos - lastPos);
		printf("0 0\n");

	}
	return 0;
}
