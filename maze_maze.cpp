#include<bits/stdc++.h>
using namespace std;
const int INF = 999999;

int w, h;
int d[40][40];
int px[40][40];
int py[40][40];
queue<pair<int, int> > que;

void bfs(){
	//init rows=h, clumns=w
	/*
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++) d[i][j] = INF;
	}
	*/

	//get start point
	que.push(make_pair(0, 0));
	//init distance with start point
	d[0][0] = 1;


	//loop until queue is empty
	while(que.size()){
		int x = que.front().second;
		int y = que.front().first;
		que.pop();

		//cout << "d = " << d[y][x] << endl;
		//cout << "x = " << x << endl;
		//cout << "y = " << y << endl;

		//if x, y is goal, stop
		if(x == w - 1 and y == h - 1) break;

		//search around
		//up
		if(py[y - 1][x] == 0 and d[y - 1][x] == INF){
			que.push(make_pair(y - 1, x));
			d[y - 1][x] = d[y][x] + 1;
			//cout << "up" << endl;
		}
		//down
		if(py[y][x] == 0 and d[y + 1][x] == INF){
			que.push(make_pair(y + 1, x));
			d[y + 1][x] = d[y][x] + 1;
			//cout << "down" << endl;
		}
		//lf
		if(px[y][x - 1] == 0 and d[y][x - 1] == INF){
			que.push(make_pair(y, x - 1));
			d[y][x - 1] = d[y][x] + 1;
			//cout << "lf" << endl;
		}
		//rh
		if(px[y][x] == 0 and d[y][x + 1] == INF){
			que.push(make_pair(y, x + 1));
			d[y][x + 1] = d[y][x] + 1;
			//cout << "rh" << endl;
		}
	}

	return;
}

int main(){
while(1){//start

	int w, h;
	cin >> w >> h;
	if(w == 0 and h == 0) break;

	int idx = 0, idy = 0;
	for(int i = 0; i < 2*h - 1; i++){
		if(i % 2 == 0){
			for(int j = 0; j < w-1; j++){
				int tmp;
				cin >> tmp;
				px[idx][j] = tmp;
			}
			idx++;
		}
		else{
			for(int j = 0; j < w; j++){
				int tmp;
				cin >> tmp;
				py[idy][j] = tmp;
			}
			idy++;
		}
	}

	//init rows=h, clumns=w
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++) d[i][j] = INF;
	}

	bfs();

	/*
	//debug
	//cout << "px" << endl;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w - 1; j++) cout << px[i][j] << " ";
		cout << endl;
	}

	cout << endl;
	//cout << "py" << endl;
	for(int i = 0; i < h - 1; i++){
		for(int j = 0; j < w; j++) cout << py[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	//cout << "d" << endl;
	for(int i = 0; i < 31; i++){
		for(int j = 0; j < 31; j++) cout << d[i][j] << " ";
		cout << endl;
	}
	*/

	if(d[h-1][w-1] == INF) cout << 0 << endl;
	else cout << d[h-1][w-1] << endl;

}//end

	return 0;
}
