#include<iostream>
using namespace std;

const int maxn = 2000;
int x[maxn];

void next_turn(int n)
{
    int i;
    int min_suffix = INT_MAX;
    int min_index = -1;
    for(i=n-1; i>0; --i){
        if(x[i] < x[i+1])break;
    }
    if(i==0){
        for(int i=1; i<=n; ++i){
            x[i] = i;
        }
        return;
    }

    for(int j=i+1; j<=n; ++j){
        if(x[j]>x[i] && x[j]<min_suffix){
            min_suffix = x[j];
            min_index = j;
        }
    }
    //swap x[i], x[min_index];
    {
        int tmp = x[i];
        x[i] = x[min_index];
        x[min_index] = tmp;
    }

    //insert_sort x[i+1...n]
    {
        for(int j=i+2; j<=n; ++j){
            int k;
            for(k=j-1; k>=i+1; --k){
                if(x[j]>x[k])break;
            }
            
            int tmp = x[j];
            for(int l=j-1; l>k; --l){
                x[l+1] = x[l];
            }
            x[k+1] = tmp;
        }
    }

}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d%d", &n, &k);

        for(int i=1; i<=n; ++i){
            scanf("%d", &x[i]);
        }

        for(int i=1; i<=k; ++i){
            next_turn(n);
        }
        printf("%d", x[1]);
        for(int i=2; i<=n; ++i){
            printf(" %d", x[i]);
        }
        printf("\n");
    }
    return 0;
}
