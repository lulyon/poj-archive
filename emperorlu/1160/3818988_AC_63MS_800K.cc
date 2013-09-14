#include<iostream>
using namespace std;
const int maxn = 310;
const int maxint = INT_MAX;
int n, p;

int min_cost[maxn][maxn];
int f[maxn][maxn];
int a[maxn];

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            min_cost[i][j] = 0;
            int mid = (i + j) / 2;
            for (int k = i; k <= mid; k++)
                min_cost[i][j] += a[mid] - a[k];
            for (int k = mid + 1; k <= j; k++)
                min_cost[i][j] += a[k] - a[mid];
        }

    for (int i = 0; i <= p; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = maxint;
    
    f[0][0] = 0;
    int tmp;
    for (int i = 0; i <= p; i++)
        for (int j = 0; j <= n; j++) if (f[i][j] < maxint)
        {
            for (int k = 1; j + k <= n; k++)
            {
                tmp = f[i][j] + min_cost[j + 1][j + k];
                if(f[i + 1][j + k] > tmp)f[i + 1][j + k] = tmp;   
            }
        }
    printf("%d\n", f[p][n]);
    return 0;
}
