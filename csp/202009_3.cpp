// #include <bits/stdc++.h>
/*
注意点
1. 检测环用拓扑排序；
2. 检测到环仍然需要等待标准输入完毕后才进入下一轮；
3. 模拟题Dev-c++没有使用c++11，坑了一个晚上，操(无unordered_map/set, 无":"语法, 无auto, 无vector<vector<int>>)
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
// #include <unordered_map>
// #include <unordered_set>

// #define DEBUG

#define uu(i, a, b) for (int i = (a); i < (b); ++i)
#define dd(i, a, b) for (int i = (a); i > (b); --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;

using namespace std;

int Q, M, N, k, S;
vector<int> ipts[10000], opts[10000];

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
			for(int i = 0; i < v.size(); i++){
				ans &= v[i];
			}
			return ans;
		}
		else if(TYPE == "OR"){
			int ans = 0;
			for(int i = 0; i < v.size(); i++){
				ans |= v[i];
			}
			return ans;
		}
		else if(TYPE == "XOR"){
			int ans=0;
			for(int i = 0; i < v.size(); i++){
				ans ^= v[i];
			}
			return ans;
			
		}
		else if(TYPE == "NAND"){
			int ans = 1;
			for(int i = 0; i < v.size(); i++){
				ans &= v[i];
			}
			return !ans;

		}
		else if(TYPE == "NOR"){
			int ans = 0;
			for(int i = 0; i < v.size(); i++){
				ans |= v[i];
			}
			return !ans;			
		}
		else{
			pf("error unknown type of FUNC\n");
            return false;
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
	vector<Edge> edges;

	vector<int> map[3000]; // map[i][j] node i's j edges's idx
	Map(){
		n = 0;
		nodes.clear();
		edges.clear();
		uu(i, 0, 3000){
			map[i].clear();
		}
	}

	void addNode(string TYPE){ // map[2*i] and map[2*i+1]
		nodes.push_back(Node(TYPE));
		n += 1;
	}

	void addEdge(int from, int to){
		edges.push_back(Edge(from, to));
		edges.push_back(Edge(to, from));
		int num_edges = edges.size();
		map[2*from].push_back(num_edges-2);
		map[2*to+1].push_back(num_edges-1);
	}

	void init(){
		n = 0;
		nodes.clear();
		edges.clear();
		uu(i, 0, 3000){
			map[i].clear();
		}
	}

	int size(){
		return n;
	}

}m;

typedef pair<int ,int> P;

// topo sort
int indegree[3000], bk[3000];
bool isLoop(){
	memset(indegree, 0, sizeof(int) * m.size());
	memset(bk, 0, sizeof(int) * m.size());
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m.map[2*i].size(); j++){
			int edge = m.map[2*i][j], to = m.edges[edge].to;
			indegree[to]++;
		}
	}
	#ifdef DEBUG
	pf("indegree: ");
	for(int i = 0; i < m.size(); i++){
		pf("(%d, %d)", i+1, indegree[i]);
	}
	pf("\n");
	#endif
	int cnt = 0, sizen = m.size();
	while(1){
		int idx = -1;
		for(int i = 0; i < sizen; i++){
			if(indegree[i] == 0 and bk[i] == 0){
				bk[i] = 1;
				idx = i;
				cnt++;
				break;
			}
		}
		if(idx == -1 and cnt == sizen) return false;
		if(idx == -1 and cnt < sizen) return true;
		for(int i = 0; i < m.map[2*idx].size(); i++){
			int edge = m.map[2*idx][i], to = m.edges[edge].to;
			indegree[to] -= 1;
		}
		#ifdef DEBUG
		pf("find idx=%d: ", idx+1);
		for(int i = 0; i < m.size(); i++){
			pf("(%d, %d)", i+1, indegree[i]);
		}
		pf("\n");
		#endif
	}
}

void printmap(){
	for(int i = 0; i < m.size(); i++){
		printf("from %d -> ", i+1);
		for(int j = 0; j < m.map[2*i].size(); j++){
			int edge = m.map[2*i][j], to = m.edges[edge].to;
			printf(" %d", to+1);
		}
		printf("\n");
	}
}

map<pair<int, int>, int> record;

int DFS(int si, int idx){ // sith ipts
	// printf("si=%d, idx=%d\n", si, idx);
	if(record.find(pair<int, int>(si, idx)) != record.end()) return record[pair<int, int>(si, idx)];
	if(idx >= 0 and idx < M){ // it's ipts(M ipts)
		record[pair<int, int>(si, idx)] = ipts[si][idx];
		return ipts[si][idx];
	}
	else{
		std::vector<int> v;
		int num_ipts = m.map[2*idx+1].size();
		v.resize(num_ipts);
		for(int j = 0; j < m.map[2*idx+1].size(); j++){
			int edge = m.map[2*idx+1][j], to=m.edges[edge].to; //idx -> to 
			v[j] = DFS(si, to);
		}
		record[pair<int, int>(si, idx)] = m.nodes[idx].FUNC(v);
		return record[pair<int, int>(si, idx)];
	}

}

int main(){
    sf("%d", &Q);
	while(Q--){
		#ifdef DEBUG
		pf("new round\n");
		#endif
		m.init();
		record.clear();
		// M inputs and N elements
        sf("%d%d", &M, &N);
		for(int i = 0; i < M; i++){ // ipts 0 to M-1
			m.addNode("INPUT");
		}

		for(int i = 0; i < N; i++){ // elements M to M+N-1
			m.addNode("INPUT");
		}

		// describe N elements
		for(int i = 0; i < N; i++){
			// printf("i=%d\n",i);
			char FUNC[5], L[20];
			sf("%s", FUNC);
            sf("%d", &k);
			
			m.nodes[M+i].TYPE = FUNC;
			int to = M+i;
			// printf("to=%d\n",to);
			for(int j = 0; j < k; j++){
				// printf("j=%d ready to get string L\n",j);
				
                sf("%s", L);

                int idx = 0;
                // sscanf(L+1, "%d", &idx);
				for(int l = 1; L[l] != '\0'; l++){
					idx = idx * 10 + (L[l]-'0');
				}

				if(L[0] == 'O'){
					m.addEdge(M+idx-1, to);
				}
				else{
					m.addEdge(idx-1, to);
				}
			}
		}

		// judge loop
		#ifdef DEBUG
		printmap();
		#endif
		bool isloop=false;
		if(isLoop()){
			pf("LOOP\n");
			isloop=true;
			// continue;
		}

        sf("%d", &S);
		//run S times
		// ipts.resize(S); // ipts[S, M]
		for(int i = 0; i < S; i++){
			// M inputs
			ipts[i].resize(M);
			for(int j = 0; j < M; j++){
				int I;
                sf("%d", &I);
				ipts[i][j] = I;
			}
		}

		// opts.resize(S);  //opts[S][si]
		for(int i = 0; i < S; i++){
			int si; // 1 <= si <= N
			sf("%d", &si);
			opts[i].resize(si);
			// si outputs we want to check
			for(int j = 0; j < si; j++){
				int o;
				sf("%d", &o);
				opts[i][j] = o;
			}
		}
		if(!isloop){
			// run S times
			for(int i = 0; i < S; i++){
				for(int j = 0; j < opts[i].size(); j++){
					pf("%d", DFS(i, M+opts[i][j]-1)); // ith ipts in the DFS
					if(j != opts[i].size()-1) pf(" ");
				}
				pf("\n");
			}
		}

	}
	return 0;
}