#include<stdio.h>
typedef struct item
{
 int a[101][101];
 int vexsnum,arcnum;
}graph;
graph netGraph;
void shortPath_DIJ(int v0,int *vex,int *cst)
{
 int v,d[101],flag[101],i,w,c=0,min;
 for(v=0;v<netGraph.vexsnum;v++)
 {
  d[v]=netGraph.a[v0][v];
  flag[v]=0;

 }

 d[v0]=100;
 flag[v0]=1;
 for(i=1;i<netGraph.vexsnum;i++)
 {
  min=100;
  for(w=0;w<netGraph.vexsnum;w++)
  {
   if(flag[w]==0&&d[w]<min)
   {
    v=w;
    min=d[w];
   }
  }
  flag[v]=1;
  for(w=0;w<netGraph.vexsnum;w++)
  {
   if(flag[w]==0&&(min+netGraph.a[v][w])<d[w])
   {
    d[w]=min+netGraph.a[v][w];
   }
  }
 }
 min=0;
 for(w=0;w<netGraph.vexsnum;w++)
 {
  if(min<d[w]&&w!=v0)
   {
   min=d[w];
   c=w;
   }
 }
 *vex=v0+1;
 *cst=d[c];
}
void initial()
{
 int i,j;
 for(i=0;i<101;i++)
 for(j=0;j<101;j++)
 {
  netGraph.a[i][j]=100;
 }
}
main()
{
 int n,i,j,c,v,w,min=10000,temp,cost,min_w,f=0;
 while(1)
 {
  scanf("%d",&n);
  if(n==0)break;
  min=10000;
  min_w=10000;
  initial();
  netGraph.vexsnum=n;
  f=0;
  while(n--)
  {
   scanf("%d",&c);
   for(i=0;i<c;i++)
   {
    scanf("%d%d",&v,&w);
    netGraph.a[f][v-1]=w;
   }
   f++;
  }
  for(i=0;i<netGraph.vexsnum;i++)
  {
   shortPath_DIJ(i,&temp,&cost);
   if(cost<min_w)
   {
    min=temp;
    min_w=cost;
   }
  }
  if(min_w==100)
  {
   printf("disjoint\n");
  }
  else
  printf("%d %d\n",min,min_w);

 }
}

