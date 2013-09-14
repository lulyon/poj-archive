#include <iostream>
#include <queue>

bool state[1<<16];

int factor[4][4];

char str[4][10];

typedef struct{
	int state_num;
	int level;
}InfoType;

int flip(int state_num, int i, int j){

	bool flag;
	if(i>0){
		flag = ((state_num & factor[i-1][j])!=0);
		if(flag){
			state_num -= factor[i-1][j];
		}
		else{
			state_num += factor[i-1][j];
		}
	}

	if(i<3){
		flag = ((state_num & factor[i+1][j])!=0);
		if(flag){
			state_num -= factor[i+1][j];
		}
		else{
			state_num += factor[i+1][j];
		}
	}

	if(j>0){
		flag = ((state_num & factor[i][j-1])!=0);
		if(flag){
			state_num -= factor[i][j-1];
		}
		else{
			state_num += factor[i][j-1];
		}
	}

	if(j<3){
		flag = ((state_num & factor[i][j+1])!=0);
		if(flag){
			state_num -= factor[i][j+1];
		}
		else{
			state_num += factor[i][j+1];
		}
	}

	{
		flag = ((state_num & factor[i][j])!=0);
		if(flag){
			state_num -= factor[i][j];
		}
		else{
			state_num += factor[i][j];
		}
	}

	return state_num;
}

bool isWanted(int state_num){
	if(state_num == ((1<<16) - 1) || state_num == 0)return 1;
	else return 0;
}

void bfs(int state_num){
	InfoType tmpInfo, insertInfo;
	tmpInfo.state_num = state_num;
	tmpInfo.level = 0;
	state[state_num] = 1;

	std::queue<InfoType> Q;
	Q.push(tmpInfo);
	while(!Q.empty()){
		tmpInfo = Q.front();
		Q.pop();

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

					Q.push(insertInfo);
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
	memset(state, 0, sizeof(state));

	for(int i=0; i<4; ++i){
		scanf("%s", str[i]);
	}

	int snum = 0;
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			if(str[i][j]=='w'){
				snum += factor[i][j];
			}
		}
	}

	bfs(snum);

	return 0;
}