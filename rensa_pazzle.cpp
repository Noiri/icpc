#include <bits/stdc++.h>
using namespace std;

template <typename _Ty>
ostream& operator << (ostream& ostr, const vector<_Ty>& v) {
    if (v.empty()) {
        ostr << "{ }";
        return ostr;
    }
    ostr << "{" << v.front();
    for (auto itr = ++v.begin(); itr != v.end(); itr++) {
        ostr << ", " << *itr;
    }
    ostr << "}";
    return ostr;
}

int main(){
while(1){//start

	int h;
	cin >> h;
	if(h == 0) break;

	vector<vector<int> > v (5, vector<int>(h));
	for(int i = 0; i < h; i++){
		for(int j = 0; j < 5; j++){
			int tmp;
			cin >> tmp;
			v[j][i] = tmp;
		}
	}

	for(int i = 0; i < 5; i++){
		reverse(v[i].begin(), v[i].end());
	}



	int ans = 0;
for(int k = 0; k <= 11; k++){

	for(int i = 0; i < h; i++){
		if(v[0][i] == v[1][i] and v[0][i] == v[2][i] and v[0][i] == v[3][i] and v[0][i] == v[4][i]){
			ans += v[0][i] * 5;
			v[0][i] = 0;
			v[1][i] = 0;
			v[2][i] = 0;
			v[3][i] = 0;
			v[4][i] = 0;
		}
		else if(v[0][i] == v[1][i] and v[0][i] == v[2][i] and v[0][i] == v[3][i]){
			ans += v[0][i] * 4;
			v[0][i] = 0;
			v[1][i] = 0;
			v[2][i] = 0;
			v[3][i] = 0;
		}
		else if(v[1][i] == v[2][i] and v[1][i] == v[3][i] and v[1][i] == v[4][i]){
			ans += v[1][i] * 4;
			v[1][i] = 0;
			v[2][i] = 0;
			v[3][i] = 0;
			v[4][i] = 0;
		}
		else if(v[1][i] == v[2][i] and v[2][i] == v[3][i]){
			ans += v[1][i] * 3;
			v[1][i] = 0;
			v[2][i] = 0;
			v[3][i] = 0;
		}
		else if(v[0][i] == v[1][i] and v[1][i] == v[2][i]){
			ans += v[0][i] * 3;
			v[0][i] = 0;
			v[1][i] = 0;
			v[2][i] = 0;
		}
		else if(v[2][i] == v[3][i] and v[3][i] == v[4][i]){
			ans += v[2][i] * 3;
			v[2][i] = 0;
			v[3][i] = 0;
			v[4][i] = 0;
		}
	}

	for(int i = 0; i < 5; i++){
		v[i].erase(remove(v[i].begin(), v[i].end(), 0), v[i].end());
		v[i].resize(h);
	}
}
	cout << ans << endl;
	//init
	v.clear();

}//end

	return 0;
}
