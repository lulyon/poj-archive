#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        int num;
        scanf("%d", &num);
        if(num>=10){
            int top=0;
            while(num>=10){
                top ++;
                num = (num + 5)/10;
            }
            printf("%d", num);
            for(int i=1; i<=top; ++i){
                printf("0");
            }
        }
        else{
            printf("%d", num);
        }
        printf("\n");
    }
    return 0;
}

