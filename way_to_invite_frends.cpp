#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int data[N];

int main(){
	int n;
	cin >> n;

	//input
	for(int i = 1; i <= n; i++){
		int r, l;
		cin >> r >> l;
		for(int j = r; j <= l; j++) data[j]++;
	}

	//debug
	//for(int i = 1; i < 10; i++) cout << "arr = " << data[i] << endl;

	int ans = 0;
	for(int i = 1; i <= N; i++){
		int ok = data[i];
		if(ok + 1 >= i) ans = max(ans, i);
	}

	cout << ans - 1 << endl;

	return 0;
}
