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
#include <iomanip>
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

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

#define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;

const int maxn = 200;

int N, K;
string S, E="ROM";

struct Edge{
    string from, to;
    int c; // cost
    Edge(string f, string t, int c):from(f), to(t), c(c){};
};

struct Node{
    string name;
    int hp; // happiniess;
    vector<Edge> edge;
};
map<string, int> Map;

vector<Node*> node;

Node *getnode(string name){
    if(Map.find(name) == Map.end()){
        int idx = node.size();
        Map[name] = idx;

        Node *re = new Node;
        re->name = name;

        node.push_back(re);
        return re;
    }
    else{
        return node[Map[name]];
    }
}

const int INF = 1e9;
int bk[maxn], bk_time[maxn], dis[maxn];
set<int> pre[maxn];

void init(){
    memset(bk, 0, sizeof(bk));
    memset(bk_time, 0, sizeof(bk_time));
    fill(dis, dis+maxn, INF);
    dis[Map[S]] = 0;
}

bool spfa(){
    init();
    queue<int> Q;
    Q.push(Map[S]);
    bk[Map[S]] = 1;
    bk_time[Map[S]]++;
    while(!Q.empty()){
        int from = Q.front(); Q.pop();
        bk[from] = 0;

        for(const auto& edge : node[from]->edge){
            int to = Map[edge.to], newdis = edge.c + dis[from];
            if(newdis < dis[to]){
                dis[to] = newdis;
                pre[to].clear();
                pre[to].insert(from);
                if(bk[to] == 0){
                    Q.push(to);
                    bk[to] = 1;
                    bk_time[to]++;
                    if(bk_time[to] > N) return false;
                }
            }
            else if(newdis == dis[to]){
                pre[to].insert(from);
            }
        }
    }   
    return true;
}

vector<vector<int>> re;
vector<int> tmp;

void init_dfs(){
    memset(bk, 0, sizeof(bk));
}

void dfs(int idx){
    #ifdef DEBUG
    pf("detect at idx = %d\n", idx);
    #endif
    bk[idx] = 1;
    tmp.push_back(idx);
    if(pre[idx].size() == 0){
        re.push_back(tmp);

        bk[idx] = 0;
        tmp.pop_back();
        return ;
    } 

    for(const auto & to : pre[idx]){
        if(bk[to] == 0){
            dfs(to);
        }
    }

    bk[idx] = 0;
    tmp.pop_back();
}


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    cin >> N >> K >> S;
    uu(i, 0, N-1){ // except start
        string name;
        int hp;
        cin >> name >> hp;
        Node *n = getnode(name);
        n->hp = hp;
    }
    
    uu(i, 0, K){
        string from, to;
        int c;
        cin >> from >> to >> c;
        Node *n1 = getnode(from), *n2 = getnode(to);
        n1->edge.push_back(Edge(from, to, c));
        n2->edge.push_back(Edge(to, from, c));
    }

    spfa();
    #ifdef DEBUG
    uu(i, 0, N){
        pf("pre[%d]:\n", i);
        for(const auto& u : pre[i]){
            pf("%d ", u);
        }
        cout << endl;
    }
    #endif
    dfs(Map[E]);

    #ifdef DEBUG
    pf("dis:\n");

    uu(i, 0, N){
        pf("%d ", dis[i]);
    }
    cout << endl;
    uu(j, 0, re.size()){
        pf("route %d:\n", j);
        dd(i, re[j].size()-1, -1){
            pf("%d ", re[j][i]);
        }
        cout << endl;
    }
    #endif




    return 0;
}