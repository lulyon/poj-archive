#include<stdio.h>
int main()
{ int i,j,k,N,t,an,i0,j0,col,x,y,flag,anx,any;
  int a[100][100];
  scanf("%d",&t);
  while(t--)
  { for(i=1;i<=19;i++)
    { for(j=1;j<=19;j++)
      { scanf("%d",&a[i][j]);
      }
    }    
    
    for(i=1;i<=19;i++)
    { for(j=1;j<=19;j++)
      { if(a[i][j]!=0)
        { i0=i;j0=j;an=0;
          col=a[i0][j0];
          for(y=j0;y<=19;y++)
          { if(a[i0][y]==col)an++;
            else break;  
          }
          if(an==5){anx=i0;any=j0;goto pp;}
          else an=0;
          for(x=i0;x<=19;x++)
          { if(a[x][j0]==col)an++; 
            else break;
          }
          if(an==5){anx=i0;any=j0;goto pp;}
          else an=0;
          for(x=i0,y=j0;x<=19,y>=1;x++,y--)
          { if(a[x][y]==col)an++;  
            else break;
          }
          
          if(an==5){anx=x-1;any=y+1;goto pp;}
          else an=0; 
          for(x=i0,y=j0;x<=19,y<=19;x++,y++)
          {if(a[x][y]==col)an++;else break;}
           
          if(an==5){anx=i0;any=j0;goto pp;}
          else an=0;
        }
      }
    }
    if(an==0){printf("0\n");continue;}
    pp:;
    printf("%d\n",col);
    printf("%d %d\n",anx,any);
               
  } 
   
}