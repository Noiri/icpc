#include<bits/stdc++.h>
using namespace std;

int main(){
while(1){//start


	int N, M, r;
	//N；PC数　M；学生数
	cin >> N >> M;
	if(N == 0 and M == 0) break;
	cin >> r;


	//学生数、　時間
	int data[10004][721];
	for(int j = 0; j < 10004; j++){
		for(int k = 0; k < 721; k++) data[j][k] = 0;
	}


	for(int i = 0; i < r; i++){
		// t；時刻、　n;PC番号　m；学生番号　s；１ならログイン、０ならログアウト(配列中では逆)
		int t, n, m;
		bool s;
		cin >> t >> n >> m >> s;
		if(s) data[m][t - 539] += 1;
		else data[m][t - 539] += -1;
	}

	//累積和をとる
	for(int i = 0; i <= M; i++){
		for(int k = 1; k < 721; k++) data[i][k] = data[i][k] + data[i][k - 1];
	}


	//クエリを取得
	int qn;
	cin >> qn;
	for(int i = 0; i < qn; i++){
		int ts, tt, sn;
		cin >> ts >> tt >> sn;

		//学生について調査する
		int ans = 0;
		for(int j = ts - 539; j < tt - 539; j++){
			if(data[sn][j]) ans++;
		}
		cout << ans << endl;
	}

}//end

	return 0;
}
