#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, X, Y;

struct Node{
	int idx;
	ll d;
	Node(){
		idx=202;
	}
};

ll dis(int x, int y){
	return (X-x)*(X-x) + (Y-y)*(Y-y);
}

bool cmp(Node& n1, Node& n2){
	if(n1.d < n2.d) return true;
	else if(n1.d > n2.d) return false;
	else{
		if(n1.idx < n2.idx) return true;
		else return false;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> X >> Y;
	vector<Node> nodes(n, Node());
	for(int i = 0; i < n; i++){
		int x,y;
		cin >> x >> y;
		nodes[i].idx = i+1;
		nodes[i].d = dis(x, y);
	}

	sort(nodes.begin(), nodes.end(), cmp);
	// for(const auto & n : nodes){
	// 	cout << n.d << " " << n.idx << endl;
	// }
	for(int i = 0; i < 3; i++){
		cout << nodes[i].idx << endl;
	}

}