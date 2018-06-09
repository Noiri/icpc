#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;
int arr[101][101];
int brr[101];
int crr[101];

int main(){
while(1){//start

	//init
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++){
			arr[i][j] = 0;
			brr[i] = 0;
			crr[i] = 0;
		}
	}
	v.clear();


	int n;
	cin >> n;
	if(n == 0) break;
	for(int i = 1; i <= n; i++){
		int m;
		cin >> m;
		for(int j = 0; j < m; j++){
			int temp;
			cin >> temp;
			arr[i][temp] = 1;
		}
	}

	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		int temp;
		cin >> temp;
		brr[temp] = 1;
		crr[temp] = 1;
	}


	for(int i = 1; i <= n; i++){
		int point = 0;
		for(int j = 1; j <= 100; j++){
			if(arr[i][j] and brr[j]){
				point++;
				crr[j] = 0;
			}
		}
		v.push_back(make_pair(point, i));
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	bool flag = false;
	for(int i = 0; i < 101; i++){
		if(crr[i]) flag = true;
	}

	if(flag) cout << -1 << endl;
	else if(v[0].first == v[1].first) cout << -1 << endl;
	else cout << v[0].second << endl;
}//end


	return 0;
}
