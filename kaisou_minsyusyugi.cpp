#include<bits/stdc++.h>
using namespace std;
typedef string::const_iterator itr;

//<num>
//終了後イテレータは数字の次をさしていることに注意
int num(itr &begin){
	int res = 0;

	while(isdigit(*begin)){
		res *= 10;
		res += *begin - '0';
		begin++;
	}

	return res;
}

//再帰を書くということはグラフを表現することと同義

//BNFで記述すると再帰になるので再帰で実装する
//<expr> ::= [<left> <expr> <right>]*
int expr(itr &begin){
	begin++; //skip "["
	int ans;
	if(isdigit(*begin)){ //<expr> == <expr> つまり <expr> := <num>
		int res = num(begin);
		ans = res / 2 + 1;
	}
	else{ //otherwise
		vector<int> v; //階層ごとにベクターを生成
		while(*begin == '[') v.push_back(expr(begin)); //<right>は下の階層へ潜る演算子, <left>は上の階層に浮上する演算子、潜ったタイミングで要素を追加、浮上したタイミングで計算
		sort(v.begin(), v.end());
		int res = 0;
		for(int i = 0; i < (int)v.size() / 2 + 1; i++) res += v[i];
		ans = res;
	}


	begin++; //skip "]"
	return ans;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		itr begin = s.begin();
		cout << expr(begin) << endl;
	}

	return 0;
}
