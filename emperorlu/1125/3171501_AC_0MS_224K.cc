#include <stdio.h>

#define Max 99999999

int inta[101][101];

void Floyd(int a[][101] , int n )
{
     int i , j , k ;
     int min , Index , time , c , p ;

     for( k = 1 ;k<=n ;k++ )
         for( i = 1 ;i <= n ;i++)
                 for(j =1 ; j<=n;j++)
                 {
                         if( a[i][j] > a[i][k] + a[k][j] )
                                 a[i][j] = a[i][k] + a[k][j] ;
                 }
     min = Max ;

     for( i= 1 ;i <= n ;i++)
     {
           p = 0 ;
           c = 0 ;
           for(j = 1 ;j <= n;j++)
           {
               c += a[i][j] ;
               if( a[i][j] > p )
                 p = a[i][j] ;
           }
           if( min > c )
           {
                 min = c ;
                 Index = i ;
                 time = p ;
           }
     }
     if( min < Max )
         printf("%d %d\n",Index ,time ) ;
     else
         printf("disjoint\n");
}
int main(int argc, char* argv[])
{
         int n ;
         int i , j   ;

         while(scanf("%d",&n) != EOF)
         {
                 if( n== 0 )
                         return 0 ;
                 for( i = 1 ; i <= n ;i++ )
                         for( j = 1 ; j <= n ;j++)
                                 if(i == j )
                                         inta[i][j] = 0 ;
                                 else
                                         inta[i][j] = Max ;

                 int nn ;
                 int a , time ;
                 i = 1 ;
                 while( i <= n )
                 {
                         scanf("%d",&nn ) ;
                         if( nn == 0 )
                         {
                                 i++ ;
                                 continue ;
                         }
                         for( j=1 ;j<=nn ;j++ )
                         {
                             scanf("%d %d",&a,&time ) ;
                            inta[i][a] = time ;
                         }
                         i++ ;
                 }
                 Floyd(inta , n) ;
         }

         return 0;
}

