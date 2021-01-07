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
void print(vector<T> &v){rep(i, v.size()){if(i == 0) cout << v[i];else cout << " " << v[i];}cout << '\n';}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p == begin) cout << *p;else cout << " " << *p;}cout << '\n';}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){ll re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}

const int maxn = 102;

bool a[maxn][maxn][maxn];
bool b[maxn][maxn][maxn];

int dir[6][3] = {
    { 1,  0,  0},
    {-1,  0,  0},
    { 0,  1,  0},
    { 0, -1,  0},
    { 0,  0,  1},
    { 0,  0, -1},
};

int ssum = 0, vsum = 0, vcnt = 0, scnt = 0;
int inbox(int x, int y, int z){
    return 0 <= x and x < maxn and 0 <= y and y < maxn and 0 <= z and z < maxn;
};

int touchborder = 0;

void bfs(int _x, int _y, int _z){
    queue<vector<int>> que;
    que.push({_x, _y, _z});
    b[_x][_y][_z] = 1;
    while(!que.empty()){
        int x = que.front()[0], y = que.front()[1], z = que.front()[2];
        vcnt++;
        que.pop();
        rep(i, 6){
            int nx = x + dir[i][0], ny = y + dir[i][1], nz = z + dir[i][2];
            if(!inbox(nx, ny, nz)) touchborder = 1;
            else{
                if(a[nx][ny][nz] == 0 and b[nx][ny][nz] == 0){
                    b[nx][ny][nz] = 1;
                    que.push({nx, ny, nz});
                }
                if(a[nx][ny][nz] == 1) scnt++;
            }
        } 
    }

}

void solve(){
    int t;
    cin >> t;

    while(t--){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n;
        cin >> n;
        rep(_, n){
            int x0, y0, z0, x, y, z;
            cin >> x0 >> y0 >> z0 >> x >> y >> z;
            auto fill = [&](){
                repu(i, x0, x0 + x){
                    repu(j, y0, y0 + y){
                        repu(k, z0, z0 + z){
                            a[i][j][k] = 1;
                        }
                    }
                }
            };
            fill();
        }

        ssum = 0; vsum = maxn*maxn*maxn; vcnt = 0; scnt = 0;

        int quit = 0;
        rep(i, maxn){
            rep(j, maxn){
                rep(k, maxn){
                    if(a[i][j][k] == 0 and b[i][j][k] == 0){
                        b[i][j][k] = 1;
                        bfs(i, j, k);
                        if(touchborder){
                            ssum += scnt;
                            vsum -= vcnt;
                            quit = 1;
                            break;
                        } 
                    }
                }
                if(quit) break;
            }
            if(quit) break;
        }
        cout << ssum << " " << vsum <<                                                                                                                                  "\n";


    }    
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("o", "w", stdout);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}
