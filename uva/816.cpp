// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
// 5) use cout << '\n'; instead of cout << endl; (cout << endl is really slow)
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
#include <numeric>
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
#define pll pair<ll, ll>

using namespace std;

struct UF{
    vi f, sz; // father and component size
    int cnt; // set number 
    UF(int n): cnt(n), f(n), sz(n,1){
        rep(i, n){f[i] = i;}
    }

    int find(int x){
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    bool unite(int x, int y){
        x=find(x), y=find(y);
        if(x==y) return false;
        else{
            if(sz[x] < sz[y]) swap(x, y);
            f[y] = x;
            sz[x] += sz[y];
            cnt--;
            return true;
        }
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

};

int lowerbound(vector<int>& a, int x){
    int l = 0, r = a.size() -1 ;
    while(l < r){
        int m = (l + r) >> 1;
        if(a[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

template<typename T>
void print(vector<T> &v){rep(i, v.size()){if(i == 0) cout << v[i];else cout << " " << v[i];}cout << endl;}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p == begin) cout << *p;else cout << " " << *p;}cout << endl;}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){ll re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}

//       lrf
// nesw  012
// 0
// 1
// 2
// 3
int intd(char c){
    if(c == 'N' or c == 'L') return 0;
    if(c == 'E' or c == 'R') return 1;
    if(c == 'S' or c == 'F') return 2;
    if(c == 'W') return 3;
    exit(0);
}

int dt[4][3] = {
    {3, 1, 0},
    {0, 2, 1},
    {1, 3, 2},
    {2, 0, 3},
};

struct Node{
    vector<string> info;
};

vector<vector<Node>> g;

int inbox(int x, int y){
    return x >= 0 and x < 9 and y >= 0 and y < 9;
}

void add(int& x, int& y, int d){
    if(d == 0) x--;
    if(d == 1) y++;
    if(d == 2) x++;
    if(d == 3) y--;
}


void solve(){
    string s;
    while(cin >> s, s != "END"){
        cout << s << '\n';
        g.clear();
        g.resize(9, vector<Node>(9));
        int sx, sy, ex, ey;
        char cd;
        cin >> sx >> sy >> cd >> ex >> ey; 
        sx--;sy--;ex--;ey--;
        int r, c;
        while(cin >> r, r != 0){
            cin >> c;
            r--;c--;
            string x;
            while(cin >> x, x != "*"){
                g[r][c].info.push_back(x);
            }
        }
        g[ex][ey].info.push_back("NL");
        g[ex][ey].info.push_back("EL");
        g[ex][ey].info.push_back("SL");
        g[ex][ey].info.push_back("WL");

        queue<vector<int>> que;
        set<vector<int>> s;
        que.push({sx, sy, intd(cd)});
        s.insert({sx, sy, intd(cd)});

        // vector<vector<pii>> record(9, vector<pii>(9)); // x,y
        vector<vector<vector<vector<int>>>> record(9, vector<vector<vector<int>>>(9, vector<vector<int>>(4, vector<int>(3, 0))));
        int find = 0;
        int ed = 0;
        int gone = 0;
        while(!que.empty()){
            int x = que.front()[0], y = que.front()[1], d = que.front()[2];

            if(x == ex and y == ey and gone){
                find = 1;
                ed = d;
                break;
            }
            que.pop();
            int nx = x, ny = y;
            add(nx, ny, d); 
            #ifdef DEBUG2
            cout << x+1  << ", " << y+1  << ", " << d << "->" << nx+1 << ", " << ny+1 <<  endl;
            #endif
            if(inbox(nx, ny)){
                each(info, g[nx][ny].info){
                    if(intd(info[0]) == d){
                        repu(i, 1, info.size()){
                            int nd = dt[d][intd(info[i])];
                            if(s.count({nx, ny, nd}) == 0){
                                s.insert({nx, ny, nd});
                                que.push({nx, ny, nd});
                                gone = 1;
                                // record[nx][ny] = {x, y};
                                record[nx][ny][nd] = {x, y, d};
                                // record.insert({x, y, d});
                            }
                        }
                    }
                }
            }
        }
        #ifdef DEBUG2
        cout << "ending seaching" << endl;
        #endif
        if(!find){
            cout << "  No Solution Possible" << '\n';
        }
        else{
            vector<pii> re;
            re.push_back({ex, ey});
            while(!(ex == sx and ey == sy and ed == intd(cd))){
                #ifdef DEBUG2
                cout << ex+1  << ", " << ey+1 << endl;
                #endif
                vi tmp = record[ex][ey][ed];
                ex = tmp[0];
                ey = tmp[1];
                ed = tmp[2];
                re.push_back({ex, ey});
            }
            cout << "  ";
            int cnt = 0;
            for(int i = re.size()-1; i > -1; --i){
                if(cnt % 10 != 0) cout << " ";
                if(cnt % 10 == 0 and i != re.size()-1) cout << "\n  ";
                cout << '(' << re[i].first+1 << ',' << re[i].second+1 << ')';
                ++cnt;
            }
            cout << '\n'; 
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