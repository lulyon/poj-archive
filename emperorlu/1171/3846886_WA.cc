#include<iostream>
using namespace std;
char a[10],s[10];
int score[26]=
{
    2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,7,7
};

int num[26];
int tmp[26];


int main()
{
    scanf("%s",a);
    for(int i=0;a[i];++i)
        ++num[a[i]-'a'];

    int max=0;
    while(1)
    {
        scanf("%s",s);
        if(s[0]=='.')break;
        
        for(int i=0;i<26;++i)
            tmp[i]=num[i];
        
        int cn=0;
        for(int i=0;s[i];++i)
        {
            if(tmp[s[i]-'a'])
            {
                cn+=score[s[i]-'a'];
                --tmp[s[i]-'a'];
            }
        }
        if(max<cn)max=cn;
        
    }
    
    printf("%d\n",max);
    return 0;
}
