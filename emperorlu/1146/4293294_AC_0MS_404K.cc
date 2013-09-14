#include<iostream>
#include<algorithm>
using namespace std;
char str[100];
char pre[100];
char pos[100];

bool cmp(const char &aa,const char &bb)
{
	return aa>bb;
}
	
int main()
{
    while(1)
    {
		scanf("%s",str);
		if(str[0]=='#')break;
		
		int len = strlen(str);
		strcpy(pre,str);
		strcpy(pos,str);
		sort(pos,pos+len,cmp);
		
		//printf("%s\n",pos);
		//system("pause");
		
		
		
		while(1)
		{
			if(strcmp(str,pre))
			{
				printf("%s\n",str);
				break;
			}
			else if(strcmp(str,pos)==0)
			{
				printf("No Successor\n");
				break;
			}
			next_permutation(str,str+len);			
		}
	}
    return 0;
}
