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

const int maxn = 51, maxc = 1001;


int x0[maxn], y0[maxn], z0[maxn], x1[maxn], y1[maxn], z1[maxn];

int nx, ny, nz;
int xs[2*maxn], ys[2*maxn], zs[2*maxn];

int color[2*maxn][2*maxn][2*maxn];
int b[2*maxn][2*maxn][2*maxn];

void discretize(int* x, int& n){
    sort(x, x+n);
    n = unique(x, x+n) - x;
}

int ID(int* x, int n, int x0){
    return lower_bound(x, x+n, x0) - x;
}


struct Cell{
    int x, y, z;
    Cell(int x = 0, int y = 0, int z= 0):x(x),y(y),z(z){}

    int inBox(){
        // return 0 <= x and x < nx-1 and 0 <= y and y < ny-1 and 0 <= z and z < nz-1;
        return 0 <= x and x < nx-1 and 0 <= y and y < ny-1 and 0 <= z and z < nz-1;
    }

    int isConcrete(){
        return color[x][y][z] == 1;
    }

    void setVisited(){
        b[x][y][z] = 1;
    }

    int isVisited(){
        return b[x][y][z] == 1;        
    }

    int getV(){
        return (xs[x+1] - xs[x]) * (ys[y+1] - ys[y]) * (zs[z+1] - zs[z]);
    }

    int getS(int i){
        if(i == 0 or i == 1){ // x
            return (ys[y+1] - ys[y]) * (zs[z+1] - zs[z]);
        }
        if(i == 2 or i == 3){ // y
            return (xs[x+1] - xs[x]) * (zs[z+1] - zs[z]);
        }
        // if(i == 4 or i == 5){ // z
            return (ys[y+1] - ys[y]) * (xs[x+1] - xs[x]);
        // }
        // return -1;
    }

};

int dir[6][3] = {
    { 1,  0,  0},
    {-1,  0,  0},
    { 0,  1,  0},
    { 0, -1,  0},
    { 0,  0,  1},
    { 0,  0, -1},
};

void floodfill(int& s, int& v){
    s = v = 0;
    Cell c;
    queue<Cell> que;
    que.push(c);
    c.setVisited();
    while(!que.empty()){
        Cell x = que.front(); que.pop();

        v += x.getV();

        rep(i, 6){
            int nx = x.x + dir[i][0], ny = x.y + dir[i][1], nz = x.z + dir[i][2];
            Cell nc(nx, ny, nz);
            if(nc.inBox()){
                if(nc.isConcrete()){
                    s += x.getS(i);
                }
                else{
                    if(!nc.isVisited()){
                        nc.setVisited();
                        que.push(nc);
                    }
                }
            }
        }
    }

    v = maxc*maxc*maxc - v;
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        nx = ny = nz = 2;  //默认一开始就有两个离散点了,(最大的水部分)
        xs[0] = ys[0] = zs[0] = 0; // 包括最大的水部分也需要离散化.(0, 0, 0), (maxc, maxc, maxc)
        xs[1] = ys[1] = zs[1] = maxc;
        memset(b, 0, sizeof(b));
        
        int n;
        cin >> n;


        rep(i, n){
            cin >> x0[i] >> y0[i] >> z0[i] >> x1[i] >> y1[i] >> z1[i];
            x1[i] += x0[i]; y1[i] += y0[i]; z1[i] += z0[i];
            xs[nx++] = x0[i]; xs[nx++] = x1[i];
            ys[ny++] = y0[i]; ys[ny++] = y1[i];
            zs[nz++] = z0[i]; zs[nz++] = z1[i];
        }
        discretize(xs, nx);
        discretize(ys, ny);
        discretize(zs, nz);

        // paint color for sculptures;
        memset(color, 0, sizeof(color));
        rep(i, n){
            int X0 = ID(xs, nx, x0[i]), X1 = ID(xs, nx, x1[i]);
            int Y0 = ID(ys, ny, y0[i]), Y1 = ID(ys, ny, y1[i]);
            int Z0 = ID(zs, nz, z0[i]), Z1 = ID(zs, nz, z1[i]);
            repu(X, X0, X1){
                repu(Y, Y0, Y1){
                    repu(Z, Z0, Z1){
                        color[X][Y][Z] = 1;
                    }
                }
            }
        }

        int s, v;
        floodfill(s, v);
        cout << s << " " << v << '\n';
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