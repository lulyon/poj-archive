#include<iostream.h>
#include<map>
using namespace std;
string str;
map<string,int> mp;
map<string,int>::iterator iter,ed;
int main()
{
    int n=0;
    while(getline(cin,str))
    {
        mp[str]++;
        ++n;
    }
    iter = mp.begin();
    ed = mp.end();
    
    while(iter!=ed)
    {    
        cout<<iter->first;
        printf(" %.4lf\n",100.000000*(iter->second)/(double)n);
        ++iter;
    }
    
    return 0;
}
