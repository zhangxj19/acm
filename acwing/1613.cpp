#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x & (-x))
const int n = 9, maxn = 10, M = 1 << maxn;
int r[maxn], c[maxn], g[maxn][maxn], ones[M], mp[M];
char a[maxn][maxn];

int get(int x, int y) {
    return r[x] & c[y] & g[x/3][y/3];
}

void setbit(int x, int y, int num, int isone) {
    if(isone) {
        r[x] |= 1 << (num);
        c[y] |= 1 << (num);
        g[x/3][y/3] |= 1 << (num);        
    }
    else {
        r[x] &= (~(1 << (num)));
        c[y] &= (~(1 << (num)));
        g[x/3][y/3] &= (~(1 << (num)));
    }
}

int dfs(int cnt) {
    
    if(cnt == 0) return 1;

    int x, y, mind = n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i][j] == '.') {
                int state = get(i, j);
                int _1 = ones[state];
                if(_1 < mind) {
                    mind = _1;
                    x = i;
                    y = j;
                }                
            }
        }
    }
    // cout << cnt << "\n";
    // cout << x << " " << y << " " << mind << "\n";

    for(int s = get(x, y); s; s -= lowbit(s)) {
        char num = mp[lowbit(s)] + '1';
        a[x][y] = num;

        setbit(x, y, a[x][y] - '1', 0);
        if(dfs(cnt - 1)) return 1;
        setbit(x, y, a[x][y] - '1', 1);

        a[x][y] = '.';
    }
    return 0;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < maxn; ++i) mp[1 << i] = i;
    for(int i = 0; i < M; ++i) {
        int cnt = 0;
        for(int j = i; j; j -= lowbit(j)) cnt++;
        ones[i] = cnt;
    }
    for(int i = 0; i < n; ++i) {
        r[i] = (1 << n) - 1;
        c[i] = (1 << n) - 1;
        for(int j = 0; j < n; ++j) {
            g[i][j] = (1 << n) - 1;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        for(int j = 0; j < n; ++j) {
            if(a[i][j] == '.') cnt++;
            else {
                setbit(i, j, a[i][j] - '1', 0);
            }
        }
    }    

    dfs(cnt);

    for(int i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }

}