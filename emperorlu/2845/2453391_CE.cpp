> #include <string.h>
> #include <stdio.h>
> char addnum1[85 char addnum2[85];
> char result[85];
> char c='0';
> void main(){
> 	int n,a,b,tag;
> 	scanf("%d",&n);
> 	int i=0;
> 	while(i<n){
> 		scanf("%s",addnum1);
> 		scanf("%s",addnum2);
> 		a=strlen(addnum1);
> 		b=strlen(addnum2);
> 		tag=a>b?a:b;
> 		int t=tag;
> 		if(a>b){
> 			while(b>0){
> 				addnum2[a-1]=addnum2[b-1];
> 				b--;
> 				a--;
> 			}
> 		}
> 		if(a<b){
> 			while(a>0){
> 				addnum1[b-1]=addnum2[a-1];
> 				a--;
> 				b--;
> 			}
> 		}
> 		while(tag>0){
> 			if(addnum1[tag-1]=='0'&&addnum2[tag-1]=='0'){
> 				result[tag-1]=c;
> 				c='0';
> 				tag--;
> 				continue;
> 			}
> 			if((addnum1[tag-1]=='1'&&addnum2[tag-1]=='0')||(addnum1[tag-1]=='0'&&addnum2[tag-1]=='1')){
> 				if(c=='1'){
> 					result[tag-1]='0';
> 				}
> 				else{
> 					result[tag-1]='1';
> 				}
> 				tag--;
> 				continue;
> 			}
> 			if(addnum1[tag-1]=='1'&&addnum2[tag-1]=='1'){
> 				result[tag-1]=c;
> 				c='1';
> 				tag--;
> 				continue;
> 			}
> 		}
> 		if(c!='0'){
> 			printf("%d %c",i+1,c);
> 			printf("%s",result);
> 			c='0';
> 			printf("\n");
> 		}
> 		else {
> 			printf("%d ",i+1);
> 			a=0;
> 			while(a<t-1&&result[a]=='0')a++;
> 			printf("%s",&(result[a]));
> 			printf("\n");
> 		}
> 		i++;
> 	}
> }
