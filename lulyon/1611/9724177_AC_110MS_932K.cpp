#include<iostream>
using namespace std;
typedef struct NODE{
	int gid;
	struct NODE *next;
}nodeType;

typedef struct LIST{
	int begin;
	int end;
	int *list;
}listType;

int main(int argc, char **argv)
{
	int n, m;
	while(1){
		scanf("%d%d", &n, &m);
		if(!n && !m)break;

		typedef int * pInt;
		typedef nodeType * pNodeType;
		pInt *group = new pInt[m];
		
		pNodeType *student = new pNodeType[n+10];
		for(int i=0; i<n+10; ++i){
			student[i] = NULL;
		}
		for(int i=0; i<m; ++i){
			int num;
			scanf("%d", &num);
			group[i] = new int[num+1];
			group[i][0] = num;
			for(int j=1; j<=num; ++j){
				scanf("%d", &group[i][j]);
				nodeType *newNode = new nodeType;
				newNode->gid = i;
				newNode->next = NULL;

				if(student[group[i][j]]==NULL){
					student[group[i][j]] = newNode;
				}
				else{
					newNode->next = student[group[i][j]];
					student[group[i][j]] = newNode;
				}
			}
		}

		bool *visited = new bool[n+10];
		for(int i=0; i<n+10; ++i){
			visited[i] = 0;
		}

		listType bfsList;
		bfsList.begin = bfsList.end = 0;
		bfsList.list = new int[n+10];
		bfsList.list[0] = 0;
		int count = 1;
		visited[0] = 1;

		while(bfsList.begin <= bfsList.end){
			int stuId = bfsList.list[bfsList.begin];
			bfsList.begin ++;

			nodeType *p = student[stuId];
			while(p != NULL){
				int gId = p->gid;

				int num = group[gId][0];
				for(int i=1; i<=num; ++i){
					if(visited[group[gId][i]] == 0){
						count ++;
						bfsList.list[++bfsList.end] = group[gId][i];
						visited[group[gId][i]] = 1;
					}
				}

				p = p->next;
			}

		}

		printf("%d\n", count);


		delete []bfsList.list;
		for(int i=0; i<m; ++i){
			delete group[i];
		}
		delete []group;

		for(int i=0; i<n+10; ++i){
			if(student[i] != NULL){
				nodeType *p = student[i];
				nodeType *q = NULL;
				while(p != NULL){
					q = p->next;
					delete p;
					p = q;
				}
			}
		}
		delete []student;
		delete []visited;
	}
	return 0;
}

