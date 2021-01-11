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

struct Node{
    int d; // tokens for palace and tokens needed to be enabled for trasactions
    unordered_map<int, int> opt; // node number and connection numbers
    Node(int d=0):d(d){}
};

void solve(){
   int np, nt, kcase = 0;
   while(cin >> np, np != 0){
        cout << "Case " << ++kcase << ": ";
        vector<Node> gp, gt;
        gp.resize(np);
        rep(i, np){
            int x;
            cin >> x;
            gp[i].d = x;
        }
        cin >> nt;
        gt.resize(nt);
        rep(i, nt){
            int x;
            while(cin >> x, x != 0){
                if(x < 0){
                   // place to transition
                   x = -x - 1;
                   gp[x].opt[i]++; 
                   gt[i].d++;
                }
                else{
                   // transition to place
                   x -= 1;
                   gt[i].opt[x]++;
                }
            }
        }
        #ifdef DEBUG
        auto de_bug = [&](){
            cout << '\n';
            cout << "palace\n";
            rep(i, np){
                cout << i << " " << gp[i].d << "=== ";
                each(x, gp[i].opt){
                    cout << x.first << ", " << x.second << "; ";
                }
                cout << "\n";
            }
            cout << "transactions\n";
            rep(i, nt){
                cout << i << " " << gt[i].d << "=== ";
                each(x, gt[i].opt){
                    cout << x.first << ", " << x.second << "; ";
                }
                cout << "\n";

            }
        };
        #endif
        int nf;
        cin >> nf;
        int die = 0;
        int cnt = 0;
        unordered_map<int, int> ipt; // ipt for transactions
        rep(i, np){
            each(y, gp[i].opt){
                ipt[y.first] += gp[i].d;
            }
        }

        unordered_set<int> enabled;
        each(x, ipt){
            int tid = x.first;
            if(gt[tid].d <= x.second){
                enabled.insert(tid);
                break;
            }
        }

        while(!die and cnt < nf){
            // cnt++;

            #ifdef DEBUG2
            cout << "\nenabled tid: ";
            each(x, enabled){
                cout << x << ", ";
            }
            de_bug();
            #endif

            if(enabled.size() == 0){
                die = 1;
                break;
            }
            else{
                cnt++;
            }

            each(x, enabled){
                // fire out 
                each(y, gt[x].opt){
                    int pid = y.first, w = y.second;
                    gp[pid].d += w;
                    each(z, gp[pid].opt){
                        int tid = z.first;
                        ipt[tid] += w;
                        if(ipt[tid] >= gt[tid].d) enabled.insert(tid);
                    }
                }
                // decrease for ipt
                each(y, gp){
                    if(y.opt.count(x)){
                        int w = y.opt[x];
                        y.d -= w;
                        ipt[x] -= w;
                    }
                }
                if(ipt[x] < gt[x].d) enabled.erase(enabled.find(x));
                break;
            }
            
            #ifdef DEBUG2
            cout <<"|" << '\n';
            cout <<"|" ;
            de_bug();
            cout << cnt << " transitions finished \n";
            #endif
    
        }
        vector<pii> re;
        rep(i, np){
            if(gp[i].d > 0){
                re.push_back({i, gp[i].d});
            }
        }    
        sort(re.begin(), re.end(), [](pii& x, pii& y){
            return x.second == y.second ? x.second > y.second : x.first < y.first;
        });

        if(die){
            cout << "dead after " << cnt << " transitions\n";
        }
        else{
            cout << "still live after " << nf  << " transitions\n";
        }
        cout << "Places with tokens: ";
        rep(i, re.size()){
            if(i != 0) cout << " ";
            cout << re[i].first + 1 << " " << "(" << re[i].second << ")";
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