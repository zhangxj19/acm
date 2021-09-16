#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

int Q, M, N, k, S;
vector<vector<int>> ipts, opts;

struct Node{
	string TYPE;
	Node(string t):TYPE(t){};
	bool FUNC(vector<int>& v){
		if(TYPE == "INPUT"){
			return v[0];
		}
		else if(TYPE == "NOT"){
			return !v[0];
		}
		else if(TYPE == "AND"){
			int ans = 1;
			for(const auto &num : v){
				ans &= num;
			}
			return ans;
		}
		else if(TYPE == "OR"){
			int ans = 0;
			for(const auto &num : v){
				ans |= num;
			}	
			return ans;
		}
		else if(TYPE == "XOR"){
			int ans=0;
			for(const auto &num : v){
				ans ^= num;
			}
			return ans;
			
		}
		else if(TYPE == "NAND"){
			int ans = 1;
			for(const auto &num : v){
				ans &= num;
			}
			return !ans;

		}
		else if(TYPE == "NOR"){
			int ans = 0;
			for(const auto &num : v){
				ans |= num;
			}	
			return !ans;			
		}
		else{
			cout << "error unknown type of FUNC" << endl;
		}
	}
};


struct Edge{
	int from, to;
	Edge(int f, int t):from(f), to(t){};
};


struct Map{
	int n; // M+N nodes; idx of inputs: i, idx of elements: i+M
	vector<Node> nodes;
	vector<Edge> edges, redges;

	vector<vector<int>> map, rmap; // map[i][j] node i's j edges's idx
	Map(){
		n = 0;
		nodes.clear();
		edges.clear();
		redges.clear();
		map.clear();
		rmap.clear();
	}
	void addNode(string TYPE){
		nodes.push_back(Node(TYPE));
		map.push_back(vector<int>());
		rmap.push_back(vector<int>());
		n += 1;
	}

	void addEdge(int from, int to){
		edges.push_back(Edge(from, to));
		int num_edges = edges.size();
		map[from].push_back(num_edges-1);

		redges.push_back(Edge(to, from));
		num_edges = redges.size();
		rmap[to].push_back(num_edges-1);
	}



	void init(){
		n = 0;
		nodes.clear();
		edges.clear();
	}

	int size(){
		return n;
	}

}m;

typedef pair<int ,int> P;


bool is_loop;

void dfs(int ipt, set<int>& S){
	S.insert(ipt);
	for(int j = 0; j < m.map[ipt].size(); j++){
		int edge = m.map[ipt][j], to = m.edges[edge].to;
		if(S.find(to) == S.end()){
			dfs(to, S);
		}
		else{
			is_loop = true;
		}
	}
	S.erase(ipt);
}


bool isLoop(){
	// cout << "start.." << endl;
	is_loop = false;
	set<int> S;
	for(int ipt = 0;  ipt < M; ipt++){
		S.clear();
		dfs(ipt, S);
		if(is_loop) break;
	}
	return is_loop;
}



void printmap(){
	for(int i = 0; i < m.size(); i++){
		printf("from %d -> ", i);
		for(int j = 0; j < m.map[i].size(); j++){
			int edge = m.map[i][j], to = m.edges[edge].to;
			printf(" %d", to);
		}
		printf("\n");
	}
}

int DFS(int si, int idx){
	// printf("si=%d, idx=%d\n", si, idx);
	if(idx >= 0 and idx < M){
		return ipts[si][idx];
	}
	else{
		std::vector<int> v;
		int num_ipts = m.rmap[idx].size();
		v.resize(num_ipts);

		for(int j = 0; j < m.rmap[idx].size(); j++){
			int edge = m.rmap[idx][j], to=m.edges[edge].from;
			v[j] = DFS(si, to);
		}
		
		return m.nodes[idx].FUNC(v);
	}

}

int main(){
	ios::sync_with_stdio(false);
	cin >> Q;
	// printf("Q=%d\n", Q);
	while(Q--){
		m.init();
		// M inputs and N elements
		cin >> M >> N;
		for(int i = 0; i < M; i++){
			m.addNode("INPUT");
		}

		for(int i = 0; i < N; i++){
			m.addNode("INPUT");
		}

		// describe N elements
		for(int i = 0; i < N; i++){
			// printf("i=%d\n",i);
			string FUNC, L;
			cin >> FUNC;
			cin >> k;
			
			m.nodes[i+M].TYPE = FUNC;
			// cout << FUNC << " " << k << endl;
			int to = i+M;
			// printf("to=%d\n",to);
			for(int j = 0; j < k; j++){
				// printf("j=%d ready to get string L\n",j);
				
				cin >> L;
				
				int idx = stoi(L.substr(1, L.size()-1));
				// printf("idx=%d\n", idx);
				// cout << L << endl;
				if(L[0] == 'O'){
					m.addEdge(idx+M-1, to);
				}
				else{
					m.addEdge(idx-1, to);
				}
			}
			// cout << endl;
		}

		// judge loop
		// cout << "before judge" << endl;
		// printmap();
		if(isLoop()){
			cout << "LOOP" << endl;
			continue;
		}

		//!judge loop


		// cout << "judege done.." << endl;
		cin >> S;
		//run S times
		ipts.resize(S);
		for(int i = 0; i < S; i++){
			// M inputs
			ipts[i].resize(M);
			for(int j = 0; j < M; j++){
				int I;
				cin >> I;
				ipts[i][j] = I;
			}
		}

		// cout << "ipts done" << endl;

		opts.resize(S);
		for(int i = 0; i < S; i++){
			int si; // 1 <= si <= N
			cin >> si;
			opts[i].resize(si);
			// si outputs we want to check
			for(int j = 0; j < si; j++){
				int o;
				cin >> o;
				opts[i][j] = o;
			}
		}
		// cout << "opts done" << endl;

		// run S times
		// cout << 'S' << S << endl;
		for(int i = 0; i < S; i++){
			// cout << i << " " <<endl;
			for(int j = 0; j < opts[i].size(); j++){
				// cout << "ready to run.." << endl;
				cout << DFS(i, opts[i][j]+M-1) << " ";
			}
			cout << endl;
		}
	}
}