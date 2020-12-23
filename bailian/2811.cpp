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

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

template<typename T>
void print(vector<T> &v){
    rep(i, v.size()){
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

template<typename T>
void print(T* begin, T* end){
    for(T *p = begin; p != end; ++p){
        if(p == begin) cout << *p;
        else cout << " " << *p;
    }
    cout << endl;
}

template<typename T>
T sum(T* begin, T* end){
    T re = 0;
    for(T *p = begin; p != end; ++p) re = re + *p;
    return re;
}

// template<typename T>
// T sum(typename vector<T>::iterator begin, typename vector<T>::iterator end){
//     T re = 0;
//     for(auto p = begin; p != end; ++p) re = re + *p;
//     return re;
// }
int sum(vector<int>::iterator begin, vector<int>::iterator end){
    int re = 0;
    for(auto p = begin; p != end; ++p) re = re + *p;
    return re;
}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){
    ll re = 0;
    for(auto p = begin; p != end; ++p) re = re + *p;
    return re;
}

const int n = 5, m = 6;

int a[n][m], b[n][m];


int cnt1(int x, int y){
    int re = 0;
    if(x - 1 >= 0 and b[x-1][y] == 1) re++;
    if(b[x][y] == 1) re++;
    if(y - 1 >= 0 and b[x][y-1] == 1) re++;
    if(y + 1 < m and b[x][y+1] == 1) re++;
    return re; 
}

void generate(){
    repu(x, 1, n){
        rep(y, m){
            int cnt = cnt1(x-1, y);
            if(a[x-1][y] == 1 and (cnt % 2 == 0)) b[x][y] = 1;
            if(a[x-1][y] == 0 and (cnt % 2 == 1)) b[x][y] = 1;
        }
    }   
}

void solve(){
    rep(i, n){
        rep(j, m){
            cin >> a[i][j];
        }
    }
    // rep(j, m) b[0][j] = 0;
    // int tmp[m] = {1, 0, 1, 0, 0, 1};
    // rep(j, m) b[0][j] = tmp[j];

    for(int i = 0; i < (1 << m); ++i){
        memset(b, 0, sizeof(b));
        for(int j = 0; j < m; ++j){
            if(i & (1 << j)) b[0][j] = 1;
        }
        generate();

        // check last row
        int ok = true;
        rep(y, m){
            int cnt = cnt1(n-1, y);
            if(a[n-1][y] == 1 and (cnt % 2 == 0)) ok = false;
            if(a[n-1][y] == 0 and (cnt % 2 == 1)) ok = false;
        }   

        if(ok){
            rep(i, n){
                print(b[i], b[i] + m);
            }
            return ;
        }
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