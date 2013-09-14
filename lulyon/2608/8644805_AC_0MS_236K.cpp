#include<iostream>
using namespace std;
char a[21];
int kan(char a)
{
    if(a=='B'||a=='F'||a=='P'||a=='V') return 1;
    if(a=='C'||a=='G'||a=='J'||a=='K'||a=='Q'||a=='S'||a=='X'||a=='Z') return 2;
    if(a=='D'||a=='T') return 3;
    if(a=='L') return 4;
    if(a=='M'||a=='N') return 5;
    if(a=='R') return 6;
    else return 0;
}
int main()
{
    while(gets(a))
    {
        int l=strlen(a);
        for(int i=0,now=0,last=0;l-i;i++)
        {
            now=kan(a[i]);
            if(now&&now!=last)
            {
                cout<<now;
            }
            last=now;
        }
        cout<<endl;
    }
}

