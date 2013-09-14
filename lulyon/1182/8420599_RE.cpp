#include <stdio.h>
#include <stdlib.h>

int const N= 50010;
int n, k;
int uset[N], dist[N];

int find( int x ){
    if( x== uset[x] ) return x;
    int rt= find( uset[x] );
    dist[x]= ( dist[x]+ dist[ uset[x] ] )% 3;
    uset[x]= rt;
    return rt;
}

int main(){
    scanf("%d%d",&n,&k);
    for( int i= 0; i<= n; ++i ){
        uset[i]= i; dist[i]= 0; }
    int ans= 0;
    for( int i= 0; i< k; ++i ){
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y ); d--;
            
        if( x> n || y> n ){ ans++; continue; }

        int rx= find(x), ry= find(y);
        if( rx== ry ){
            if( ( d+ dist[y] )% dist[x] ) ans++; 
        }else{
            uset[rx]= ry;
            dist[rx]= ( d+ dist[y]- dist[x]+ 6 )% 3;
        }
    }
    printf("%d\n", ans );
    
    return 0;
}