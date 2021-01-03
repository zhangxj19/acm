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

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

template<typename T>
void print(vector<T> &v){rep(i, v.size()){if(i == 0) cout << v[i];else cout << " " << v[i];}cout << endl;}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p == begin) cout << *p;else cout << " " << *p;}cout << endl;}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){ll re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}

const int maxn = 201;

int h, w, a[maxn][maxn], b[maxn][maxn];
map<int, int> cnt;
vector<char> re;

inline int alpha2num(char x){
    if(x >= '0' and x <= '9') return x - '0';
    else return x - 'a' + 10;
}

string num2binary(int x){ // 4 bits
    string re; 
    for(int i = 3; i > -1; --i){
        if((x & (1 << i))) re += '1';
        else re += '0';
    }
    return re;
}

int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

int inbox(int x, int y){
    return x >= 0 and x < h and y >= 0 and y < 4*w;
}

void dfs_black(int x, int y, int type){
    rep(i, 4){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(inbox(nx, ny) and a[nx][ny] == 1 and b[nx][ny] == 0 ){
            b[nx][ny] = type;
            dfs_black(nx, ny, type);
        }
    }
}

int is_back_gnd = false;
int btype = 0;
void dfs_w(int x, int y){
    
    rep(i, 4){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(!inbox(nx, ny)){
            is_back_gnd = 1;
        }
        else if(a[nx][ny] == 1) btype = b[nx][ny];
        else if(a[nx][ny] == 0 and b[nx][ny] == 0){
            b[nx][ny] = -1;
            dfs_w(nx, ny);
        }
    }
}



void solve(){
    int kase = 0;
    while(cin >> h >> w, !(h == 0 and w == 0)){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        cnt.clear();
        re.clear();
        rep(i, h){
            string s; 
            cin >> s;
            rep(j, s.size()){
                string x = num2binary(alpha2num(s[j]));
                #ifdef DEBUG2
                cout << s[j] << " , " << x << endl;
                #endif
                repu(k, j*4, j*4 + 4){
                    a[i][k] = x[k - 4*j] - '0';
                }
            }
        }
        #ifdef DEBUG2
        rep(i, h){
            rep(j, 4*w){
                cout << a[i][j];
            }
            cout << endl;
        }
        #endif
        // black

        int type = 1;
        rep(i, h){
            rep(j, 4*w){
                if(a[i][j] == 1 and b[i][j] == 0){
                    b[i][j] = type;
                    dfs_black(i, j, type);
                    cnt[type] = 0;
                    type++;
                }
            }
        }


        rep(i, h){
            rep(j, 4*w){
                if(a[i][j] == 0 and b[i][j] == 0){
                    b[i][j] = -1;
                    is_back_gnd = false;
                    btype = 0;
                    dfs_w(i, j);
                    if(!is_back_gnd){
                        cnt[btype]++;
                    }
                }
            }
        }

        #ifdef DEBUG
        rep(i, h){
            rep(j, 4*w){
                cout << b[i][j];
            }
            cout << endl;
        }
        #endif

        each(x, cnt){
            #ifdef DEBUG
            cout << x.first << ", " << x.second << endl;
            #endif
            if(x.second == 1) re.push_back('A');
            else if(x.second == 3) re.push_back('J');
            else if(x.second == 5) re.push_back('D');
            else if(x.second == 4) re.push_back('S');
            else if(x.second == 0) re.push_back('W');
            else if(x.second == 2) re.push_back('K');
        }
        sort(re.begin(), re.end());

        cout << "Case " << ++kase << ": ";
        each(ch, re){
            cout << ch;
        }
        cout << endl;




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