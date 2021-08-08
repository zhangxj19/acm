#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int , int>
const int N = 2e5 + 5;
int n, p[N];
unordered_map<int, int> mp;
int sz;

int find(int x) {
    if (x == p[x]) {
        return x;
    }
    return p[x] = find(p[x]);
}

int geti(int x) {
    if (!mp.count(x)) {
        mp[x] = sz++;
    }

    return mp[x];
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
    int T;
    cin >> T;
    while (T--) {
        // init
        mp.clear();
        sz = 0;
        cin >> n;
        // !init
        for (int i = 0; i < 2 * n; ++i) {
            p[i] = i;
        }
        vector<pii> neq;
        for (int i = 1; i <= n; ++i) {
            int a, b, e;
            cin >> a >> b >> e;
            a = geti(a);
            b = geti(b);
            if (!e) {
                neq.push_back({a, b});
            }
            else {
                // merge
                p[find(a)] = find(b);
            }
        }

        int ok = 1;
        for (auto& x : neq) {
            if (find(x.first) == find(x.second)) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    return 0;
}