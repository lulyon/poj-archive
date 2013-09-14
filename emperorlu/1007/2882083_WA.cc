#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void InsertSort(int a[], int n)
{
    int i,j,temp;
    for(i=1; i<=n-1; i++)
    {
        temp = a[i];
        j=i-1;
        while(j>=0 && temp<a[j])
            a[j+1]=a[j--];
        a[j+1]=temp;
    }
}

int main()
{
    int len, n, k, i, j, sum[100]={0}, sumTo[100]={0};
    char a[100][51];

    scanf("%d %d",&len,&n);
    k = n;
    while(n--)
    {
        scanf("%s",a[n]);
        for(i=0; i<len; i++)
        {
            for(j=i; j<len; j++)
            {
                if(a[n][i]>a[n][j])
                    sum[n]++;
            }
        }
    }

    
    memcpy(sumTo, sum, sizeof(int)*100);
    InsertSort(sumTo, k);
    
    for(i=0; i<k; i++)
    {
        for(j=0; j<k; j++)
        {
            if(sum[j]==sumTo[i])
            {
                printf("%s\n", a[j]);
                break;
            }
        }
    }
    //system("pause");
    return 0;
}
