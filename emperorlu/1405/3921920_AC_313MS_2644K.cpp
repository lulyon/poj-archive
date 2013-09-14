#include<iostream>
#include<iomanip>
#include<cstdio>

using namespace std;

#define SIZE 100000
//s[0]储存位数，其他的从s[SIZE]开始向前存储
void mutiply(__int64* s1,__int64*s2,__int64*res){
    int i,j;
    for(i=SIZE;i>SIZE-s1[0];i--){
        for(j=SIZE;j>SIZE-s2[0];j--){
            res[i+j-SIZE]+=s1[i]*s2[j];
            res[i+j-SIZE-1]+=res[i+j-SIZE]/100000000;
            res[i+j-SIZE]%=100000000;
        }
    }
    int len=s1[0]+s2[0];
    for(i=SIZE+1-len;i<SIZE;i++){
        if(res[i]!=0)break;
    }
    res[0]=SIZE+1-i; 
    /* res[0]=len;
    if(res[1001-s1[0]-s2[0]]==0)res[0]--; */
}  

void plus_(__int64*s){
    int i;
    s[SIZE]++;
    for(i=SIZE;i>SIZE-s[0];i--){
        if(s[i]>=100000000){
            s[i]%=100000000;
            s[i-1]++;
        }
        else break;
    }
    if(s[SIZE-s[0]]!=0)s[0]++;
}

void des(__int64*s){
    int i;
    s[SIZE]--;
    for(i=SIZE;i>SIZE-s[0];i++){
        if(s[i]<0){
            s[i]+=100000000;
            s[i-1]--;
        }
        else break;
    }
    if(s[SIZE-s[0]+1]==0)s[0]--;
}

int main(){
    int N;
    cin>>N;
    cout<<2<<endl;
    N--;
    int i;
    __int64 s[SIZE+1]={0};
    s[0]=1;
    s[SIZE]=2;
    while(N--){
        __int64 res[SIZE+1]={0};
        __int64 s1[SIZE+1];
        for(i=0;i<SIZE+1;i++){
            s1[i]=s[i];
        }
        des(s1);
       
        mutiply(s1,s,res);
        
        plus_(res);
     
        for(i=0;i<SIZE+1;i++){
            s[i]=res[i];
        }
    
        for(i=SIZE+1-s[0];i<=SIZE;i++){
            if(s[i]<10000000&&i!=SIZE+1-s[0]){
                /* cout<<setw(8)<<setfill('0')<<s[i]; */
                printf("%.8I64d",s[i]);
            }
            else printf("%I64d",s[i]);    
        }
       printf("\n");
    }       
    //system("pause");
    return 0;
}     
