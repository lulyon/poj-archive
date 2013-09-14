#include<iostream>
using namespace std;
char a[10000][20];
char word[20];
int len[10000];
int wordstack[10000];
int main()
{
    int dictflag=0,i,j,k;
    while(1)
    {
        cin>>a[dictflag];
        if(a[dictflag][0]=='#')break;
        len[dictflag]=strlen(a[dictflag]);
        dictflag++;
    }
    while(1)
    {
        cin>>word;
        if(word[0]=='#')break;
        int wordlen=strlen(word);
        int wordflag=0;
        for(i=0;i<dictflag;i++)
        {
            if(wordlen==len[i])
            {
                for(j=0;word[j]&&a[i][j]==word[j];j++);
                if(word[j]=='\0')
                {
                    cout<<word<<" is correct"<<endl;
                    break;
                }
                j++;
                for(;word[j]&&a[i][j]==word[j];j++);
                if(word[j]=='\0')
                    wordstack[wordflag++]=i;
            }
            else if(wordlen==len[i]-1)
            {
                for(j=0;word[j]&&a[i][j]==word[j];j++);
                if(word[j]=='\0')
                {
                    wordstack[wordflag++]=i;
                    continue;
                }
                for(;word[j]&&a[i][j+1]==word[j];j++);
                if(word[j]=='\0')
                    wordstack[wordflag++]=i;
            }
            else if(wordlen==len[i]+1)
            {
                for(j=0;a[i][j]&&a[i][j]==word[j];j++);
                
                if(a[i][j]=='\0')
                {
                    wordstack[wordflag++]=i;
                    continue;
                }
                for(;a[i][j]&&a[i][j]==word[j+1];j++);
                if(a[i][j]=='\0')
                    wordstack[wordflag++]=i;
            }
            
            
        }
        if(i<dictflag)continue;
        cout<<word<<":";
        for(i=0;i<wordflag;i++)
            cout<<' '<<a[wordstack[i]];
        cout<<endl;
    }
    //system("pause");
    return 0;
}
