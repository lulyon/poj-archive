#include<iostream>
#include<map>
using namespace std;
map<char,string> cs;
map<string,char> sc;
int a[200];
int stack[110];
void init()
{
    cs.insert(make_pair('A',".-"));sc.insert(make_pair(".-",'A'));
    cs.insert(make_pair('B',"-..."));sc.insert(make_pair("-...",'B'));
    cs.insert(make_pair('C',"-.-."));sc.insert(make_pair("-.-.",'C'));
    cs.insert(make_pair('D',"-.."));sc.insert(make_pair("-..",'D'));
    cs.insert(make_pair('E',"."));sc.insert(make_pair(".",'E'));
    cs.insert(make_pair('F',"..-."));sc.insert(make_pair("..-.",'F'));
    cs.insert(make_pair('G',"--."));sc.insert(make_pair("--.",'G'));
    cs.insert(make_pair('H',"...."));sc.insert(make_pair("....",'H'));
    cs.insert(make_pair('I',".."));sc.insert(make_pair("..",'I'));
    cs.insert(make_pair('J',".---"));sc.insert(make_pair(".---",'J'));
    cs.insert(make_pair('K',"-.-"));sc.insert(make_pair("-.-",'K'));
    cs.insert(make_pair('L',".-.."));sc.insert(make_pair(".-..",'L'));
    cs.insert(make_pair('M',"--"));sc.insert(make_pair("--",'M'));
    cs.insert(make_pair('N',"-."));sc.insert(make_pair("-.",'N'));
    cs.insert(make_pair('O',"---"));sc.insert(make_pair("---",'O'));
    cs.insert(make_pair('P',".--."));sc.insert(make_pair(".--.",'P'));
    cs.insert(make_pair('Q',"--.-"));sc.insert(make_pair("--.-",'Q'));
    cs.insert(make_pair('R',".-."));sc.insert(make_pair(".-.",'R'));
    cs.insert(make_pair('S',"..."));sc.insert(make_pair("...",'S'));
    cs.insert(make_pair('T',"-"));sc.insert(make_pair("-",'T'));
    cs.insert(make_pair('U',"..-"));sc.insert(make_pair("..-",'U'));
    cs.insert(make_pair('V',"...-"));sc.insert(make_pair("...-",'V'));
    cs.insert(make_pair('W',".--"));sc.insert(make_pair(".--",'W'));
    cs.insert(make_pair('X',"-..-"));sc.insert(make_pair("-..-",'X'));
    cs.insert(make_pair('Y',"-.--"));sc.insert(make_pair("-.--",'Y'));
    cs.insert(make_pair('Z',"--.."));sc.insert(make_pair("--..",'Z'));
    cs.insert(make_pair('_',"..--"));sc.insert(make_pair("..--",'_'));
    cs.insert(make_pair(',',".-.-"));sc.insert(make_pair(".-.-",','));
    cs.insert(make_pair('.',"---."));sc.insert(make_pair("---.",'.'));
    cs.insert(make_pair('?',"----"));sc.insert(make_pair("----",'?'));
    
    a['A']=2;a['H']=4;a['O']=3;a['V']=4;a['.']=4;
    a['B']=4;a['I']=2;a['P']=4;a['W']=3;a['?']=4;
    a['C']=4;a['J']=4;a['Q']=4;a['X']=4;
    a['D']=3;a['K']=3;a['R']=3;a['Y']=4;
    a['E']=1;a['L']=4;a['S']=3;a['Z']=4;
    a['F']=4;a['M']=2;a['T']=1;a['_']=4;
    a['G']=3;a['N']=2;a['U']=3;a[',']=4;
    
}
int main()
{
    int t;
    init();
    cin>>t;
    string str;
    int tt=0;
    while(t--)
    {
        cin>>str;
        string dict;
        string::iterator iter;
        int top=0;
        for(iter=str.begin();iter!=str.end();++iter)
        {
            dict+=cs[*iter];
            stack[top++]=a[*iter];
        }
        str.clear();
        iter=dict.begin();
        cout<<++tt<<": ";
        for(int i=top-1;i>=0;--i)
        {
            for(int j=0;j<stack[i];++j,++iter)
                str.push_back(*iter);
            cout<<sc[str];
            str.clear();
        }
        cout<<endl;
    }
    return 0;
}
