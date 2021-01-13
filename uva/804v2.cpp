// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
// 5) use cout << '\n'; instead of cout << endl; (cout << endl is really slow)
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
#include <numeric>
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
#define pll pair<ll, ll>

using namespace std;

struct UF{
    vi f, sz; // father and component size
    int cnt; // set number 
    UF(int n): cnt(n), f(n), sz(n,1){
        rep(i, n){f[i] = i;}
    }

    int find(int x){
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    bool unite(int x, int y){
        x=find(x), y=find(y);
        if(x==y) return false;
        else{
            if(sz[x] < sz[y]) swap(x, y);
            f[y] = x;
            sz[x] += sz[y];
            cnt--;
            return true;
        }
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

};

int lowerbound(vector<int>& a, int x){
    int l = 0, r = a.size() -1 ;
    while(l < r){
        int m = (l + r) >> 1;
        if(a[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

template<typename T>
void print(vector<T> &v){rep(i, v.size()){if(i != 0) cout << " "; cout << v[i];}cout << '\n';}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p != begin) cout << " "; cout << *p;}cout << '\n';}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){ll re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}

const int maxn = 100;

struct Palace{
    int d;
    unordered_map<int, int> opt, ipt;
};

struct Transition{
    int need;
    unordered_map<int, int> opt, ipt;
};



void solve(){
    int np, kcase = 0;
    while(cin >> np && np != 0){
        cout << "Case " << ++kcase << ": ";
        vector<Palace> p(np);
        rep(pid, np){
            cin >> p[pid].d;
        }
        int nt;
        cin >> nt;
        vector<Transition> t(nt);
        unordered_map<int, int> inputs; // for transitions
        rep(tid, nt){
            int pid;
            while(cin >> pid){
                if(pid == 0) break;
                if(pid > 0){ // tran to palace
                    pid--;
                    t[tid].opt[pid]++;
                    p[pid].ipt[tid]++;
                }
                else if(pid < 0){ // palace to tran
                    pid = -pid - 1;
                    p[pid].opt[tid]++;
                    t[tid].ipt[pid]++;
                    t[tid].need++;
                }
            }
        }
        each(x, p){
            int d = x.d;
            each(y, x.opt){
                int tid = y.first;
                inputs[tid] += d;
            }
        }

        set<int> enable;
        each(x, inputs){
            int tid = x.first, num = x.second;
            if(num >= t[tid].need) enable.insert(tid);
        }

        int nf;
        cin >> nf;
        int cnt = 0, died = 0;
        while(cnt < nf){
            if(enable.empty()){
                died = 1;
                break;
            }
            
            int tid = *enable.begin();

            each(x, t[tid].opt){
                int pid = x.first, w = x.second;
                p[pid].d += w;

                each(y, p[pid].opt){
                    int ttid = y.first;
                    inputs[ttid] += w;
                    if(inputs[ttid] >= t[ttid].need) enable.insert(ttid);
                }
            }
            
            each(x, t[tid].ipt){
                int pid = x.first, w = x.second;
                p[pid].d -= w;
                inputs[tid] -= w;
            }
            if(inputs[tid] < t[tid].need) enable.erase(enable.find(tid));

            #ifdef DEBUG2
            cout << endl;
            rep(i, np){
                cout << "(" <<  i << ", " <<  p[i].d << ") ";
            }
            cout << endl;
            #endif

            cnt++;
        }
        if(!died){
            cout << "still live after " << nf << " transitions" << '\n';
        }
        else{
            cout << "dead after " << cnt <<  " transitions" << endl;
        }

        cout << "Places with tokens:";
        rep(i, np){
            if(p[i].d != 0)
                cout << " " << i + 1 << " (" << p[i].d << ")";
        }
        cout << "\n\n";

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