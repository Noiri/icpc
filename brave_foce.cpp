#include <bits/stdc++.h>
using namespace std;
const int INF = 999999;


queue<pair<int, int> > que;
int maze[300][300];
int d[300][300];
int dx[6] = {0, 1, 1, 0, -1, -1};
int dy[6] = {1, 1, 0, -1, -1, 0};


//今回 arr[y][x] で設計する
void bfs(int sx, int sy){
	que.push(make_pair(sy, sx));
	d[sy][sx] = 0;


	while(que.size()){
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		//seach around
		for(int i = 0; i < 6; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(0 <= ny and ny < 300 and 0 <= nx and nx < 300 and d[ny][nx] == INF and maze[ny][nx]){
				que.push(make_pair(ny, nx));
				d[ny][nx] = d[y][x] + 1;
			}
		}
	}
}

int main(){
while(1){//start
	int t, n;
	cin >> t >> n;
	if(t == 0 and n == 0) break;

	//init
	for(int i = 0; i < 300; i++){
		for(int j = 0; j < 300; j++){
			d[i][j] = INF;
			maze[i][j] = 1;
		}
	}

	//0なら移動不可　1なら移動可能
	for(int i = 0; i < n; i++){
		int tx, ty;
		cin >> tx >> ty;
		maze[ty + 150][tx + 150] = 0;
	}
	int sx, sy;
	cin >> sx >> sy;

	bfs(sx + 150, sy + 150);

	int cnt = 0;
	for(int i = 0; i < 300; i++){
		for(int j = 0; j < 300; j++){
			if(d[i][j] <= t) cnt++;
		}
	}

	cout << cnt << endl;
}//end
	return 0;
}
