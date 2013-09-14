//3253 Fence Repair by suqiang@neuq&jlu 
#include <stdio.h>
#include <stdlib.h>

int comp(const void *p,const void *q)
{
    return (*(int*)p-*(int*)q);
}

int main()
{
    int n,i,j,array[20001],temp;
    __int64 sum=0;

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    //对原始数列排序	
    qsort(array,n,sizeof(int),comp);
    //插入两个元素的和
    for(i=1;i<n;i++)
    {
        array[i]+=array[i-1];

        sum+=array[i];

	//以下语句可以用qsort(array,n,sizeof(int),comp);代替，但效率一定会低，因为所有元素排序效率会很低，因为只有一个元素是没有排序的
	
        temp=array[i];
        for(j=i+1;j<n;j++)
        {
            if(temp>array[j])
                array[j-1]=array[j];
            else
                break;
        }
        array[j-1]=temp;
    }
    printf("%I64d\n",sum);
    return 1;
}
