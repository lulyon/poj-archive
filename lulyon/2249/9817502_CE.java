#include<stdio.h>

int main() {
                int n, m;
                while (1){
                        scanf("%d%d", &n, &m);

                        if (n == 0 && m == 0)
                                break;
                        if (m == 0) {
                                printf("0\n");
                                continue;
                        }

                        double rs = 1.0;
                        int i, j;
                        for (i = 1, j = n - m + 1; i <= m && j <= n;) {
                                if (rs >= 1.0) {
                                        rs = rs / i;
                                        ++i;
                                } else {
                                        rs = rs * j;
                                        ++j;
                                }
                        }

                        while (i <= m) {
                                rs = rs / i;
                                ++i;
                        }

                        while (j <= n) {
                                rs = rs * j;
                                ++j;
                        }
                        printf("%d\n", (int)rs);
                }
        }
"temp.c" 39L, 501C                                                                                         15,4-25       Top
