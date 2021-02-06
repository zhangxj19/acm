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

vi A;
vi vis;
int n;


const int maxn = 100;
int isp[maxn];

void makeprime(){
    rep(i, maxn){
        isp[i] = 1;
    }
    isp[0] = isp[1] = 0;

    repu(i, 2, maxn){
        if(isp[i] == 1){
            for(int j = i + i; j < maxn; j += i){
                isp[j] = 0;
            }   
        }
    }

}

void dfs(int cur){
    if(cur == n and isp[A[n-1] + A[0]]){
        rep(i, n){
            if(i!=0) cout << " ";
            cout << A[i];
        }
        cout << "\n";
    }
    else{
        repu(i, 2, n+1){
            if(!vis[i] and isp[A[cur-1] + i]){
                A[cur] = i;
                vis[i] = 1;
                dfs(cur + 1);
                vis[i] = 0;
            }
        }
    }
}


void solve(){
    int kcase = 0;
    makeprime();
    #ifdef DEBUG
    repu(i, 1, maxn){
        if(isp[i]) cout << i << " ";
    }
    cout << endl;
    #endif
    while(cin >> n and n > 0){
        if(kcase != 0) cout << "\n";
        cout << "Case " << ++kcase << ":\n";
        vis.assign(n+1, 0);
        A.assign(n, 0);

        A[0] = 1;
        dfs(1);

        // repu(i, 1, n+1){
        //     vis[i] = 1;
        //     A.push_back(i);
        //     dfs(1);
        //     vis[i] = 0;
        //     A.pop_back();
        // }
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
    // freopen("o", "w", stdout);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}