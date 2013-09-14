#include <cstdio>
#include <cstring>
int n,i,j,k,tmp,best,nbest,t1,t2;
int a[110][110],num[110];
bool flag;
int main() {
    while (scanf("%d",&n),n) {
        memset(a,0x7f,sizeof(a));
        for (i=1;i<=n;i++) {
            scanf("%d",&num[i]);
            for (j=1;j<=num[i];j++) {
                scanf("%d%d",&t1,&t2);
                a[i][t1]=t2;
            }
        }
        for (i=1;i<=n;i++) a[i][i]=0;
        for (k=1;k<=n;k++)
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++)
                    if (a[i][k]!=0x7f7f7f7f && a[k][j]!=0x7f7f7f7f) a[i][j]<?=a[i][k]+a[k][j];
        for (best=0x7fffffff,i=1;i<=n;i++) {
            flag=false;
            for (tmp=0,j=1;j<=n;j++) {
                tmp>?=a[i][j];
                if (a[i][j]==0x7f7f7f7f) {
                    flag=true;
                    break;
                }
            }
            if (!flag) {
                if (tmp<best) {
                    best=tmp;
                    nbest=i;
                }
            }
        }
        if (best==0x7fffffff) printf("disjoint\n");
        else printf("%d %d\n",nbest,best);
    }
    return 0;
}