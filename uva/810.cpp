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

int dir[4][2] = {
    { 0,-1},
    { 0, 1},
    {-1, 0},
    { 1, 0},
}; 

void solve(){
    // int findleft[7][7] = {
    //     // find left if findleft[up][front]
    //     {0, 0, 0, 0, 0, 0, 0}, // 
    //     {0, 0, 3, 5, 2, 4, 0}, // 
    //     {0, 4, 0, 1, 6, 0, 3}, // 
    //     {0, 2, 6, 0, 0, 1, 5}, // 
    //     {0, 5, 1, 0, 0, 6, 2}, // 
    //     {0, 3, 0, 6, 1, 0, 4}, // 
    //     {0, 0, 4, 2, 5, 3, 0}, // 
    // };
    int findleft[7][7] = {
        // find left if findleft[up][front]
        {0, 0, 0, 0, 0, 0, 0}, // 
        {0, 0, 4, 2, 5, 3, 0}, // 
        {0, 3, 0, 6, 1, 0, 4}, // 
        {0, 5, 1, 0, 0, 6, 2}, // 
        {0, 2, 6, 0, 0, 1, 5}, // 
        {0, 4, 0, 1, 6, 0, 3}, // 
        {0, 0, 3, 5, 2, 4, 0}, // 
    };

    string name;
    while(cin >> name, name != "END"){
        cout << name << '\n';
        int r, c, sx, sy, up, front;
        cin >> r >> c >> sx >> sy >> up >> front;
        sx--;sy--;
        vvi a(r, vi(c, 0));

        rep(i, r){
            rep(j, c){
                cin >> a[i][j];
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
            front = up;
            up = back;
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

        auto canset = [&](int x, int y, int u){
            return a[x][y] == -1 ? 1 : (a[x][y] == u);
        };

        // [r][c][up][front]
        // vector<vector<vector<vector<int>>>> vis(r, vector<vector<vector<int>>>(c, vector<vector<int>>(7, vector<int>(7, 0))));
        set<vector<int>> vis; // vector have 4 elements as r, c, u, f
        
        map<vector<int>, vector<int>> fa; 

        queue<vector<int>> que;
        que.push({sx, sy, up, front});
        vector<int> des;
        int find = 0;
        int gone = 0;
        while(!que.empty()){
            int x = que.front()[0], y = que.front()[1], u = que.front()[2], f = que.front()[3]; que.pop();
            reset(u, f);
            #ifdef DEBUG2
            cout << "(" << x+1 << "," << y+1 << "," << u << "," << f<< ") ";
            if(fa.count({x, y, u, f})){
                vi father = fa[{x, y, u, f}];
                cout << "<-" << "(" << father[0]+1 << "," << father[1]+1 << "," << father[2] << "," << father[3]<< ") \n";
            }
            else cout << "\n";
            #endif
            if(x == sx and y == sy and gone) {
                des = {x, y, u, f};
                find = 1;
                break;
            }
            gone = 1;
            rep(i, 4){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                reset(u, f);
                if(i == 0) gol();
                else if(i == 1) gor();
                else if(i == 2) gou();
                else if(i == 3) god();
                #ifdef DEBUG2
                cout << "try nx = " << nx << ", ny = " << ny << " up = " << up << ", front = " << front << "\n";
                cout << inbox(nx, ny) ;
                if(inbox(nx, ny)){
                    cout << ", " << !vis.count({nx, ny, up, front}) << ", " << canset(nx, ny, u) << "\n";
                }
                else cout << "\n";
                #endif
                if(inbox(nx, ny) and !vis.count({nx, ny, up, front}) and canset(nx, ny, u)){
                    vis.insert({nx, ny, up, front});
                    que.push({nx, ny, up, front});
                    fa[{nx, ny, up, front}] = {x, y, u, f};
                }
            }
            
        }  
        if(find){
            vector<pii> re;
            do{
                re.push_back({des[0], des[1]});
                
                des = fa[des];
                if(des[0] == sx and des[1] == sy){
                    re.push_back({sx, sy});
                    break;
                }
            }while(1);
            reverse(re.begin(), re.end());
            cout << "  ";
            for(int i = 0; i < re.size(); ++i){
                if(i != 0 and i % 9 == 0) cout << ",\n  ";
                if(i != 0 and i % 9 != 0)cout << ",";
                cout << "(" << re[i].first+1 << "," << re[i].second+1 << ")";
            }
            cout << "\n";
        }
        else{
            cout << "  No Solution Possible\n";
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
    // freopen("o", "w", stdout);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}