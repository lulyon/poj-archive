#include <stdio.h>
#include <string.h>


struct point 
{
    int x,y;
};

point pt[200];

int px[200],py[200];

int xn,yn;

int n;

int f[200][200][200],g[200][200][200];

int graph[200][200];

int find(int p[],int x,int num)
{
    int i;
    for (i=0;i<num;i++)
        if (p[i]==x) return i;
    return -1;
}


void ins(int p[],int x,int&num)
{
    int i;

    if (find(p,x,num)>=0) return ;

    i=num;
    if (i>0)
    while (p[i-1]>x)
    {
        p[i]=p[i-1];
        i--;
        if (i==0) break;
    }
    p[i]=x;
    num++;
}



void input()
{
    int i,j,k,p,q;
    xn=0;
    yn=0;
    memset(px,0,sizeof(px));
    memset(py,0,sizeof(py));
    for (i=0;i<n;i++)
    {
        scanf("%d%d",&pt[i].x,&pt[i].y);
        ins(px,pt[i].x,xn);
        ins(py,pt[i].y,yn);

    }



    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    memset(graph,0,sizeof(graph));

    for (i=0;i<n;i++)
    {
        p=find(px,pt[i].x,xn);
        q=find(py,pt[i].y,yn);
        graph[p][q]=1;
        f[p][p][q]=1;
        g[q][q][p]=1;
    }

    for (i=0;i<xn;i++)
        for (j=1;i+j<xn;j++)
            for (k=0;k<yn;k++)
                f[i][j+i][k]=f[i][j+i-1][k]+f[i+j][i+j][k];

    for (i=0;i<yn;i++)
        for (j=1;j+i<yn;j++)
            for (k=0;k<xn;k++)
                g[i][j+i][k]=g[i][i+j-1][k]+g[i+1][i+j][k];

}



    

int main()
{
    int i,j,p,q;
    int t=0;

    while (scanf("%d",&n)==1)
    {

        if (n==0) break;
        t++;

        input();


        int ans=0;
        for (i=0;i<xn;i++)
            for (j=i+1;j<xn;j++)
                for (p=0;p<yn;p++)
                    for (q=p+1;q<yn;q++)
                    {
                        int temp=f[i][j][p]+f[i][j][q]+g[p][q][i]+g[p][q][j]-graph[i][p]-graph[i][q]-graph[j][p]-graph[j][q];

                        if (temp>ans) 
                        {
                            //cout<<"*********"<<endl;
                            //cout<<i<<' '<<q<<endl;
                        //    cout<<j<<' '<<p<<endl;
                        

                            ans=temp;
                        }
                    }
                    printf("%s %d: ","Case",t);
        printf("%d\n",ans);
    }

    return 0;
}

