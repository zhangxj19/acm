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


set<pii> st;
int isrecur;

int expr(int x, int y, vector<vector<string>>& a){
    #ifdef DEBUG2
    cout << "check " << x << ", " << y << "\n";
    #endif
    if(st.count({x, y})){
        isrecur = 1;
        return -1;
    }
    else{
        st.insert({x, y});
    }
    string s = a[x][y];
    int re=0;
    if(s[0] == '-' or isdigit(s[0])){
        re = atoi(s.c_str());
        st.erase(st.find({x, y}));
    }
    else{
        int i = 0;
        re = 0;
        int sign = 1;
        while(i < s.size()){
            if(isalpha(s[i])){
                int r = s[i] - 'A';
                int c = s[i+1] - '0';

                re += expr(r, c, a) * sign;
                sign = 1;
                i += 2;
            }
            else if(s[i] == '-'){
                sign = -1;
                i += 1;
            }
            else if(s[i] == '+'){
                sign = 1;
                i += 1;
            }
            else{
                // number
                int j = i;
                while(j < s.size() and isdigit(s[j])) j++;
                re += atoi(s.substr(i, j).c_str()) * sign;
                sign = 1;
                i = j;
            }
        }
    }

    
    return re;
}

void solve(){
    int r, c;
    while(cin >> r >> c, !(r == 0 or c == 0)){
        st.clear();
        vector<vector<string>> a(r, vector<string>(c));
        vector<vector<int>> re(r, vector<int>(c, -1));
        vector<vector<int>> isok(r, vector<int>(c, 1)); 
        rep(i, r){
            rep(j, c){
                string x;
                cin >> x;
                a[i][j] = x;
            }
        }
        int ok = 1;
        rep(i, r){
            rep(j, c){
                isrecur = 0;
                st.clear();
                // st.insert({i, j});
                re[i][j] = expr(i, j, a);
                if(isrecur){
                    re[i][j] = -1;
                    isok[i][j] = 0;
                    ok = 0;
                }
            }
        }


        if(ok){
            cout << " ";
            rep(i, c){
                cout << setw(6) << setfill(' ') << i;
            }
            cout << "\n";
            rep(i, r){
                cout << char('A' + i);
                rep(j, c){
                    if(re[i][j] < 0 and re[i][j] / 10000){
                        cout << " " << re[i][j];
                    }
                    else 
                        cout << setw(6) << setfill(' ') << re[i][j];
                }
                cout << "\n";
            }
        }
        else{
            rep(i, r){
                rep(j, c){
                    if(isok[i][j] == 0){
                        cout << (char)('A' + i) << j << ": " << a[i][j] << '\n';
                    }
                }
            }
        }
        cout << "\n";


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