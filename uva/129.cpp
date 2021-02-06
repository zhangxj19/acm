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

int n, l;
int cnt = 0;
vi a;

char get(int x){
    return x + 'A';
}

int dfs(int cur){
    if(cnt++ == n){
        for(int i = 0; i < cur; ++i){
            if(i != 0 and i % 64 == 0) cout << '\n';
            if(i != 0 and i % 4 == 0 and i % 64 != 0){
                cout << " ";
            }
            cout << get(a[i]);
        }
        cout << "\n" << cur << "\n";
        return 0;
    }
    for(int i = 0 ; i < l; ++i){
        a[cur] = i;
        int ok = 1;
        for(int j = 1; j+j <= cur + 1; ++j){
            int eq = 1;
            for(int k = 0; k < j; ++k){
                if(a[cur-k] != a[cur-k-j]){ eq = 0; break;}
            }
            if(eq){ ok = 0; break;}
        }
        if(ok){
            if(!dfs(cur+1)) return 0;
        }
    }
    return 1;
}

void solve(){
    while(cin >> n >> l, !(n == 0 and l == 0)){
        a.assign(81, 0);
        cnt = 0;
        dfs(0);
    }

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