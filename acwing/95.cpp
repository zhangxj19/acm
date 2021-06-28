#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10;
int n;
char a[N][N], b[N][N];

int dir[5][2] = {
    {0, 0},
    {0, 1},
    {0,-1},
    {1, 0},
    {-1, 0},
};

void turn(int x, int y) {
    for (int i = 0; i < 5; ++i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx <0 or nx >= 5 or ny <0 or ny >=5) {
            continue;
        }
        if (a[nx][ny] == '0') {
            a[nx][ny] = '1';
        }
        else {
            a[nx][ny] = '0';
        }
    }
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
    cin >> n;
    while (n--) {
        for (int i = 0 ; i < 5; ++i) {
            cin >> a[i];
        }
        int res = 1e9;
        for (int k = 0 ; k < (1 << 5); ++k) {
            memcpy(b, a, sizeof a);
            int cnt = 0;
            for (int j = 0 ; j < 5; ++j) {
                if (k >> j & 1) {
                    turn(0, j);
                    cnt ++;
                }
            }

            for (int i = 1 ; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (a[i-1][j] == '0') {
                        turn(i, j);
                        cnt ++;
                    }
                }
            }
            int ok = 1;
            for (int j = 0 ; j < 5; ++j) {
                if (a[4][j] == '0') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                res = min(res, cnt);
            }
            memcpy(a, b, sizeof b);
        }

        cout << ((res == 1e9 or res > 6) ? -1 : res) << "\n";

    }

    
    return 0;
}