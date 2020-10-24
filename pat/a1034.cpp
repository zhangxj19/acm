// #include <bits/stdc++.h>
// 2 options:
// 1) cin cout 
// 2) scanf printf
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

const int maxn = 1001;

int N, K;

struct Edge{
    int from, to, w;
    Edge(int from, int to, int w):from(from), to(to), w(w){};
};

struct Node{
    string name;
    int idx;
    vector<Edge> out;
    vector<Edge> in;
    vector<Edge> no; // no direction
};

map<string, int> M; // name to idx
vector<Node*> node; // must be a vecotr pointers

Node *getnode(string name){
    // create a new node if name is not in Map
    if(M.find(name) == M.end()){
        M[name] = node.size();
        Node *tmp = new Node;
        tmp->name = name;
        tmp->idx = node.size();
        node.push_back(tmp);
        #ifdef DEBUG
        pf("create new node (%d, %s)\n", tmp->idx, tmp->name.c_str());
        #endif
        return tmp;
    }
    else{
        #ifdef DEBUG
        pf("fetch a node (%d, %s)\n", node[M[name]]->idx, node[M[name]]->name.c_str());
        #endif
        return node[M[name]];
    }
}

set<int> bk;

int getroot(){
    uu(i, 0, node.size()){
        if(bk.find(i) == bk.end()) return i;
    }
    return -1;
}

vector<int> subnet(){
    int root = getroot();
    vector<int> re;
    if(root != -1){ // if root == -1, no nodes undetected any more.
        queue<int> Q;
        Q.push(root);
        bk.insert(root);
        while(!Q.empty()){
            int now = Q.front(); Q.pop();

            re.push_back(now);

            uu(i, 0, node[now]->no.size()){
                int to = node[now]->no[i].to;
                if(bk.find(to) == bk.end()){
                    Q.push(to);
                    bk.insert(to);
                }
            }
        }
    }
    return re;
}

#ifdef DEBUG
void printnet(vector<int> &v){
    int root = v[0];
    set<int> S, Sv;
    uu(i, 0, v.size()) Sv.insert(v[i]);
    if(root != -1){ // if root == -1, no nodes undetected any more.
        queue<int> Q;
        Q.push(root);
        S.insert(root);
        while(!Q.empty()){
            int now = Q.front(); Q.pop();

            cout << "(" << node[now]->idx << ", " << node[now]->name << ") ";

            uu(i, 0, node[now]->no.size()){
                int to = node[now]->no[i].to;
                if(S.find(to) == S.end() and Sv.find(to) != Sv.end()){
                    Q.push(to);
                    S.insert(to);
                }
            }
        }
    }
    cout << endl;
}
#endif

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2){
    return p1.first < p2.first;
}


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> N >> K;

    uu(i, 0, N){
        string name1, name2;
        cin >> name1 >> name2;
        int time;
        cin >> time;
        Node *n1 = getnode(name1), *n2 = getnode(name2);

        n1->out.push_back(Edge(n1->idx, n2->idx, time));  // n1->n2
        n2->in.push_back(Edge(n1->idx, n2->idx, time));

        n1->no.push_back(Edge(n1->idx, n2->idx, time));
        n2->no.push_back(Edge(n2->idx, n1->idx, time));
    }

    #ifdef DEBUG
    uu(i, 0, node.size()){
        pf("(%d, %s): ", i, node[i]->name.c_str());
        uu(j, 0, node[i]->no.size()){
            pf("(%d, %s) ", node[i]->no[j].to, node[node[i]->no[j].to]->name.c_str());
        }
        cout << endl;
    }
    #endif

    vector<int> sbn = subnet();
    vector<pair<string, int>> re;
    while(sbn.size() != 0){
        #ifdef DEBUG
        uu(i, 0, sbn.size()){
            pf("%d ", sbn[i]);
        }
        cout << endl;
        printnet(sbn);
        #endif

        int sum = 0;
        uu(i, 0, sbn.size()){
            uu(j, 0, node[sbn[i]]->out.size()){
                sum += node[sbn[i]]->out[j].w;
            }
        }
        if(sum > K and sbn.size() > 2){
            // find the boss of the gang and the number of the members;
            int maxw = INT_MIN, boss = -1;
            uu(i, 0, sbn.size()){
                int w = 0;
                uu(j, 0, node[sbn[i]]->out.size()){
                    w += node[sbn[i]]->out[j].w;
                }
                uu(j, 0, node[sbn[i]]->in.size()){
                    w += node[sbn[i]]->in[j].w;
                }
                if(w > maxw){
                    maxw = w;
                    boss = sbn[i];
                }
            }
            re.push_back(make_pair(node[boss]->name, sbn.size()));
        }

        sbn = subnet();
    }

    cout << re.size() << endl;
    sort(re.begin(), re.end(), cmp);
    uu(i, 0, re.size()){
        cout << re[i].first << " " << re[i].second << endl;
    }




    return 0;
}