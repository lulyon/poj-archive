#include <iostream>
using namespace std;
bool flag[35][35];
int main()
{

	int i,j,k,n,x,y;
	char str;
	scanf("%d",&n);
	for (k = 1; k <= n; k++)
	{
		scanf("%d%d",&x,&y);
                getchar();
		memset(flag,0,sizeof(flag));
		while(1)
		{
                        str=getchar();
                        
                        if(str=='.')break;
                        
			if(str == 'E')
			{
				flag[y - 1][x] = 1;
				x++;
			}
			else if (str == 'W')
			{
				flag[y][x - 1] = 1;
				x--;
			}
			else if (str == 'N')
			{
				flag[y][x] = 1;
				y++;
			}
			else if (str == 'S')
			{
				flag[y - 1][x - 1] = 1;
				y--;
			}
			
		}
		printf("Bitmap #%d\n",k);
		for (i = 31; i >= 0; i--)
		{
			for (j = 31; j >= 0; j--)
				if (flag[i][31 - j] == 1)
					printf("X");
				else printf(".");
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
