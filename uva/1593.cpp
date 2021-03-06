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
// unique upper_bound lower_bound
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
T sum(T* begin, T* end){
    T re = 0;
    for(T *p = begin; p != end; ++p) re = re + *p;
    return re;
}

template<typename T>
T sum(typename vector<T>::iterator begin, typename vector<T>::iterator end){
    T re = 0;
    for(auto p = begin; p != end; ++p) re = re + *p;
    return re;
}

vector<vector<string>> v;
vector<string> tmp;

int colmax;

map<int, int> colmax_str;

void solve(){
    int r = 0, c = 0;
    string s;
    while(1){
        char ch = getchar();
        if(ch == '\n' or ch == ' ' or ch == EOF){
            if(s.size()){
                tmp.push_back(s);
                c++;
                colmax = max(colmax, c);
                colmax_str[c-1] = max(colmax_str[c-1], (int)s.size());

                s.clear();
            }

            if(ch == '\n' or ch == EOF){
                // while(tmp.size() < colmax) tmp.push_back("");
                v.push_back(tmp);

                r++;
                c = 0;

                tmp.clear();
                if(ch == EOF) break;
            }
        }
        else{
            s += ch;
        }
        
    }
    #ifdef DEBUG
    each(e, v){
        print(e);
    }
    #endif
    each(e, v){
        rep(i, e.size()){
            // if(e[i] == "") break;
            // else{
            if(i == e.size() - 1) cout << e[i] << endl;
            else{
                cout << e[i];
                rep(j, colmax_str[i] - e[i].size() + 1) cout << " ";
            }
            // }
        }
    }

}

int main(){
    // #ifndef DEBUG
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // #endif
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