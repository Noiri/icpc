#include<bits/stdc++.h>
using namespace std;
//typedef pair<int, int> P;
vector<pair<int, pair<int, int> > > v;

int main(){
while(1){//start

	int H, W;
	cin >> H >> W;
	if(H == 0 and W == 0) break;
	int D = H * H + W * W;

	for(int h = 1; h <= 150; h++){
		for(int w = 1; w <= 150; w++){
			int d = h * h + w * w;
			if(D < d and h < w ) v.push_back(make_pair(d, make_pair(h, w)));
			else if(D == d and h < w and H < h) v.push_back(make_pair(d, make_pair(h, w)));
		}
	}

	sort(v.begin(), v.end());

	cout << v[0].second.first << " " << v[0].second.second << endl;

	//init
	v.clear();
}//end

	return 0;
}
