#include<iostream>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int sum;
        int min,max;
        int tmp;
        scanf("%d",&tmp);
        sum=max=min=tmp;
        for(int i=1;i<n;++i)
        {
            scanf("%d",&tmp);
            sum+=tmp;
            if(min>tmp)min=tmp;
            if(max<tmp)max=tmp;
        }
        sum-=min+max;
        printf("%d\n",sum/(n-2));
    }
    return 0;
}
