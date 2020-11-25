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
#define lowbit(x) (x&(-x))

using namespace std;

const int maxn = 100;
int N;
struct Node{
    int l, r;
}node[maxn]; 

int a[maxn]; // cnt array contains node index

#define L(x) (2*(x)+1)
#define R(x) (2*(x)+2)
#define pii pair<int, int>

int iscbt(int x){ // node index
    uu(i, 0, maxn) a[i] = -1;
    queue<pii> Q; // node index and cbt index
    int b[maxn] = {0};
    Q.push(make_pair(x, 0));
    b[0] = 1;
    while(!Q.empty()){
        pii t = Q.front(); Q.pop();
        int ni = t.first, ci = t.second;
        a[ci] = ni;

        if(node[ni].l != -1 and b[L(ci)] == 0){
            b[L(ci)] = 1;
            Q.push(make_pair(node[ni].l, L(ci)));
        }
        if(node[ni].r != -1 and b[R(ci)] == 0){
            b[R(ci)] = 1;
            Q.push(make_pair(node[ni].r, R(ci)));
        }

    }
    uu(i, 0, N){
        if(a[i] == -1) return false;
    }
    return true;
}

int isroot(int x){ // node index
    int b[maxn] = {0};
    queue<int> Q;
    Q.push(x);
    b[x] = 1;
    int cnt = 0;
    while(!Q.empty()){
        int t = Q.front(); Q.pop();
        cnt++;

        if(node[t].l != -1 and b[node[t].l] == 0){
            b[node[t].l] = 1;
            Q.push(node[t].l);
        }

        if(node[t].r != -1 and b[node[t].r] == 0){
            b[node[t].r] = 1;
            Q.push(node[t].r);
        }
    }
    return cnt == N;
}

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
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    cin >> N;
    uu(i, 0, N){
        string l, r;
        cin >> l >> r;
        if(l != "-"){
            sscanf(l.c_str(), "%d", &node[i].l);
        }
        else{
            node[i].l = -1;
        }
        if(r != "-"){
            sscanf(r.c_str(), "%d", &node[i].r);
        }
        else{
            node[i].r = -1;
        }
    }

    uu(i, 0, N){
        if(iscbt(i)){
            cout << "YES " << a[N-1] << endl;
            return 0;
        }
    }

    cout << "NO ";

    uu(i, 0, N){
        if(isroot(i)){
            cout << i << endl; 
            return 0;
        }
    }





    
    return 0;
}