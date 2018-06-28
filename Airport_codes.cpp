#include <bits/stdc++.h>
using namespace std;

vector<string> s;
vector<string> code;

int main(){
while(1){//start
	int n;
	cin >> n;
	if(n == 0) break;
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		s.push_back(tmp);
	}

	int max_k = 0;
	for(int i = 0; i < n; i++){
		string tmp = string() + s[i][0];
		for(int j = 0; j < (int)s[i].size() - 1; j++){
			if(s[i][j] == 'a' or s[i][j] == 'i' or s[i][j] == 'u' or s[i][j] == 'e' or s[i][j] == 'o') tmp += s[i][j + 1];
		}
		code.push_back(tmp);
		max_k = max(max_k, (int)tmp.size());
	}


	//pading
	for(int i = 0; i < n; i++){
		int len = (int)code[i].size();
		for(int j = 0; j < max_k - len; j++){
			code[i] += "A";
		}
	}


	int g_flag = 1;
	for(int i = 1; i <= max_k; i++){
		vector<string> temp;
		for(int j = 0; j < n; j++){
			temp.push_back(code[j].substr(0, i));//途中で方針変更したせいで考えた時間も合わせて１時間30分もかかってしまった。
		}
		sort(temp.begin(), temp.end());
		int flag = 1;
		for(int j = 1; j < n; j++){
			if(temp[j - 1] == temp[j]) flag = 0;
		}
		if(flag){
			cout << i << endl;
			g_flag = 0;
			break;
		}
	}


	if(g_flag) cout << -1 << endl;

	s.clear();
	code.clear();
}//end

	return 0;
}
