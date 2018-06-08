#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(getline(cin, s), s != "."){
			stack<char> st;
			bool flag = true;
			for(int i = 0; i < (int)s.size(); i++){
				if(s[i] == '(' ) st.push('(');
				else if(s[i] == '[' ) st.push('[');

				if(s[i] == ')' ){
					if(st.empty() or st.top() != '('){
						flag = false;
						break;
					}
					if(!st.empty()) st.pop();
				}
				else if(s[i] == ']' ){
					if(st.empty() or st.top() != '['){
						flag = false;
						break;
					}
					if(!st.empty()) st.pop();
			}
		}
		if(!st.empty()) flag = false;
		if(flag) cout << "yes" << endl;
		else cout << "no" << endl;
		while(!st.empty()) st.pop();
	}
	return 0;
}
