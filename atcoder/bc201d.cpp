#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 5;
int h, w;
char a[N][N];
int f[N][N][N][N][2];

int game(int sa, int sb, int x, int y, int p1) {
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> a[i][j];
        }
    }
    memset(f, -1, sizeof f);

    int v = game(0, 0, 0, 0, 1);
    if (v == 1) {
        cout << "Takahashi" << "\n";
    }
    else if (v == 2){
        cout << "Aoki" << "\n";
    }
    else if (v == 0){
        cout << "Draw" << "\n";
    }

    
    return 0;
}