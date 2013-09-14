#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a[1000];
    char str[1000][10];
    while(1)
    {
        cin>>a[0];
        getchar();
        if(!a[0])break;
        gets(str[0]);
        if(strcmp(str[0],"right on")==0)
        {
            cout<<"Stan may be honest"<<endl;
            continue;
        }
        /*
        cout<<a[0]<<endl;
        cout<<str[0]<<endl;
        system("pause");
        */
        int i=1;
        while(1)
        {
            cin>>a[i];
            getchar();
            gets(str[i]);
            if(strcmp(str[i],"right on")==0)break;
            i++;
        }
        int flag=0;
        for(int j=0;j<i;j++)
            if((a[j]<a[i]&&strcmp(str[j],"too high")==0)||(a[j]>a[i]&&strcmp(str[j],"too low")==0))
            {
                flag=1;
                break;
            }
        if(flag||a[i]>10)cout<<"Stan is dishonest"<<endl;
        else cout<<"Stan may be honest"<<endl;
    }
    return 0;
}
