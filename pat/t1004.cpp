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

int sub(unordered_map<int, int>& x, unordered_map<int, int>& y){
    int re = 0;
    each(p, x){
        int key = p.first, num = p.second;
        if(y.count(key) == 0) re += num;
        else{
            re +=  num - y[key];
        }
    }
    each(p, y){
        int key = p.first, num = p.second;
        if(x.count(key) == 0) re -= num;
    }
    return re;
}

unordered_map<int, int> add(unordered_map<int, int>& x, unordered_map<int, int>& y){
    unordered_map<int, int> re = x;
    each(p, y){
        int key = p.first, num = p.second;
        if(re.count(key)) re[key] += num;
        else re[key] = num;
    }
    return re;
}

unordered_map<int, int> need;
vector<unordered_map<int, int>> a;

int dfs(int x, unordered_map<int, int> packer){
    if(x == a.size()) return sub(need, packer);

    // pick 
    unordered_map<int, int> packer2 = add(packer, a[x]);
    int r1 = dfs(x+1, packer2);

    // not pick
    int r2 = dfs(x+1, packer);

    if(r1 >= 0 and r2 <= 0) return r1;
    if(r1 <= 0 and r2 >= 0) return r2;
    if(r1 <= 0 and r2 <= 0) return max(r1, r2);
    
    return min(r1, r2);

}

void solve(){
    string x;
    cin >> x;
    each(ch, x){
        need[(int)(ch)]++;
    }

    int n;
    cin >> n;
    a.resize(n);
    rep(i, n){
        string x;
        cin >> x;
        each(ch, x){
            a[i][(int)ch]++;
        }
    }

    unordered_map<int, int> packer;
    int re = dfs(0, packer);
    if(re >= 0) cout << "Yes" << " " << re << "\n";
    else{
        each(x, a){
            packer = add(packer, x);
        }
        cout  << "No" << " " << sub(need, packer) << '\n';
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