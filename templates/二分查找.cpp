// 3种二分搜索
// 1.>=x的下标最小元素 (lower_bound)
// 2.>=x的下标最大元素
// 3.>x的下标最小元素 (upper_bound)
// 由于/2的操作是下取整,故当更新l=mid时需要让mid = l + r + 1 >> 1防止死循环.
#include <bits/stdc++.h>

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
#define pll pair<ll, ll>

using namespace std;


int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

template<typename T>
void print(vector<T> &v){rep(i, v.size()){if(i != 0) cout << " "; cout << v[i];}cout << '\n';}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p != begin) cout << " "; cout << *p;}cout << '\n';}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}

// 当出现[l...xa[m]x...r]时r需要左缩
int lowerbound(vector<int>& a, int x){
    int l = 0, r = a.size() -1 ;
    while(l < r){
        int m = (l + r) >> 1;       //
        if(a[m] < x) l = m + 1;     // [l...a[m]...xxx...r]
        else r = m;                 // [l...xa[m]x...r]
    }
    return l;
}

// 当出现[l...xa[m]x...r]时l需要右缩
int upperbound(vector<int>& a, int x){
    int l = 0, r = a.size() -1 ;
    while(l < r){
        int m = (l + r + 1) >> 1;   // m上取整
        if(a[m] <= x) l = m;        // [l...xa[m]x...r]
        else r = m-1;               // [l...x...a[m]...r]
    }
    return l;
}

// 当出现[l...xa[m]x...r]时l需要右缩
// 与上面lowerbound不同的是l需要右缩
int upperbound2(vector<int>& a, int x){
    int l = 0, r = a.size() -1 ;
    while(l < r){
        int m = (l + r) >> 1;   // m上取整
        if(a[m] > x) r = m;        //
        else l = m+1;
    }
    return l;
}

void solve(){
    vi a = {1,2,3,4,5,5,5,6,7};
    print(a);
    for(int i =0 ; i < a.size(); ++i){
        cout << i << " ";
    }
    cout << "\n";
    cout << lowerbound(a, 5) << " " << upperbound(a, 5) << endl;
    cout << lowerbound(a, 5) << " " << upperbound2(a, 5) << endl;
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