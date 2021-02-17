#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define pii pair<int, int>
const int N = 1e4 + 2;
int w, h, l, u, r, d;
int mem[N][N];

string gethash(int x, int y) {
    string re;
    re += to_string(x);
    re += "_";
    re += to_string(y);
    return re;
}

int onborder(int x, int y) {
    return x == w or y == h;
}

double po(int x, int y) {
    if(x == 0 or y == 0) return 0;
    if(x == 1 and y == 1) return 1;
    if(!onborder(x, y)) {
        return mem[x][y] * pow(0.5, (x + y - 2));
    }
    else {
        if(x == w and y == h) return po(x - 1, y) + po(x, y - 1);
        if(x == w) {
            return po(x - 1, y) * 0.5 + po(x, y-1);
        }
        if(y == h) {
            return po(x, y - 1) * 0.5 + po(x-1, y);
        }
    }
}





void solve() {
    cin >> w >> h >> l >> u >> r >> d;

    memset(mem, 0, sizeof mem);
    mem[1][1] = 1;
    for(int i = 1; i <= w; ++i) {
        for(int j = 1; j <= h; ++j) {
            if(i == 1 and j == 1) continue;
            mem[i][j] = mem[i][j-1] + mem[i-1][j];
        }
    }
    double re = 0;



    // l u
    re += po(l, u);

    for(int i = l + 1; i <= r; ++i) {
        if(onborder(i, u)) re += po(i, u-1);
        else re += po(i, u - 1) * 0.5;
    }

    for(int j = u + 1; j <= d; ++j) {
        if(onborder(l, j)) re += po(l - 1, j);
        else re += po(l - 1, j) * 0.5;
    }

    #ifdef DEBUG2
    cout << "\n";
    for(int j = 0; j <= h; ++j) {
        for(int i = 0; i <= w; ++i) {
            cout << mem[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for(int j = 0; j <= h; ++j) {
        for(int i = 0; i <= w; ++i) {
            cout << po(i, j) << " ";
        }
        cout << "\n";
    }
    cout << re << " ";
    #endif

    cout << 1 - re << "\n";
}
//Recover39233875 Tusundere_north Keaiduo555(x121314666, tt22709991, aiheguozhi123(tuzi121314666)) nidevye jingjingsijiaoS(js, hot)

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}