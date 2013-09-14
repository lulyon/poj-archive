#include<iostream>
using namespace std;
int n, m;
int que[110][1100],sum[110],t[110],a[1100];
bool  could[1100];
int main()
{
    int  i, j, k, x, y, total, s1, s2, ans;
    char c;
    bool flag;
    while(scanf("%d%d", &n, &m) != -1)
    {
        memset(could, true, sizeof(could));
        total = 0;
        for (i = 0; i < m; i ++)
        {
            scanf("%d", &sum[total]);
            for (j = 0; j < 2 * sum[total]; j ++)
            {
                scanf("%d", &que[total][j]);
                que[total][j] --;
            }
            scanf("\n%c", &c);
            if (c == '=')
                t[total] = 0;
            else
                if (c == '>')
                    t[total] = -1;
                else
                    t[total] = 1;
            if (t[total] == 0)
            {
                for (j = 0; j < 2 * sum[total]; j ++)
                    could[que[total][j]] = false;
                total --;
            }
            total ++;
        }
        ans = 0;
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; i ++)
            if (could[i])
            {
                for (x = -1; x < 2; x += 2)
                {
                    a[i] = x;
                    flag = true;
                    for (j = 0; j < total; j ++)
                    {
                        s1 = s2 = 0;
                        for (k = 0; k < sum[j]; k ++)
                        {
                            s1 += a[que[j][k]];
                            s2 += a[que[j][sum[j] + k]];
                        }
                        if (s1 + t[j] != s2)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        if (ans == 0)
                            ans = i + 1;
                        else
                            ans = -1;
                        break;
                    }
                }
                a[i] = 0;
                if (ans == -1)
                    break;
            }
        if (ans == -1)
            ans ++;
        printf("%d\n", ans);
    }
}