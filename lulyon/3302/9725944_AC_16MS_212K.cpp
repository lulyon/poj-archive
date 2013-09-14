#include<iostream>
using namespace std;
const int maxn = 110;
char s1[maxn], s2[maxn];
int dp[maxn][maxn];

int lcs(int len1, int len2)
{
    for(int i=0; i<=0; ++i){
        for(int j=0; j<len2; ++j){
            if(j==0){
                if(s1[i] != s2[j])dp[i][j] = 0;
                else dp[i][j] = 1;
            }
            else{
                if(s1[i] != s2[j])dp[i][j] = dp[i][j-1];
                else dp[i][j]=1;
            }
        }
    }

    for(int i=1; i<len1; ++i){
        for(int j=0; j<len2; ++j){
            if(j==0){
                if(s1[i] != s2[j])dp[i][j] = dp[i-1][j];
                else dp[i][j] = 1;
            }
            else{
                if(s1[i] != s2[j])dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                else dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
    }

    return dp[len1-1][len2-1];
}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%s%s", s1, s2);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        if(len1<len2){
            printf("NO\n");
            continue;
        }
        if(lcs(len1, len2)==len2){
            printf("YES\n");
        }
        else{
            for(int i=0, j=len2-1; i<j; ++i, --j){
                char tmp;
                tmp = s2[i];
                s2[i] = s2[j];
                s2[j] = tmp;
            }
            if(lcs(len1, len2)==len2){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
