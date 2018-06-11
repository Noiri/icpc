#include <bits/stdc++.h>
using namespace std;
const int N = 400000;
int for_erat[N];
vector<int> prime;
vector<int> v;
vector<int> res;


void erat(){
    for(int i = 0; i < N; i++){
        for_erat[i] = 1;
    }
    for(int i = 2; i < sqrt(N); i++){
        if(for_erat[i]){
            for(int j = 0; i * (j + 2) < N; j++){
                for_erat[i *(j + 2)] = 0;
            }
        }
    }

    for(int i = 2; i < N; i++){
        if(for_erat[i]){
            prime.push_back(i);
        }
    }
}

int main(){
	erat();

while(1){//start
	//init
	v.clear();
	res.clear();


	int n, p;
	cin >> n >> p;
	if(n == -1 and p == -1) break;

	//n以上の素数を15個見つける
	int idx = 0;
	while((int)v.size() != 50){
		if(prime[idx] > n) v.push_back(prime[idx]);
		idx++;
	}

	for(int i = 0; i < (int)v.size(); i++){
		for(int j = i; j < (int)v.size(); j++) res.push_back(v[i] + v[j]);
	}

	sort(res.begin(), res.end());
	//res.erase(unique(res.begin(), res.end()), res.end());

	cout << res[p-1] << endl;
	//for(int i = 0; i < (int)res.size(); i++) cout << res[i] << endl;


}//end
	return 0;

}
