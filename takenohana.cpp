#include <bits/stdc++.h>
using namespace std;
const int lim = 7368791;

int main(){
while(1){//start

	bool a[lim + 1];
	memset(a, 0, sizeof(a));

	int m, n;
	cin >> m >> n;
	int idx = m;
	if(m == 0 and n == 0) break;

	//敗因；全部なめた
	int cnt = 0;
	for(int i = m; cnt < n; i++){
		if(a[i] == 0){
			cnt++;
			for(int j = i; j <= lim; j += i){
				a[j] = 1;
			}
		}
	}


	for(int i = m; i <= lim; i++){
		if(a[i] == 0){
			cout << i << endl;
			break;
		}
	}

}//end

	return 0;
}
