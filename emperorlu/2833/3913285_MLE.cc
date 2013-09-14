#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int tmp,n1,n2,n;
    while(1)
    {
        vector<int> a;
        scanf("%d%d%d",&n1,&n2,&n);
        if(!n1&&!n2&&!n)break;
        
        
        for(int i=0;i<n;++i)
        {
            scanf("%d",&tmp);
            a.push_back(tmp);
        }
        
        sort(a.begin(),a.end());
        long long sum=0;
        for(int i=n2;i<n-n1;++i)
        {
            sum+=a[i];
        }
        printf("%.6lf\n",sum/(double)(n-n1-n2));
    }
    return 0;
}
