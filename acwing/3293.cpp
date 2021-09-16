#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k, t, xl, yd, xr, yu, pass, stay;

bool isin(int x, int y){
	if(xl <= x and x <= xr and yd <= y and y <= yu){
		// cout << x << " " << y << " in sqaure "<< xl << " " << yd << " " << xr << " " << yu << endl;
		return true;
	}
	else return false;
}



int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> t >> xl >> yd >> xr >> yu;
	pass = stay = 0;

	while(n--){
		int cnt_in=0,cnt_consecutive=0;
		// cout << n << endl;
		for(int i = 0; i < t; i++){
			int x, y;
			cin >> x >> y;
			if(isin(x, y)){
				if(cnt_in == 0){
					pass += 1;
				}
				cnt_in += 1;
				cnt_consecutive += 1;
			}
			else{
				cnt_consecutive = 0;
			}
			if(cnt_consecutive >= k){
				stay += 1;
				for(int j = i+1; j < t; j++){
					cin >> x >> y;
				}
				break;
			}


		}


	}
	cout << pass << endl;
	cout << stay << endl;
}