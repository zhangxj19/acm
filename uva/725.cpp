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

void solve(){
    int n;
    int kase = 0;
    while(cin >> n, n != 0){
        vector<pair<string, string>> re;
        if(kase++ != 0) cout << "\n";
        auto to_string_with_pad = [&](int x){
            string re = to_string(x);
            while(re.size() < 5){
                re.insert(0, "0");
            }
            return re;
        };
        auto isunique = [&](string& su, string& sd){
            int vis[11] = {0};
            each(ch, su){
                if(vis[ch-'0'] > 0) return false;
                vis[ch - '0']++;
            }
            each(ch, sd){
                if(vis[ch - '0'] > 0) return false;
                vis[ch - '0']++;
            }
            return true;
        };
        repu(down, 1, 100000){
            int up = n * down;
            if(up >= 1e5) break;
            #ifdef DEBUG2
            cout << up << '\n';
            #endif
            string su = to_string_with_pad(up);
            string sd = to_string_with_pad(down);
            if(isunique(su, sd)){
                #ifdef DEBUG2
                cout << up << ", " << down << '\n';
                #endif
                re.push_back({to_string_with_pad(up), to_string_with_pad(down)});
            }
        }
        if(re.size() == 0){
            cout << "There are no solutions for " << n << ".\n";

        }
        else{
            each(x, re){
                cout << x.first << " / " << x.second << " = " << n << '\n';
            }
        }
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