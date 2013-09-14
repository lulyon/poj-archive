#include<iostream>
#include<map>
using namespace std;
map<string,int> dict;
string str;
int num;
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;++i)
    {
        cin>>str>>num;
        dict.insert(make_pair(str,num));
        
    }
    for(int i=0;i<n;++i)
    {
        int sum=0;
        while(1)
        {
            cin>>str;
            if(str[0]=='.')break;
            map<string,int>::iterator iter;
            iter=dict.find(str);
            if(iter!=dict.end())
                sum+=iter->second;
        }
        cout<<sum<<endl;
    }
    return 0;
}