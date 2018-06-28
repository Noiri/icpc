#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
while(1){//start
	int n, r;
	cin >> n >> r;
	if(n == 0 and r == 0) break;

	for(int i = 1; i <= n; i++) v.push_back(i);
	reverse(v.begin(), v.end());

	for(int i = 0; i < r; i++){
		stack<int> st;
		int p, c;
		cin >> p >> c;
		for(int j = 0; j < c; j++){
			st.push(v[p + j - 1]);
		}
		v.erase(v.begin() + p - 1, v.begin() + p + c - 1);

		reverse(v.begin(), v.end());
		while(st.size()){
			int tmp = st.top();
			st.pop();
			v.push_back(tmp);
		}
		reverse(v.begin(), v.end());
	}

	cout << v[0] << endl;
	v.clear();
}//end
	return 0;
}
