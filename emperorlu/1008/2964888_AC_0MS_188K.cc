#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max 750

int main()
{
    int n,i,m;
    int h_d,h_y,_y[max],_d[max],temp;
    char h_m[9],_m[max][9];
    const char con_h[20][8]={
                            "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax",
                            "zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"
                       };
    const char con_m[20][9]={
                               "imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok",
                               "chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"
                            };    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d. %s %d",&h_d,&h_m,&h_y);
        for(m=0;m<20;m++) if(strcmp(h_m,con_h[m])==0) break;
        temp=h_y*105+m*20+h_d;
        _y[i]=h_y+temp/260;
        temp=temp%260;
        _d[i]=temp%13+1;
        strcpy(_m[i],con_m[temp%20]);  
    }
    printf("%d\n",n);
    for(i=0;i<n;i++)
	{
        printf("%d %s %d\n",_d[i],_m[i],_y[i]);
    }
	//system("pause");    
  return 0;
}


