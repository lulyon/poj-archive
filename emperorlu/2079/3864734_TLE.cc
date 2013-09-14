 // 
// File:   whu1263.cc
// Author: acm
//
// Created on 2008年7月27日, 上午6:45
//凸包标程+修改
#include<iostream>
using namespace std;
#include <math.h>
#define MAXN 100000

/* 顶点的类型定义 */
typedef struct {
double x;
double y;
double arCos;
}Point1;
int n;      // 顶点的个数
Point1 points[MAXN];      // 顶点数组
int stack[MAXN];  // 栈
int t;

/*数据读入函数*/
void Init()
{
int i;
for(i = 0; i < n; ++i)
    scanf("%lf%lf", &points[i].x, &points[i].y);
}

/*算法实现函数*/
void Make()
{
int Multi(Point1, Point1, Point1);    //计算两个向量的积
double Angle(int);       //计算其余顶点与第一顶点的角度,为排序做准备
void QSort(int, int);      //对顶点进行快速排序
void Swap(int, int);     
int i, j;
double min = 32767.0;
for(i = 0; i < n; ++i){      //找第一个顶点,做为算法的起始顶点
   if(points[i].y < min) {
    j = i;
    min = points[i].y;
   }
    }
Swap(0, j);
for(i = 1; i < n; ++i){      //计算除第一顶点外的其余顶点到第一点的线段与x轴的夹角
   points[i].arCos = Angle(i);
}
QSort(1, n-1);        //根据所得到的角度进行快速排序.
for(i = 0; i <= 2; ++i) stack[i] = i;    //将前3个顶点压栈
t = 2;
//i= 3；
while(i < n) {
    /*如果新的点,与最近入栈中的2点构成了一个"凹"角, 则将栈顶元素出栈. 直到把栈检查完*/
   while(Multi(points[stack[t-1]], points[stack[t]], points[i]) && t >= 1)t--;    
   t++;         // 将新点压栈
   stack[t] = i;
   i++;
}

/*打印结果*/
/*
for(i = 0; i <=t; ++i)
   printf("<%.2lf, %.2lf>\n",points[stack[i]].x, points[stack[i]].y);


cout<<"end"<<endl;
 */
}

int Multi(Point1 px, Point1 py, Point1 pz)
{
double k;
k = (py.x-px.x)*(pz.y-py.y) - (pz.x-py.x)*(py.y-px.y);  // 计算两个向量的向量积,
// 判断3个点所成的角是不是一个"凹"角.
if(k < 0) return 1;
return 0;
}

/*角度计算函数*/
double Angle(int i)
{
double j, k, m, n;
j = fabs(points[i].x - points[0].x);
k = fabs(points[i].y - points[0].y);
m = sqrt(j*j+k*k);      //得到顶点i 到第一顶点的线段长度.
n = acos(j/m);       //得到该线段与x轴的角度
//强悍
return n;
}

void QSort(int top, int bot)
{
     //快排
int Loc(int, int);
int pos;

if(top < bot) {
   pos = Loc(top, bot);
   QSort(top, pos-1);
   QSort(pos+1, bot);
}
}

int Loc(int top, int bot)
{
void Swap(int, int);
double x = points[top].arCos;
int j, k;
j = top+1;
k = bot;
while(1) {
   while(j < bot && points[j].arCos < x) j++;
   while(k > top && points[k].arCos > x) k--;
  
   if(j >= k) break;
  
   Swap(j, k);
}
Swap(top, k);
return k;
}

void Swap(int px, int py)
{
Point1 k;
k = points[px];
points[px] = points[py];  //注意
points[py] = k;
}


double area(int i,int j,int k)
{
    double tmp = (points[j].x-points[i].x)*(points[j].y-points[k].y)
    -(points[j].x-points[k].x)*(points[j].y-points[i].y);
    return 0.5*(tmp>0?tmp:-tmp);
}






/*主函数*/
int main()
{
    void Init();
    void Make();
    double Calc();
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)break;
        Init();     //程序数据的读入
        Make();     //程序算法过程
        
        printf("%.2lf\n",Calc());
    }
    
    return 0;
}

double Calc()
{
    int i,j,k;
    double r=-INT_MAX,tmp;

    for(i=0;i<=t;++i)
    {
        for(j=i+1;j<=t;++j)
        {
            for(k=j+1;k<=t;++k)
            {
                
                tmp=area(stack[i],stack[j],stack[k]);
                if(r<tmp)r=tmp;
                else
                    break;
            }
        }
    }
    return r;
}
