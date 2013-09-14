#include<iostream>
#include<string>
using namespace std;
char a[110],b[110];
int ac[27],bc[27];
int cmp( const void *a , const void *b ) 
{ 
    return *(char *)a - *(int *)b; 
}
int main()
{
    int i;
    while(cin>>a>>b)
    {
        memset(ac,0,sizeof(ac));
        memset(bc,0,sizeof(bc));
        for(i=0;a[i];i++)
            ac[a[i]-'A']++;
        for(i=0;b[i];i++)
            bc[b[i]-'A']++;
        int flag=1;
        qsort(ac,26,sizeof(ac[0]),cmp);
        qsort(bc,26,sizeof(bc[0]),cmp); 

        for(i=0;i<26;i++)
            if(ac[i]!=bc[i])
            {
                flag=0;
                break;
            }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
