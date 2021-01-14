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
    int findleft[7][7] = {
        // find left if findleft[up][front]
        {0, 0, 0, 0, 0, 0, 0}, // 
        {0, 0, 3, 5, 2, 4, 0}, // 
        {0, 4, 0, 1, 6, 0, 3}, // 
        {0, 2, 6, 0, 0, 1, 5}, // 
        {0, 5, 1, 0, 0, 6, 2}, // 
        {0, 3, 0, 6, 1, 0, 4}, // 
        {0, 0, 4, 2, 5, 3, 0}, // 
    };

    string name;
    while(cin >> name, name != "END"){
        int r, c, sx, sy, up, front;
        cin >> r >> c >> sx >> sy >> up >> front;
        vvi a(r, vi(c, 0));

        rep(i, r){
            rep(j, c){
                cin >> a[r][c];
            }
        }
        int left, right, back, down;
        auto flush =[&](){
            // know the up and front, and flush the dice
            down = 7 - up;
            back = 7 - front;
            left = findleft[up][front];
            right = 7 - left;
        };
        auto gou = [&](){
            up = front;
            front = down;
            flush();
        };
        auto god = [&](){
            up = back;
            front = up;
            flush();
        };
        auto gol = [&](){
            up = right;
            front = front;
            flush();
        };
        auto gor = [&](){
            up = left;
            front = front;
            flush();
        };

        auto reset = [&](int u, int f){
            up = u; front = f;
            flush();
        };

        auto inbox = [&](int x, int y){
            return 0 <= x and x < r and 0 <= y and y < c;
        };

        auto canset = [&](int x, int y){
            return a[x][y] == -1 ? 1 : (a[x][y] == down);
        };

        // [r][c][up][front]
        // vector<vector<vector<vector<int>>>> vis(r, vector<vector<vector<int>>>(c, vector<vector<int>>(7, vector<int>(7, 0))));
        set<vector<int>> vis; // vector have 4 elements as r, c, u, f
        
        map<vector<int>, pii> fa; 

        queue<vector<int>> que;
        que.push({sx, sy, up, front});
        while(!que.empty()){
            int x = que.front()[0], y = que.front()[1], u = que.front()[2], f = que.front()[3];
            int nx = x, ny = y;
            // l
            reset(u, f);
            gol();
            nx = x; ny = y - 1;
            if(inbox(nx, ny) and vis.count({nx, ny, up, front}) and canset(nx, ny)){
                vis.insert({nx, ny, up, front});
                que.push({nx, ny, up, front});
                fa[{nx, ny, up, front}] = {x, y};
            }

            // r
            reset(u, f);
            gor();


            // u
            reset(u, f);
            gou();


            // d
            reset(u, f);
            god();

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