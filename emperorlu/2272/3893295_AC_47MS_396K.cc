#include<iostream>
#include<math.h>


#define EPS 1e-12
using namespace std;

double x[10],y[10],xy[10];
double s[5]={9,36,81,144,225};
int sc[5]={100,80,60,40,20};
int main()
{
    int i,j;
    while(1)
    {
        for(i=0;i<6;++i)
        {
            scanf("%lf %lf",x+i,y+i);
            xy[i]=x[i]*x[i]+y[i]*y[i];
        }
        
        //cout<<x[i]<<endl;
        
        if(fabs(x[0]+100)<EPS)break;
        
        int cn1=0;
        for(i=0;i<3;++i)
        {
            for(j=0;j<6&&xy[i]>s[j];++j);
            if(j<6)
                cn1+=sc[j];
        }
        
        int cn2=0;
        for(i=3;i<6;++i)
        {
            for(j=0;j<6&&xy[i]>s[j];++j);
            if(j<6)
                cn2+=sc[j];
        }
        if(cn1>cn2)
            printf("SCORE: %d to %d, PLAYER 1 WINS.\n",cn1,cn2);
        else if(cn1==cn2)
            printf("SCORE: %d to %d, TIE.\n",cn1,cn2);
        else
            printf("SCORE: %d to %d, PLAYER 2 WINS.\n",cn1,cn2);
    }
    
    return 0;
}
