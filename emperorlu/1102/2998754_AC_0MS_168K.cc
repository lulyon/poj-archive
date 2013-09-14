/*
  Name: 
  Copyright: 
  Author: 
  Date: 19-12-07 20:16
  Description: 
*/
#include<stdio.h>
#include<stdlib.h>
char a[10];
char b[10][5]={"- -","   ","---","---"," - ","---","---","-  ","---","---"};
char c[10][5]={"||||"," | |"," || "," | |","|| |","|  |","| ||"," | |","||||","|| |"};
int main()
{
    int n;
    while(scanf("%d%s",&n,a),n)
    {
        for(int i=0;a[i];i++)
        {
            printf(" ");
            for(int j=1;j<=n;j++)
                printf("%c",b[a[i]-'0'][0]);
            printf(" ");
            printf(" ");
        }
        printf("\n");
        for(int k=1;k<=n;k++)
        {
            for(int i=0;a[i];i++)
            {
                printf("%c",c[a[i]-'0'][0]);
                for(int j=1;j<=n;j++)
                {
                    printf(" ");
                }
                printf("%c",c[a[i]-'0'][1]);
                printf(" ");
            }
            printf("\n");
        }
        for(int i=0;a[i];i++)
        {
            printf(" ");
            for(int j=1;j<=n;j++)
            {
                printf("%c",b[a[i]-'0'][1]);
            }
            printf(" ");
            printf(" ");
        }
        printf("\n");
        for(int k=1;k<=n;k++)
        {
            for(int i=0;a[i];i++)
            {
                printf("%c",c[a[i]-'0'][2]);
                for(int j=1;j<=n;j++)
                {
                    printf(" ");
                }
                printf("%c",c[a[i]-'0'][3]);
                printf(" ");
            }
            printf("\n");
        }
        for(int i=0;a[i];i++)
        {
            printf(" ");
            for(int j=1;j<=n;j++)
            {
                printf("%c",b[a[i]-'0'][2]);
            }
            printf(" ");
            printf(" ");
        }
        printf("\n");
        printf("\n");
    }
    return 0;
}