#include <iostream>

bool state[1<<16];

int factor[4][4];

char str[4][10];

typedef struct{
	int state_num;
	int level;
}InfoType;

InfoType Q[1<<16];

int flip(int state_num, int i, int j){

	if(i>0)state_num ^= factor[i-1][j];
	if(i<3)state_num ^= factor[i+1][j];

	if(j>0)state_num ^= factor[i][j-1];
	if(j<3)state_num ^= factor[i][j+1];
	
	state_num ^= factor[i][j];

	return state_num;
}

bool isWanted(int state_num){
	if(state_num == 0xffff || state_num == 0)return 1;
	else return 0;
}

void bfs(int state_num){
	InfoType tmpInfo, insertInfo;
	tmpInfo.state_num = state_num;
	tmpInfo.level = 0;
	state[state_num] = 1;

	int head, tail;
	head = tail = 0;
	Q[tail++] = tmpInfo;

	while(head<tail){
		tmpInfo = Q[head++];

		if(isWanted(tmpInfo.state_num)){
			printf("%d\n", tmpInfo.level);
			return;
		}

		for(int i=0; i<4; ++i){
			for(int j=0; j<4; ++j){
				state_num = flip(tmpInfo.state_num, i, j);
				if(!state[state_num]){
					insertInfo.level = tmpInfo.level + 1;
					insertInfo.state_num = state_num;
					state[state_num] = 1;

					Q[tail++] = insertInfo;
				}
			}
		}
	}

	printf("Impossible\n");
}


int main(int argc, char ** argv){
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			factor[i][j] = 1<<(i*4+j);
		}
	}

	for(int i=0; i<4; ++i){
		scanf("%s", str[i]);
	}

	int snum = 0;
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			if(str[i][j]=='w'){
				snum |= factor[i][j];
			}
		}
	}

	bfs(snum);

	return 0;
}
