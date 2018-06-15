#include <bits/stdc++.h>
using namespace std;
typedef pair<double, string> P;

vector<pair<double, string> > v;

bool comp(P lhs, P rhs){
	if(lhs.first != rhs.first) return lhs.first > rhs.first;
	return lhs.second < rhs.second;
}

int main(){
while(1){	//strt
	int n;
	cin >> n;
	if(n == 0) break;
	for(int i = 0; i < n; i++){
		string l;
		int a, b, c, d, e, f, s, m, p;
		cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
		double T = a + b + c + m * (d + e);
		double money = m * f * s - p;
		//小数点以下を使用したいので倍した
		double Er = money / T;

		v.push_back(make_pair(Er, l));
	}

	sort(v.begin(), v.end(), comp);

	for(int i = 0; i < n; i++){
		cout << v[i].second << endl;
	}
	cout << "#" << endl;
	v.clear();
}//end
	return 0;
}
