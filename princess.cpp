#include <bits/stdc++.h>
using namespace std;
const int Ex = 11;
vector<int> v;

int main(){
while(1){//start
	int n, m;
	cin >> n >> m;
	if(n == 0 and m == 0) break;
	v.resize(Ex);

	//input data
	for(int i = 0; i < n; i++){
		int d, p;
		cin >> d >> p;
		v[p] += d;
	}

	//sub
	for(int i = 10; i > 0; i--){
		if(m - v[i] >= 0){
			m -= v[i];
			v[i] = 0;
		}
		else{
			v[i] -= m;
			break;
		}
	}

	//cluc
	int ans = 0;
	for(int i = 10; i > 0; i--){
		ans += i * v[i];
	}

	cout << ans << endl;
	v.clear();
}//end
	return 0;
}
