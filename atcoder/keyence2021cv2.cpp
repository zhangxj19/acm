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
int dp[maxh][maxw][4];
int h, w, k;
int a[maxh][maxw];

#define SPACE 0
#define R 1
#define D 2
#define X 3

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

    rep(i, 4) dp[0][0][i] = 1;
    repu(j, 1, w){
        rep(k, 4){
            if(a[0][j-1] == SPACE)
                dp[0][j][k] = (dp[0][j-1][R] + dp[0][j-1][X])%P;
            else if(a[0][j-1] == R or a[0][j-1] == X)
                dp[0][j][k] = dp[0][j-1][a[0][j-1]];
            else dp[0][j][k] = 0;
        }
    }
    repu(i, 1, h){
        rep(k, 4){
            if(a[i-1][0] == SPACE)
                dp[i][0][k] = (dp[i-1][0][D] + dp[i-1][0][X])%P;
            else if(a[i-1][0] == D or a[i-1][0] == X)
                dp[i][0][k] = dp[i-1][0][a[i-1][0]];
            else dp[i][0][k] = 0;
        }
    }

    repu(i, 1, h){
        repu(j, 1, w){
            int re = 0;
            rep(k, 1){
                int u = 0, l = 0;
                if(a[i-1][j] == SPACE)
                    u = (dp[i-1][j][D] + dp[i-1][j][X]) % P;
                else if(a[i-1][j] == D or a[i-1][j] == X)
                    u = dp[i-1][j][a[i-1][j]];
                else u = 0;

                if(a[i][j-1] == SPACE)
                    l = (dp[i][j-1][R] + dp[i][j-1][X])%P;
                else if(a[i][j-1] == R or a[i][j-1] == X)
                    l = dp[i][j-1][a[i][j-1]];
                else l = 0;

                re = (u + l)%P;
            }
            rep(k, 4) dp[i][j][k] = re;
        }
    }

    #ifdef DEBUG
    rep(i, h){
        rep(j , w){
            cout << dp[i][j][0] << " ";
        }
        cout << "\n";
    }
    #endif

    cout << dp[h-1][w-1][0] << "\n";
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