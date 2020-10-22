// #include <bits/stdc++.h>
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
	// Node(string t):TYPE(t){};
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


// struct Edge{
// 	int from, to;
// 	Edge(int f, int t):from(f), to(t){};
// };


// struct Map{
// 	int n; // M+N nodes; idx of inputs: i, idx of elements: i+M
// 	vector<Node> nodes;
// 	vector<Edge> edges;

// 	vector<int> map[3000]; // map[i][j] node i's j edges's idx
// 	Map(){
// 		n = 0;
// 		nodes.clear();
// 		edges.clear();
// 		uu(i, 0, 3000){
// 			map[i].clear();
// 		}
// 	}

// 	void addNode(string TYPE){ // map[2*i] and map[2*i+1]
// 		nodes.push_back(Node(TYPE));
// 		n += 1;
// 	}

// 	void addEdge(int from, int to){
// 		edges.push_back(Edge(from, to));
// 		edges.push_back(Edge(to, from));
// 		int num_edges = edges.size();
// 		#ifdef DEBUG
// 		if(2*to + 1 >= map.size() or 2*from >= map.size()){
// 			pf("map size = %d, [%d,%d], 2*from=%d, 2*to+1=%d\n", (int)map.size(), from, to, 2*from, 2*to+1);
// 			return;
// 		}
// 		#endif
// 		map[2*from].push_back(num_edges-2);
// 		map[2*to+1].push_back(num_edges-1);
// 	}

// 	void init(){
// 		n = 0;
// 		nodes.clear();
// 		edges.clear();
// 		uu(i, 0, 3000){
// 			map[i].clear();
// 		}
// 	}

// 	int size(){
// 		return n;
// 	}

// }m;

// typedef pair<int ,int> P;

// bool is_loop;

// void dfs(int ipt, set<int>& S){
// 	S.insert(ipt);
// 	for(int j = 0; j < m.map[2*ipt].size(); j++){
// 		int edge = m.map[2*ipt][j], to = m.edges[edge].to;
// 		if(S.find(to) == S.end()){
// 			dfs(to, S);
// 		}
// 		else{
// 			is_loop = true;
// 		}
// 	}
// 	S.erase(ipt);
// }

// bool isLoop(){
// 	is_loop = false;
// 	set<int> S;
// 	for(int ipt = 0;  ipt < M; ipt++){
// 		S.clear();
// 		dfs(ipt, S);
// 		if(is_loop) break;
// 	}
// 	return is_loop;
// }

// void printmap(){
// 	for(int i = 0; i < m.size(); i++){
// 		printf("from %d -> ", i+1);
// 		for(int j = 0; j < m.map[2*i].size(); j++){
// 			int edge = m.map[2*i][j], to = m.edges[edge].to;
// 			printf(" %d", to+1);
// 		}
// 		printf("\n");
// 	}
// }

// map<pair<int, int>, int> record;

// int DFS(int si, int idx){ // sith ipts
// 	// printf("si=%d, idx=%d\n", si, idx);
// 	if(record.find(pair<int, int>(si, idx)) != record.end()) return record[pair<int, int>(si, idx)];
// 	if(idx >= 0 and idx < M){ // it's ipts(M ipts)
// 		record[pair<int, int>(si, idx)] = ipts[si][idx];
// 		return ipts[si][idx];
// 	}
// 	else{
// 		std::vector<int> v;
// 		int num_ipts = m.map[2*idx+1].size();
// 		v.resize(num_ipts);
// 		for(int j = 0; j < m.map[2*idx+1].size(); j++){
// 			int edge = m.map[2*idx+1][j], to=m.edges[edge].to; //idx -> to 
// 			v[j] = DFS(si, to);
// 		}
// 		record[pair<int, int>(si, idx)] = m.nodes[idx].FUNC(v);
// 		return record[pair<int, int>(si, idx)];
// 	}

// }
int main(){
    // scanf("%d", &Q);
	// while(Q--){
        // scanf("%d%d", &M, &N);
		// for(int i = 0; i < N; i++){
		// 	scanf("%s", FUNC);
        //     scanf("%d", &k);
		// 	for(int j = 0; j < k; j++){
        //         scanf("%s", L);
		// 	}
		// }
        // scanf("%d", &S);

		// ipts.resize(S); // ipts[S, M]
		// for(int i = 0; i < S; i++){
		// 	// M inputs
		// 	ipts[i].resize(M);
		// 	for(int j = 0; j < M; j++){
		// 		int I;
        //         scanf("%d", &I);
		// 	}
		// }

		// opts.resize(S);  //opts[S][si]
		// for(int i = 0; i < S; i++){
		// 	int si; // 1 <= si <= N
		// 	scanf("%d", &si);
		// 	opts[i].resize(si);
		// 	// si outputs we want to check
		// 	for(int j = 0; j < si; j++){
		// 		int o;
		// 		scanf("%d", &o);
		// 	}
		// }

		// // run S times
		// for(int i = 0; i < S; i++){
		// 	for(int j = 0; j < opts[i].size(); j++){
				
		// 		if(j != opts[i].size()-1) printf(" ");
		// 	}
		// 	printf("\n");
		// }
	// }
	return 0;
}