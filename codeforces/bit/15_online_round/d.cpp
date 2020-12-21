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

const int P = 998244353, maxn = 1e5+1, maxp = 1e6+1;

int isprime[maxp];

void makeprime(){
    fill(isprime, isprime+maxp, 1);
    isprime[0] = isprime[1] = 0;
    repu(i, 2, maxp){
        if(isprime[i]) for(int j = i + i; j < maxp; j+=i) isprime[j] = 0;
    }
}




struct Node{
    ll c;
    vi n;
    set<ll> fac;
    Node(){
        fac.clear();
    }
}node[maxn];


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


ll bk[maxn];

struct QueueElement{
    ll idx;
    ll re;
    set<ll> fac;
    QueueElement(){
        fac.clear();
    }
};

ll cal(ll re, set<ll>& fac_added, set<ll>& fac_add){
    #ifdef DEBUG
    cout << "new cal" << endl;
    cout << re << endl;
    each(x, fac_added) cout << x << " ";
    cout << endl;
    each(x, fac_add) cout << x << " ";
    cout << endl;
    #endif
    each(x, fac_add){
        if(fac_added.find(x) == fac_added.end()){
            re = re / x;
            re = re * (x - 1);
        }
    }
    return re;
}

set<ll> add_fac(set<ll>& f1, set<ll>& f2){
    set<ll> re;
    each(x, f1) re.insert(x);
    each(x, f2) re.insert(x);
    return re;
}

void solve(){
    ll n, p, q;
    cin >> n >> p >> q;
    makeprime();
    repu(i, 1, n+1){
        cin >> node[i].c;
        ll tc = node[i].c;
        for(int j = 2; j * j <= tc; ++j){
            if(tc %j == 0){
                while(tc % j == 0) tc /= j;
                node[i].fac.insert(j);
            }
            

            // if(isprime[j]){
            //     while(tc % j == 0){
            //         node[i].fac.insert(j);
            //         tc /= j;
            //     }
            // }
        }
        if(tc != 1) node[i].fac.insert(tc);
    }
    #ifdef DEBUG
    repu(i, 1, n+1){
        cout << node[i].c << " ";
        each(x, node[i].fac) cout << "(" << x << ") ";
        cout << endl;
    }
    #endif
    rep(i, n-1){
        ll u,v;
        cin >> u >> v;
        node[u].n.push_back(v);
        node[v].n.push_back(u);
    }
    #ifdef DEBUG
    // cout << ola(1000000) << endl;
    // repu(i, 1, 22) cout << "ola(" << i << ")=" << ola(i) << endl;
    #endif

    // find a route from u to v;

    queue<QueueElement> Q;
    QueueElement e;
    e.idx = p;
    e.re = node[p].c;
    e.re = cal(e.re, e.fac, node[p].fac);

    e.fac = node[p].fac;
    Q.push(e);

    bk[p] = 1;
    while(!Q.empty()){
        QueueElement x = Q.front(); Q.pop();
        if(x.idx == q){
            // cout << x.second << endl;
            ll re = x.re;
            cout << re << endl;
            return ;
        }

        each(y, node[x.idx].n){
            if(bk[y] == 0){
                #ifdef DEBUG
                // cout << node[y].c << " " << node[y].ola << endl;
                // pf("cx=%d, node[y[.c = %d, node[y].ola = %d\n", node[x.first].c, node[y].c, node[y].ola);
                #endif
                QueueElement e;
                e.idx = y;
                e.re = x.re * node[y].c % P;

                e.re = cal(e.re, x.fac, node[y].fac);

                e.fac = add_fac(x.fac, node[y].fac);
                Q.push(e);
                
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