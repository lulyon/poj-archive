#include<iostream>
using namespace std;

char a[10010] = {
"29922993299429952996299729982999447044714472447344744475497049714972497349744975546054615462546354645465546654675468546959605961596259636456645764586459744074417442744374447445744674477448744979407941794279438436843784388439942494259426942794289429992499259926992799289929"	};
int main(){
	for(int i=0; a[i]; i+=4){
		printf("%c%c%c%c\n",a[i],a[i+1],a[i+2],a[i+3]);
	}
	return 0;
}

