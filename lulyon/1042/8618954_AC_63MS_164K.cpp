#include <iostream>
#include <queue>
#define MAXN 26
using namespace std;

int main()
{
    int n, h, tmp, sum, max;
    int i, j, k, p;
    int F[MAXN], f[MAXN], d[MAXN], t[MAXN] = {0}, ans[MAXN], ANS[MAXN];
    
    while (scanf("%d", &n) != EOF && n)
    {
        scanf("%d", &h);
        h *= 12;
        for (i = 0; i < n; i++)
            scanf("%d", &F[i]);
        for (i = 0; i < n; i++)
            scanf("%d", &d[i]);
        for (i = 1; i < n; i++)
        {
            scanf("%d", &tmp);
            t[i] = tmp + t[i-1];
        }
        memset(ANS, 0, sizeof(ANS));
        for (max = 0, i = 1; i <= n; i++)
        {
            memset(ans, 0, sizeof(ans));
            for (j = 0; j < i; j++)
                f[j] = F[j];
            for (j = 0, sum = 0; j < h - t[i-1]; j++)
            {
                for (p = 0, k = 1; k < i; k++)
                    if (f[k] > f[p])
                        p = k;
                if (f[p] <= 0)
                {
                    ans[0] += h - t[i-1] - j;
                    break;
                }
                sum += f[p];
                f[p] -= d[p];
                ans[p]++;
            }
            if (sum > max)
            {
                max = sum;
                memcpy(ANS, ans, sizeof(ans));
            }
            if (sum == max)
            {
                for (j = 0; j < i; j++)
                    if (ans[j] != ANS[j])
                        break;
                if (ans[j] > ANS[j])
                    memcpy(ANS, ans, sizeof(ans));
            }
        }
        for (i = 0; i < n - 1; i++)
            printf("%d, ", ANS[i]*5);
        printf("%d\nNumber of fish expected: %d\n\n", ANS[n-1]*5, max);
    }
    return 0;
}
