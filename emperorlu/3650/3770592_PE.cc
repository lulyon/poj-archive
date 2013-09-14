#include<iostream>
#include<map>
using namespace std;
map<char,string> dict;
void init()
{
    dict.insert(make_pair(' ',"%20"));
    dict.insert(make_pair('!',"%21"));
    dict.insert(make_pair('$',"%24"));
    dict.insert(make_pair('%',"%25"));
    dict.insert(make_pair('(',"%28"));
    dict.insert(make_pair(')',"%29"));
    dict.insert(make_pair('*',"%2a"));
}
int main()
{
    char c;
    init();
    while((c=getchar())!='#')
    {
        if(dict.count(c))
            cout<<dict[c]<<endl;
        else
            cout<<c<<endl;
    }
    return 0;
}

