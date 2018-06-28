#include<bits/stdc++.h>
using namespace std;

//operand, level
vector<pair<string, int> > v;

int main(){
	int n;
	cin >> n;

	int max_level = 0;
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		//count level and push
		int cnt = 0;
		for(int j = 0; j < (int)tmp.size(); j++){
			if(tmp[j] == '.') cnt++;
		}
		v.push_back(make_pair(string() + tmp[(int)tmp.size() - 1], cnt));
		max_level = max(max_level, cnt);
	}


	reverse(v.begin(), v.end());

	//for(int i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << endl;

	while(max_level >= 1){
		//get head and tail, make que
		cout << "max_level = " << max_level << endl;
		cout << "vec_size = " << v.size() << endl;
		int del_head = -1;
		int del_tail;
		int flag = 0;
		queue<int> que;
		string operand;
		for(int i = 0; i < (int)v.size(); i++){
			if(del_head == -1 and v[i].second == max_level){
				del_head = i;
				que.push(stoi(v[i].first));
			}
			else if(v[i].second == max_level){
				que.push(stoi(v[i].first));
				flag = 1;
			}
			else if(v[i].second == max_level - 1 and flag){
				operand = v[i].first;
				del_tail = i; //modified
				break;
			}
		}
//NTpmDM02
		v.erase(v.begin() + del_head, v.begin() + del_tail);

		//make place_holder
		int place_holder;
		if(operand == "+") place_holder = 0;
		else if(operand == "*") place_holder = 1;

		while(que.size()){
			cout << "que_size = " << que.size() << endl;
			int x = que.front();
			cout << "x = " << x << endl;
			que.pop();
			if(operand == "+") place_holder += x;
			else if(operand == "*") place_holder *= x;
		}
		v[del_head] = make_pair(to_string(place_holder), max_level - 1);
		cout << place_holder << endl;
		max_level--;
	}

	cout << v[0].first << endl;



	return 0;
}
