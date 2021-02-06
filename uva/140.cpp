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

string s;

int re = 0;
vector<int> ans, tmp;
int n;


void solve(){
    while(cin >> s, s != "#"){
        vector<unordered_set<int>> g(26);
        set<int> st;
        for(int i = 0; i < s.size(); ){
            int j = s.find(';', i);
            if(j == string::npos){
                int x = s[i] - 'A';
                for(int k = i + 2; k < s.size(); ++k){
                    int y = s[k] - 'A';
                    g[x].insert(y);
                    g[y].insert(x);
                }
                break;
            }
            else{
                int x= s[i] - 'A';
                for(int k = i + 2; k < j; ++k){
                    int y = s[k] - 'A';
                    g[x].insert(y);
                    g[y].insert(x);
                }        
                i = j + 1;
            }
        }
        #ifdef DEBUG2
        rep(i, g.size()){
            cout << i << ": ";
            each(y, g[i]){
                cout << y << " ";
            }
            cout << "\n";
        }
        #endif
        vector<int> a, pos(26, 0);
        for(int i = 0; i < g.size(); ++i) if(g[i].size()) a.push_back(i);
        const int inf = (int) 1e9;
        re = inf;
        sort(a.begin(), a.end());
        do{
            #ifdef DEBUG2
            print(a);
            #endif
            for(int i = 0; i < a.size(); ++i) pos[a[i]] = i;
            int f = 0;
            for(int i = 0; i < a.size(); ++i){
                each(y, g[a[i]]) f = max(f, abs(pos[a[i]] - pos[y]));
            }
            if(f < re){
                ans = a;
                re = f;
            }
        } while(next_permutation(a.begin(), a.end()));
        for(int i = 0; i < ans.size(); ++i) cout << (char)(ans[i] + 'A') << " "; 
        cout << "-> " << re << "\n";
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