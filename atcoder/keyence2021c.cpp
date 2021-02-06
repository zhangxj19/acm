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
const int P = 998244353;
const int maxh = 5001, maxw = 5001;
int mem[maxh][maxw][4];
int h, w, k;
int a[maxh][maxw];

#define SPACE 0
#define R 1
#define D 2
#define X 3

int dfs(int x, int y, int state){ // space r d x (0, 1, 2, 3)
    if(x == 0 and y == 0){
        return 1;
    }
    if(mem[x][y][state] != 0) return mem[x][y][state];
    else{
        int u, l;
        //    u
        // l now

        // check u
        if(x == 0){
            u = 0;
        }
        else{
            if(a[x-1][y] == SPACE){
                u = (dfs(x-1, y, D) + dfs(x-1, y, X)) % P;
            }
            else if(a[x-1][y] == D or a[x-1][y] == X){
                u = dfs(x-1, y, a[x-1][y]) % P;
            }
            else{
                u = 0;
            }
        }

        // check l
        if(y == 0){
            l = 0;
        }
        else{
            if(a[x][y-1] == SPACE){
                l = (dfs(x, y-1, R) + dfs(x, y-1, X)) % P;
            }
            else if(a[x][y-1] == R or a[x][y-1] == X){
                l = dfs(x, y-1, a[x][y-1]) % P;
            }
            else{
                l = 0;
            }
        }
        mem[x][y][state] = (u + l) % P;

        return mem[x][y][state];
    }
}

void solve(){
    cin >> h >> w >> k;
    rep(i, k){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        char c;
        cin >> c;
        if(c == 'X') a[x][y] = X;
        else if(c == 'R') a[x][y] = R;
        else if(c == 'D') a[x][y] = D;
    }
    #ifdef DEBUG2
    rep(i, h){
        rep(j, w){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    #endif

    int re = dfs(h-1, w-1, a[h-1][w-1]);
    cout << re << "\n";
}

signed main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
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