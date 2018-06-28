#include<bits/stdc++.h>
using namespace std;

int h, w;

char maze[51][51];
int bm[51][51];
int wm[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfsB(int y, int x){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx and nx < w and 0 <= ny and ny < h and bm[ny][nx] == 0 and maze[ny][nx] == '.'){
			bm[ny][nx] = 1;
			dfsB(ny, nx);
		}
	}
	return;
}

void dfsW(int y, int x){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx and nx < w and 0 <= ny and ny < h and wm[ny][nx] == 0 and maze[ny][nx] == '.'){
			wm[ny][nx] = 1;
			dfsW(ny, nx);
		}
	}
	return;
}


int main(){
while(1){//start

	//init
	for(int i = 0; i < 50; i++){
		for(int j = 0; j < 50; j++){
			maze[i][j] = 'a';
			bm[i][j] = 0;
			wm[i][j] = 0;
		}
	}

	cin >> w >> h;
	if(w == 0 and h == 0) break;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++) cin >> maze[i][j];
	}

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(maze[i][j] == 'W') dfsW(i, j);
			if(maze[i][j] == 'B') dfsB(i, j);
		}
	}

	int ansb = 0;
	int answ = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(wm[i][j] == 0 and bm[i][j] == 1) ansb += 1;
			if(bm[i][j] == 0 and wm[i][j] == 1) answ += 1;
		}
	}

	cout << ansb << " " << answ << endl;
}//end
	return 0;
}
