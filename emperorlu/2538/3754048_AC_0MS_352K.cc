#include<iostream>
using namespace std;
int hash[200];
void init()
{
    hash['W']='Q';
    hash['E']='W';
    hash['R']='E';
    hash['T']='R';
    hash['Y']='T';
    hash['U']='Y';
    hash['I']='U';
    hash['O']='I';
    hash['P']='O';
    hash['[']='P';
    hash[']']='[';
    hash['S']='A';
    hash['D']='S';
    hash['F']='D';
    hash['G']='F';
    hash['H']='G';
    hash['J']='H';
    hash['K']='J';
    hash['L']='K';
    hash[';']='L';
    hash['\'']=';';
    hash['X']='Z';
    hash['C']='X';
    hash['V']='C';
    hash['B']='V';
    hash['N']='B';
    hash['M']='N';
    hash[',']='M';
    hash['.']=',';
    hash['/']='.';
    
    hash['1']='`';
    hash['2']='1';
    hash['3']='2';
    hash['4']='3';
    hash['5']='4';
    hash['6']='5';
    hash['7']='6';
    hash['8']='7';
    hash['9']='8';
    hash['0']='9';
    hash['-']='0';
    hash['=']='-';
   // hash['\']= '=';
        
    
    
    
    
    
    
    
    
}
int main()
{
    init();
    char c;
    while((c=getchar())!=EOF)
    {
        if(hash[c]!=0)
            printf("%c",hash[c]);
        else
            printf("%c",c);
    }
}
