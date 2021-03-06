// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
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

typedef long long ll;
const double eps = 1e-8;
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}
#define lowbit(x) (x&(-x));

// #define DEBUG
// #define LOCAL

using namespace std;
const int maxk = 1001, maxn = 21;
int N, M, K, Q, a[maxk], q[maxn];

struct Node{
    int p, end;
}node[maxk];

struct Window{
    int end, pop;
    queue<int> q;
}w[maxn];

int minute(int &h, int &m){
    return h*60 + m;
}
const int begt = 8*60, endt = 17*60;

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("o", "w", stdout);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    // cout << setw(2) << setfill('0');  // add this every time cout int with width and left padding '0'

    cin >> N >> M >> K >> Q;
    // sf("%d%d%d%d", &N, &M, &K, &Q);
    uu(i, 0, K){
        cin >> node[i].p;
        // sf("%d", &node[i].p);
    }
    // init
    uu(i, 0, N){
        w[i].end = begt;
        w[i].pop = begt;
    }
    int idx = 0;

    uu(i, 0, _min(M*N, K)){
        int wid = idx % N;
        w[wid].q.push(idx); 
        w[wid].end += node[idx].p;
        node[idx].end = w[wid].end;  

        if(idx < N) w[wid].pop = node[idx].end;

        idx++;
    }

    uu(i, idx, K){
        int minpop = INT_MAX, id;
        uu(j, 0, N) if(w[j].pop < minpop) minpop = w[id=j].pop;

        w[id].q.pop();
        w[id].q.push(i);
        w[id].end += node[i].p;
        node[i].end = w[id].end;
        w[id].pop = node[w[id].q.front()].end;
    }


    while(Q--){
        int x;
        cin >> x;
        x--;
        if(node[x].end - node[x].p >= endt){
            cout << "Sorry" << endl;
            // pf("Sorry\n");
        }
        else{
            cout << setw(2)<< setfill('0') << (node[x].end) / 60 << ":" << setw(2)<< setfill('0') << (node[x].end) % 60 << endl;
            // pf("%02d:%02d\n", node[x].end/60, node[x].end%60);
        }
    }


    
    return 0;
}