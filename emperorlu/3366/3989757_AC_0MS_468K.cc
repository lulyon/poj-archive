#include<iostream>
#include<map>
using namespace std;

map<string,string> mp;

int main()
{
    int l,n;
    cin>>l>>n;
    string s1,s2;
    string::iterator iter;
    while(l--)
    {
        cin>>s1>>s2;
        mp.insert(make_pair(s1,s2));
    }
    while(n--)
    {
        cin>>s1;
        if(mp.count(s1))
            cout<<mp[s1]<<endl;
        else
        {
            iter=s1.end()-1;
            if(*(iter)=='y'&&(iter==s1.begin()||
                    (*(iter-1)!='a'&&*(iter-1)!='e'&&*(iter-1)!='o'&&*(iter-1)!='i'&&*(iter-1)!='u')))
            {
                *(iter)='i';
                cout<<s1<<"es"<<endl;
            }
            else if(*iter=='o'||*iter=='x'||*iter=='s'
                    ||(*iter=='h'&&iter>s1.begin()&&(*(iter-1)=='s'||*(iter-1)=='c')))
            {
                cout<<s1<<"es"<<endl;
            }
            else
            {
                cout<<s1<<'s'<<endl;
            }
        }
    }
    return 0;
}
