#include <stdio.h>

int table[5][5]=
{
	5,-1,-2,-1,-3,
	-1,5,-3,-2,-4,
	-2,-3,5,-2,-2,
	-1,-2,-2,5,-1,
	-3,-4,-2,-1,0
};

int score[105][105];

void ctoi(char *s,int n)
{
	for(int i=0;i<n;i++)
	{
		switch(s[i])
		{
		case 'A':
			s[i]='0';
			break;
		case 'C':
			s[i]='1';
			break;
		case 'G':
			s[i]='2';
			break;
		case 'T':
			s[i]='3';
			break;
		case '-':
			s[i]='4';
			break;
		}
	}
}

int dp(int lena,int lenb,char *s1,char *s2)
{
	ctoi(s1,lena);
	ctoi(s2,lenb);
	score[0][0]=0;
	for(int i=1;i<=lena;i++)
		score[i][0]=score[i-1][0]+table[s1[i-1]-'0'][4];
	for(int i=1;i<=lenb;i++)
		score[0][i]=score[0][i-1]+table[4][s2[i-1]-'0'];
	for(int i=1;i<=lena;i++)//从1开始 <=len
		for(int j=1;j<=lenb;j++)
		{
			score[i][j]=score[i-1][j-1]+table[s1[i-1]-'0'][s2[j-1]-'0'];
			if(score[i][j]<score[i-1][j]+table[s1[i-1]-'0'][4])
				score[i][j]=score[i-1][j]+table[s1[i-1]-'0'][4];
			if(score[i][j]<score[i][j-1]+table[4][s2[j-1]-'0'])
				score[i][j]=score[i][j-1]+table[4][s2[j-1]-'0'];
		}
	return score[lena][lenb];
}

int main()
{
	int cases,lena,lenb;
	char s1[105],s2[105];
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d%s%d%s",&lena,s1,&lenb,s2);
		printf("%d\n",dp(lena,lenb,s1,s2));
	}
	return 0;
}

