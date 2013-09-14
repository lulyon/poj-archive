#include<iostream>
using namespace std;
int a, b, n, m, r;
int board[100 + 10][100 + 10], que[100 + 10];

const int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct loc_type
{
    int x, y;
}loc[1100];
int main()
{
    int  i, j, x, y, k, t;
    char c;
    bool flag;
    scanf("%d",&r);
    while (r--)
    {
        scanf("%d%d%d%d", &b, &a, &n, &m);
        memset(board, -1, sizeof(board));
        for (i = 0; i < n; i ++)
        {
            scanf("%d%d %c\n", &y, &x, &c);
            x = a - x;
            y --;
            loc[i].x = x;
            loc[i].y = y;
            board[x][y] = i;
            switch (c)
            {
                case 'E' :
                    que[i] = 0;
                    break;
                case 'S' :
                    que[i] = 1;
                    break;
                case 'W' :
                    que[i] = 2;
                    break;
                case 'N' :
                    que[i] = 3;
                    break;
            }
        }
        flag = true;
        for (i = 0; i < m; i ++)
        {
            scanf("%d %c %d\n", &k, &c, &t);
            if (! flag)
                continue;
            k --;
            switch (c)
            {
                case 'L' :
                    que[k] = (que[k] + 4 - (t % 4)) % 4;
                    break;
                case 'R' :
                    que[k] = (que[k] + (t % 4)) % 4;
                    break;
                case 'F' :
                    board[loc[k].x][loc[k].y] = -1;
                    x = loc[k].x;
                    y = loc[k].y;
                    for (j = 0; j < t; j ++)
                    {
                        x += move[que[k]][0];
                        y += move[que[k]][1];
                        if (x >= a || x < 0 || y >= b || y < 0)
                        {
                            printf("Robot %d crashes into the wall\n", k + 1);
                            flag = false;
                            break;
                        }
                        else
                            if (board[x][y] != -1)
                            {
                                printf("Robot %d crashes into robot %d\n",k+1,board[x][y]+1);
                                flag = false;
                                break;
                            }
                    }
                    if (flag)
                    {
                        loc[k].x = x;
                        loc[k].y = y;
                        board[x][y] = k;
                    }
                    break;
            }
        }
        if (flag)
            printf("OK\n");
    }
    return 0;
}
