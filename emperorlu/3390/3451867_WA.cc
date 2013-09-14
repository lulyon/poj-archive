#include <iostream>
using namespace std;
 
int main()
{
	int C, M, N;
	int len[10000], dp[10000];
	int ans;
	
	scanf("%d", &C);
	while (C--)
	{
		scanf("%d %d", &M, &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &len[i]);
		
		dp[0] = (M-len[0])*(M-len[0]);
		
		for (int i = 1; i < N; i++)
		{
			int temp = 0;
			
			temp += len[0];
			for (int j = 1; j <= i; j++)
				temp += len[j] + 1;
			if (temp <= M)
				dp[i] = (M-temp)*(M-temp);
			else
				dp[i] = 99999999;
			
			temp = 0;
			for (int j = 1; i-j >= 0; j++)
			{
				if (temp != 0)
					temp++;
				temp += len[i-j+1];
				if (temp > M)
					break;
				
				if (dp[i-j] + (M-temp)*(M-temp) < dp[i])
				{
					dp[i] = dp[i-j] + (M-temp)*(M-temp);
					break;
				}
			}
		}
		
		ans = dp[N-1];
		
		printf("%d\n", ans);
	}
	
	return 0;
}
