// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
#include <cmath>
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
#include <stack>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

// #define DEBUG

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;

bool equ(double a, double b){
    return fabs(a-b) < eps;
}

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return a/gcd(a, b)*b;
}

using namespace std;

int x, y;

struct Node{
    int id, idx;
    vector<int> nei; // push idx not id
};

vector<Node*> node;
map<int, int> M; // id to idx, idx is the index of node

Node *getnode(int id){
    if(M.find(id) == M.end()){
        Node *tmp = new Node;
        tmp->id = id;
        tmp->idx = node.size();
        M[id] = tmp->idx;
        node.push_back(tmp);
        return tmp;
    }
    else{
        return node[M[id]];
    }
}

int *bk, re;
void dfs(int idx){
    bk[idx] = 1;
    uu(i, 0, node[idx]->nei.size()){
        int to = node[idx]->nei[i];
        if(bk[to] == 0){
            dfs(to);
        }
    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    while(cin >> x >> y){
        Node *n1 = getnode(x), *n2 = getnode(y);
        if(x != y){
            n1->nei.push_back(n2->idx);
            n2->nei.push_back(n1->idx);
        }
        else{
            n1->nei.push_back(n1->idx);

        }

    }

    #ifdef DEBUG
    uu(i, 0, node.size()){
        pf("(%d, %d): ", node[i]->idx, node[i]->id);
        uu(j, 0, node[i]->nei.size()){
            int to = node[i]->nei[j];
            pf("(%d, %d) ", node[to]->idx, node[to]->id);
        }
        cout << endl;
    }
    #endif
    bk = new int[node.size()];
    memset(bk, 0, sizeof(int) * node.size());
    uu(i, 0, node.size()){
        if(bk[i] == 0){
            dfs(i);
            re++;
        }
    }
    cout << re << endl;

    return 0;
}