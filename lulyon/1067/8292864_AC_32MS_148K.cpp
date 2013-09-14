#include <stdio.h>
#include <math.h>

const double goldnum = (1.0 + sqrt(5.0)) * 0.5;

int main(){
    int a, b, k, c;
    
    while(scanf("%d%d", &a, &b) != EOF){
        if (a > b)a^=b^=a^=b;
        k = b - a;
        c = (int)(goldnum * (double)k);
        if (c == a) printf ("0\n"); else printf ("1\n");
    }
    return 0;
}

