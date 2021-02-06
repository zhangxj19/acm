#include <bits/stdc++.h>

using namespace std;

const int maxn = 10, N = 9, M = 1 << 10; 
#define lowbit(x) (x & (-x))
#define pii pair<int, int>
int a[maxn * maxn], mp[M], ones[M];
int row[maxn], col[maxn], vis[N], box[N][N];

void get2d(int i, int& x, int& y){
    x = i / N;
    y = i % N;
}

void init(){
    for(int i = 0; i < maxn; ++i) {
        row[i] = (1 << N) - 1;
        col[i] = (1 << N) - 1;
        vis[i] = (1 << N) - 1;
    }
}

void print(){
    for(int i = 0; i < N * N; ++i) cout << a[i];
    cout << "\n";
}

int get(int cur) {
    int x, y;
    get2d(cur, x, y);
    return row[x] & col[y] & vis[box[x][y]];
}

int get(int x, int y) {
    return row[x] & col[y] & vis[box[x][y]];
}

int dfs(int cnt) {
    if(!cnt) return 1;
    
    int cur, x, y;
    int mind = maxn;
    for(int i = 0; i < N * N; ++i) {
        if(a[i] == 0) {
            int cango = get(i);
            int one = ones[cango];
            if(one < mind) {
                mind = one;
                cur = i;
                get2d(i, x, y);
            }
        } 
    }
    int bid = box[x][y];
    for(int cango = get(cur); cango; cango -= lowbit(cango)) {
        int i = mp[lowbit(cango)];

        int v = (1 << i);
        // row[x] -= v;
        // col[y] -= v;
        // vis[bid] -= v;
        row[x] &= (~(1 << i));
        col[y] &= (~(1 << i));
        vis[bid] &= (~(1 << i));
        a[cur] = i + 1;
        if(dfs(cnt - 1)) return 1;
        a[cur] = 0;
        row[x] |= 1 << i;
        col[y] |= 1 << i;
        vis[bid] |= 1 << i;
        // row[x] += v;
        // col[y] += v;
        // vis[bid] += v;

    }

    return 0;
}

int main(){
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string x;
    for(int i = 0; i <= 6; i += 3) {
        for(int j = 0; j <= 6; j += 3) {
            int id = i + j / 3;
            for(int p = i; p < i + 3 and p < N; ++p){
                for(int q = j; q < j + 3 and q < N; ++q){
                    box[p][q] = id;
                }
            }
        }
    }
    for(int i = 0; i < maxn; ++i) mp[1 << i] = i;
    for(int i = 0; i < M; ++i) {
        int cnt = 0;
        for(int j = i; j; j -= lowbit(j)) {
            cnt++;
        }
        ones[i] = cnt;
    }
    while(cin >> x, x != "end") {
        init();
        int cnt= 0;
        for(int p = 0; p < x.size(); ++p){
            char ch = x[p];
            int i = p / N, j = p % N;
            if(ch == '.') a[p] = 0, cnt++;
            else{
                a[p] = ch - '0';
                int dx, dy;
                get2d(p, dx, dy);
                row[dx] &= (~(1 << (a[p] - 1)));
                col[dy] &= (~(1 << (a[p] - 1)));
                int id = box[dx][dy];
                vis[id] &= (~(1 << (a[p] - 1)));
            }
        }
        dfs(cnt);
        print();
    }
}