#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
	int n, m, t;
	cin >> n >> m >> t;

	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	//v.push_back(t);

	int ans = 0;
	//exeption
	ans += v[0] - m;

	for(int i = 1; i < n; i++){
		if(v[i] - v[i-1] > 2 * m) ans += (v[i] - v[i-1]) - 2 * m;
	}

	if(t - v[n-1] > m) ans += (t - v[n-1]) - m;

	cout << ans << endl;

	return 0;
}
