#include <bits/stdc++.h>

using namespace std;

#define int long long
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

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

template<typename T>
void print(vector<T> &v){rep(i, v.size()){if(i != 0) cout << " "; cout << v[i];}cout << '\n';}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p != begin) cout << " "; cout << *p;}cout << '\n';}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}
const int maxn = 301;
int n;
// vector<vector<char>> a;
// vector<vector<int>> vis;
char a[maxn][maxn];
int vis[maxn][maxn];
int re;

int dir[8][2] = {
    {-1, -1},
    {-1,  0},
    {-1,  1},
    { 0, -1},
    { 0,  1},
    { 1, -1},
    { 1,  0},
    { 1,  1},
};

int inbox(int x, int y){
    return 0 <= x and x < n and 0 <= y and y < n;
}

int mine_rounded(int x, int y){
    rep(i, 8){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(inbox(nx, ny) and a[nx][ny] == '*'){
            return 1;
        }
    }
    return 0;
}

void dfs(int x, int y){
    vis[x][y] = 1;
    if(mine_rounded(x, y)) return;
    rep(i, 8){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(inbox(nx, ny) and !vis[nx][ny] and a[nx][ny] == '.'){
            dfs(nx, ny);
        }
    }
}

void solve(){
    int t;
    cin >> t;
    int kase = 0;
    while(t--){
        re = 0;
        cout << "Case #" << ++kase << ": ";
        cin >> n;
        getchar();
        // a.resize(n, vector<char>(n));
        // vis.assign(n, vector<int>(n, 0));
        memset(vis, 0, sizeof(vis));
        rep(i, n){
            rep(j, n){
                a[i][j] = getchar();
            }
            getchar();
        }
        rep(i, n){
            rep(j, n){
                if(!vis[i][j] and a[i][j] == '.' and !mine_rounded(i, j)){
                    dfs(i, j);
                    re++;
                }
            }
        }
        #ifdef DEBUG2
        cout << "\n";
        rep(i, n){
            rep(j, n){
                cout << vis[i][j];
            }
            cout << "\n";
        }
        #endif
        rep(i, n){
            rep(j, n){

                if(!vis[i][j] and a[i][j] == '.') re++;
            }
        }
        cout << re << "\n";


    } 
}

signed main(){
    #ifndef DEBUG
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);
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