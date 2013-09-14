#include<iostream>
using namespace std;

typedef struct Node{
	bool visit[26];
	struct Node *children[26];
	char *key[26];
}TrieNode;
TrieNode *Trie;
char Triekey[100010][15];

void Tinit(TrieNode *&T){
	T = new TrieNode;
	for(int i=0; i<26; ++i){
		T->visit[i]=0;
		T->children[i]=0;
	}
	
}

void Tinsert(char *str, char *key){
	int length = strlen(str);
	TrieNode *p = Trie;
	TrieNode *q = 0;
	int index;
	for(int i=0; i<length; ++i){
		index = str[i]-'a';
		if(i<length-1){
			q = p->children[index];
			if(q==0){
				Tinit(q);
				p->children[index] = q;
				p = q;
			}
			else{
				p = q;
			}
		}
		else{
			p->visit[index]=1;
			p->key[index] = key;
			return;
		}
	}
}

char *Tsearch(char *str){
	int length = strlen(str);
	TrieNode *p = Trie;
	int index;
	for(int i=0; i<length; ++i){
		index =  str[i]-'a';
		if(p==0)return 0;
		if(i<length-1)p = p->children[index];
		else{
			if(p->visit[index]==1){
				return p->key[index];
			}
			else{
				return 0;
			}
		}
	}
}

int main(){
	char buffer[50];
	char str[15];
	int i=0;
	Tinit(Trie);
	while(gets(buffer) && strcmp(buffer,"")!=0){
		sscanf(buffer, "%s%s",Triekey[i], str);
		Tinsert(str,Triekey[i]);
		++i;
	}
	while(scanf("%s",str)!=EOF){
		char *key = Tsearch(str);
		if(key==0)printf("eh\n");
		else printf("%s\n",key);
	}
	
	return 0;
}

