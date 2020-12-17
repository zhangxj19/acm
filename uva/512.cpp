// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
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
#define pii pair<int, int>

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(vi &v){
    rep(i, v.size()){
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

int R, C, n, q;

struct Cmd{
    string x;
    vector<int> d;
};
vector<Cmd> cmd;

int simulate(int &r, int &c){
    each(x, cmd){
        if(x.x[0] == 'E'){
            if(x.d[0] == r and x.d[1] == c){
                r = x.d[2];
                c = x.d[3];
            }
            else if(x.d[2] == r and x.d[3] == c){
                r = x.d[0];
                c = x.d[1];
            }
        }
        else if(x.x[0] == 'D'){
            if(x.x[1] == 'R'){
                int cnt = 0;
                each(tar, x.d){
                    if(tar == r) return 0;
                    else if(tar < r){
                        cnt++;
                    }
                }
                r -= cnt;
            }
            else if(x.x[1] == 'C'){
                int cnt = 0;
                each(tar, x.d){
                    if(tar == c) return 0;
                    else if(tar < c){
                        cnt++;
                    }
                }
                c -= cnt;                
            }
        }
        else if(x.x[0] == 'I'){
            if(x.x[1] == 'R'){
                int cnt = 0;
                each(tar, x.d){
                    if(tar <= r) cnt++;
                }
                r += cnt;
            }
            else if(x.x[1] == 'C'){
                int cnt = 0;
                each(tar, x.d){
                    if(tar <= c) cnt++;
                }
                c += cnt;                
            }
        }
    }
    return 1;
}

void solve(){
    int kcase = 1;
    while(cin >> R >> C, !(R == 0 and C == 0)){
        cmd.clear();
        if(kcase > 1) cout << endl;
        cout << "Spreadsheet #" << kcase++ << endl;
        cin >> n;
        rep(i, n){
            Cmd x;
            cin >> x.x;
            if(x.x[0] == 'E'){
                rep(j, 4){
                    int t;
                    cin >> t;
                    x.d.push_back(t);
                }
            }
            else{
                int num;
                cin >> num;
                rep(j, num){
                    int t;
                    cin >> t;
                    x.d.push_back(t);
                }
            }
            cmd.push_back(x);
        }

        cin >> q;
        rep(i, q){
            int r, c;

            cin >> r >> c;
            cout << "Cell data in (" << r << "," << c <<") ";
            if(!simulate(r, c)){
                cout << "GONE" << endl;
            }
            else{
                cout << "moved to " << "(" << r << "," << c <<")" << endl;
            }
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