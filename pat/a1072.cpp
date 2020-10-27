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

// #define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;

const int maxn = 1e3 + 1 + 10, INF = 1e9;
int N, M, K, Ds; // 1 to N , g1 to gm

struct Edge{
    int from, to, d;
    Edge(int f, int t, int d): from(f), to(t), d(d){};
};

struct Node{
    int d;
    vector<Edge> edge;
}node[maxn];

int bk[maxn], bk_time[maxn], dis[maxn];
queue<int> Q;

void init(int S){
    fill(dis, dis+maxn, INF);
    dis[S] = 0;
    memset(bk, 0, sizeof(bk));
    memset(bk_time, 0, sizeof(bk_time));
    while(!Q.empty()) Q.pop();
}

int nextu(){
    int re = -1, mind = INT_MAX;
    uu(i, 1, N+M+1){
        if(bk[i] == 0 and dis[i] < mind){
            mind = dis[i];
            re = i;
        }
    }
    bk[re] = 1;
    return re;
}

void Dijkstra(int S){
    init(S);
    uu(i, 0, N+M){
        int from = nextu();
        uu(j, 0, node[from].edge.size()){
            int to = node[from].edge[j].to, newdis = node[from].edge[j].d + dis[from];
            if(newdis < dis[to]){
                dis[to] = newdis;
            }
        }
    }
}

bool spfa(int S){
    init(S);
    Q.push(S);
    bk[S] = 1;
    bk_time[S]++;
    while(!Q.empty()){
        int from = Q.front(); Q.pop();
        bk[from] = 0;
        uu(i, 0, node[from].edge.size()){
            int to = node[from].edge[i].to, newdis = node[from].edge[i].d + dis[from];
            if(newdis < dis[to]){
                dis[to] = newdis;
                if(bk[to] == 0){
                    Q.push(to);
                    bk[to] = 1;
                    bk_time[to]++;
                    if(bk_time[to] > (N+M+1)) return false;
                }
            }
        }

    }
    return true;
}


struct Re{
    string name;
    int idx;
    double mindis, avgdis;
    Re(string n, double md, double ad):name(n), mindis(md), avgdis(ad){
        sscanf(name.c_str(), "G%d", &idx);
    };
};
vector<Re> re;
bool cmp(const Re &r1, const Re &r2){
    if(!equ(r1.mindis, r2.mindis)) return r1.mindis > r2.mindis;
    else if(!equ(r1.avgdis, r2.avgdis)) return r1.avgdis < r2.avgdis;
    else{
        return r1.idx < r2.idx;
    }
    // if(!equ(r1.avgdis, r2.avgdis)) return r1.avgdis < r2.avgdis;
    // else{
    //     return r1.name < r2.name;
    // }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    cout << setiosflags(ios::fixed);
    cout << setprecision(1);

    cin >> N >> M >> K >> Ds;
    uu(i, 0, K){
        string p1, p2; // index of candidate gx is x + N
        cin >> p1 >> p2;
        int x, y, d;
        if(p1[0] == 'G'){
            sscanf(p1.c_str(), "G%d", &x);
            x += N;
        }
        else{
            sscanf(p1.c_str(), "%d", &x);
        }
        if(p2[0] == 'G'){
            sscanf(p2.c_str(), "G%d", &y);
            y += N;
        }
        else{
            sscanf(p2.c_str(), "%d", &y);
        }
        cin >> d;
        node[x].edge.push_back(Edge(x, y , d));
        node[y].edge.push_back(Edge(y, x , d));
    }

    uu(i, 1, M+1){
        spfa(i+N);
        // Dijkstra(i+N);
        #ifdef DEBUG
        pf("G%d:\n", i);
        uu(j, 1, M+N+1){
            pf("%d ", dis[j]);
        }
        cout << endl;
        #endif
        double mindis = INF;
        double avgdis = 0;
        int cnt = 0;
        uu(j, 1, N+1){
            if(dis[j] <= Ds){
                avgdis += dis[j];
                if(dis[j] < mindis) mindis = dis[j];
                cnt++;
            }
        }
        if(cnt == N){
            // avgdis = avgdis * 1000 / cnt;
            avgdis /= cnt;
            re.push_back(Re("G" + to_string(i), mindis, avgdis));
        }
    }

    if(re.size() == 0){
        cout << "No Solution" << endl;
    }
    else{
        sort(re.begin(), re.end(), cmp);
        cout << re[0].name << endl;
        cout << re[0].mindis << " " << re[0].avgdis << endl;
    }


    
    return 0;
}