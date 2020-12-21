// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
// override the () operator
// struct cmp{
//     bool operator()(const T &a, const T &b) const{
//         return ;
//     }
// };
// some useful functions:
// unique(it1, it2) upper_bound(it1, it2) lower_bound(it1, it2) equal_range(it1, it2)
// next_permutation(it1, it2)
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

#define rep(i, n) for (int i = 0, size = (n); i < size; ++i)
#define repu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define repd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define each(it, a) for(auto & (it) : (a))
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define lowbit(x) (x&(-x))
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

template<typename T>
void print(vector<T> &v){
    rep(i, v.size()){
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

template<typename T>
void print(T* begin, T* end){
    for(T *p = begin; p != end; ++p){
        if(p == begin) cout << *p;
        else cout << " " << *p;
    }
    cout << endl;
}

template<typename T>
T sum(T* begin, T* end){
    T re = 0;
    for(T *p = begin; p != end; ++p) re = re + *p;
    return re;
}

// template<typename T>
// T sum(typename vector<T>::iterator begin, typename vector<T>::iterator end){
//     T re = 0;
//     for(auto p = begin; p != end; ++p) re = re + *p;
//     return re;
// }
int sum(vector<int>::iterator begin, vector<int>::iterator end){
    int re = 0;
    for(auto p = begin; p != end; ++p) re = re + *p;
    return re;
}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){
    ll re = 0;
    for(auto p = begin; p != end; ++p) re = re + *p;
    return re;
}

const int P = 998244353, maxn = 1e5+1;

struct Node{
    int c;
    vi n;
    ll ola;
    ll isprime;
}node[maxn];

int isprime(int x){
    if(x <= 1)return 0;
    repu(i, 2, sqrt(x)+1){
        if(x % i == 0) return 0;
    }
    return 1;
}

long long ola(long long n) {
    long long res = n;
    for(int i = 2; i*i <=n; i++){
        if(n%i == 0) {
            res -= res/i;
            while(n%i == 0)
				n /= i;
        }
    }
    if(n>1)
		return res -= res/n;
    return res;
}


int bk[maxn];

void solve(){
    int n, p, q;
    cin >> n >> p >> q;
    repu(i, 1, n+1){
        cin >> node[i].c;
        // node[i].ola = node[i].ola = ola(node[i].c);
        // node[i].isprime = isprime(node[i].c);
        // if(node[i].isprime) node[i].ola = ola(node[i].c);
        // else node[i].ola = 1;
    }
    int root = 0;
    rep(i, n-1){
        int u,v;
        cin >> u >> v;
        node[u].n.push_back(v);
        node[v].n.push_back(u);
    }
    #ifdef DEBUG2
    // cout << ola(1000000) << endl;
    // repu(i, 1, 22) cout << "ola(" << i << ")=" << ola(i) << endl;
    #endif

    // find a route from u to v;
    queue<pll> Q;

    // Q.push(make_pair(p, node[p].ola));
    Q.push(make_pair(p, node[p].c));

    bk[p] = 1;
    while(!Q.empty()){
        pll x = Q.front(); Q.pop();
        if(x.first == q){
            // cout << x.second << endl;
            cout << ola(x.second) << endl;
            return ;
        }

        each(y, node[x.first].n){
            if(bk[y] == 0){
                #ifdef DEBUG
                // cout << node[y].c << " " << node[y].ola << endl;
                // pf("cx=%d, node[y[.c = %d, node[y].ola = %d\n", node[x.first].c, node[y].c, node[y].ola);
                #endif
                Q.push(make_pair(y, x.second * node[y].c % P));
                // Q.push(make_pair(y, x.second * node[y].ola % P));
            }
        }

    }







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
    solve();
    
    return 0;
}