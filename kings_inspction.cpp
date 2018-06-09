#include <bits/stdc++.h>
using namespace std;

vector<int> keys;
vector<char> big;
vector<char> sml;

int main(){
	//make big and sml array
	for(int i = 0; i < 26; i++){
		big.push_back('Z' - i);
		sml.push_back('z' - i);
	}
	for(int i = 0; i < 26; i++){
		big.push_back('z' - i);
		sml.push_back('Z' - i);
	}
	for(int i = 0; i < 100; i++){
		big.push_back(big[i]);
		sml.push_back(sml[i]);
	}

while(1){//start

	//init
	keys.clear();

	int n;
	cin >> n;
	if(n == 0) break;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		keys.push_back(temp);
	}

	//extend keys
	for(int i = 0; i < 200; i++){
		int temp = keys[i];
		keys.push_back(temp);
	}

	string s;
	cin >> s;
	for(int i = 0; i < (int)s.size(); i++){
			char c;
			if(islower(s[i])){
				c = sml['z' - s[i] + keys[i]];
				cout << c;
			}

			else if(isupper(s[i])){
				c = big['Z' - s[i] + keys[i]];
				cout << c;
			}
	}
	cout << endl;

}//end

	return 0;
}
