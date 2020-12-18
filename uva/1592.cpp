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
// unique upper_bound lower_bound
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
T sum(T* begin, T* end){
    T re = 0;
    for(T *p = begin; p != end; ++p) re = re + *p;
    return re;
}

template<typename T>
T sum(typename vector<T>::iterator begin, typename vector<T>::iterator end){
    T re = 0;
    for(auto p = begin; p != end; ++p) re = re + *p;
    return re;
}

const int maxn = 1e4+1, maxm = 1e1+1;
int n, m, a[maxn][maxm];

map<string, int> string_cache;
int stringGetId(string &x){
    if(string_cache.count(x)){
        return string_cache[x];
    }
    else{
        string_cache[x] = string_cache.size();
        return string_cache[x];
    }
}


int Find(int& rr1, int& rr2, int& cc1, int& cc2){
    
    rep(c1, m){
        repu(c2, c1+1, m){
            map<pii, int> mp;
            rep(r1, n){
                pii p = make_pair(a[r1][c1], a[r1][c2]);
                if(mp.count(p)){
                    rr1 = mp[p];
                    rr2 = r1;
                    cc1 = c1;
                    cc2 = c2;
                    return 1;
                }
                else{
                    mp[p] = r1;
                }                
                
            }
        }
    }
    return 0;
}

void solve(){
    while(sf("%d%d\n",&n,&m) == 2){
    // while(cin >> n >> m){
        // getchar();
        memset(a, 0, sizeof(a));
        string_cache.clear();
        rep(r, n){
            // for a row now
            rep(c, m){
                char ch;
                string s;
                while(1){
                    ch = getchar();
                    if(ch == ',' or ch == '\n' or ch == EOF) break;
                    s += ch;
                }
                int id = stringGetId(s);
                a[r][c] = id;
            }
        }
        int r1=0,r2=0,c1=0,c2=0;
        if(Find(r1,r2,c1,c2)){
            // cout << "NO" << endl;
            // cout << r1+1 << " " << r2+1 << endl;
            // cout << c1+1  << " " << c2+1 << endl;
            
            pf("NO\n%d %d\n%d %d\n", r1+1, r2+1, c1+1, c2+1);
        }
        else{
            // cout << "YES" << endl;
            pf("YES\n");
        }



    }
}

int main(){
    // #ifndef DEBUG
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // #endif
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