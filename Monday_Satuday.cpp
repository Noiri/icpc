#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
while(1){//start
	int b;
	cin >> b;
	if(b == 1) break;
	for(int i = 2; i <= b; i++){
		bool flag = true;
		if((i % 7 == 1 or i % 7 == 6) and b % i == 0){
			for(int j = 2; j < i; j++){
				if((j % 7 == 1 or j % 7 == 6) and i % j == 0) flag = false;
			}
			if(flag) v.push_back(i);
		}
	}

	cout << b << ":";
	for(int i = 0; i < (int)v.size(); i++) cout << " " << v[i];
	cout << endl;
	v.clear();
}//end
	return 0;
}
