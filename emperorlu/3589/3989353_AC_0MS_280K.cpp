#include<iostream>
using namespace std;

char s1[10],s2[10];

int pos[20];

int main()
{
    int t,n1,n2;
    cin>>t;
    while(t--)
    {
        scanf("%s%s",s1+1,s2+1);
        
        memset(pos,0,sizeof(pos));
        pos[s1[1]-'0']=1;
        pos[s1[2]-'0']=2;
        pos[s1[3]-'0']=3;
        pos[s1[4]-'0']=4;
        
        n1=n2=0;
        
        if(pos[s2[1]-'0']==1)
            n1++;
        else if(pos[s2[1]-'0']!=0)
            n2++;
        
        if(pos[s2[2]-'0']==2)
            n1++;
        else if(pos[s2[2]-'0']!=0)
            n2++;
        
        if(pos[s2[3]-'0']==3)
            n1++;
        else if(pos[s2[3]-'0']!=0)
            n2++;
        
        if(pos[s2[4]-'0']==4)
            n1++;
        else if(pos[s2[4]-'0']!=0)
            n2++;
        
        printf("%dA%dB\n",n1,n2);
    }
    return 0;
}

