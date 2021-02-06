#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define pii pair<int, int>
const int maxn = 110;
char a[maxn][maxn];
int vis[maxn][maxn];
int h, w;
unordered_map<int, int> cache;
vector<pii> star;

int getid(int x) {
    if(cache.count(x)) return cache[x];
    else{
        cache[x] = cache.size();
        return cache[x];
    }
}

int gethash(){
    int re = 0;
    for(int i = 0; i < star.size(); ++i) {
        for(int j = i + 1; j < star.size(); ++j) {
            int dx = star[i].first - star[j].first;
            int dy = star[i].second - star[j].second;
            re += dx * dx + dy * dy;
        }
    }
    return re;
}
int dir[8][2] = {
    {-1, -1},
    {-1,  0},
    {-1,  1},
    { 0, -1},
    { 0,  1},
    { 1, -1},
    { 1,  0},
    { 1,  1},
};
int inbox(int x, int y){
    return 0 <= x and x < h and 0 <= y and y < w;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    star.push_back({x, y});
    for(int i = 0; i < 8; ++i){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(inbox(nx, ny) and !vis[nx][ny] and a[nx][ny] == '1') 
            dfs(nx, ny);
    } 
}

void solve() {
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(!vis[i][j] and a[i][j] == '1') {
                star.clear();
                dfs(i, j);
                int id = getid(gethash());
                for(auto& [x, y] : star) a[x][y] = id + 'a'; 
            }
        }
    } 
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("o", "w", stdout);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h;
    for(int i = 0; i < h; ++i) cin >> a[i];
    solve(); 
}