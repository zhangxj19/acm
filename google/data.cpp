#include <bits/stdc++.h>
using namespace std;
#define int long long
int lb, ub;

int randint(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int CharToInt(const char *c) {
    int re = 0;
    for (int i=  0 ; c[i] != '\0'; ++i) {
        re = re * 10 + c[i] - '0';
    }
    return re;
}


signed main(signed argc, char ** argv) {
    // #ifdef LOCAL
    // freopen("in", "r", stdin);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(0);
    lb = CharToInt(argv[2]);
    ub = CharToInt(argv[3]);

    int n;
    // cin >> n;
    n = CharToInt(argv[1]);
    cout << n << "\n";
    while (n--) {
        int r = randint(lb, ub), c = randint(lb, ub);
        cout << r << " " << c << "\n";

        for (int i = 1; i <= r; ++i ) {
            for (int j = 1; j <= c; ++j) {
                int v = randint(0, ub);
                cout << v  << " ";
            }
            cout << "\n";
        }

    }

}