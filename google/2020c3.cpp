#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 1, M = 1e7 + 1;
int sq[M];
int n;
int a[N], s[N];

string bina(int x) {
    string re = "";
    while(x) {
        re += to_string(x % 2);
        x /= 2;
    }
    reverse(re.begin(), re.end());
    return re;
}


void solve() { 
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }

    #ifdef DEBUG
    cout << "\n";
    for(int i = 1; i <= n; ++i) cout << a[i - 1] << " ";
    cout << "\n";
    for(int i = 1; i <= n; ++i) cout << s[i] << " ";
    cout << "\n";
    #endif
    int re = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            int sum = s[j + 1] - s[i];
            if(sum >= 0 and sq[sum]) re++;
        }
    }
    cout << re << "\n";
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i * i < M; ++i) sq[i * i] = 1;
    #ifdef DEBUG
    for(int i = 0; i < 100; ++i) {
        if(sq[i]) cout << i << " " << bina(i) << "\n";
    }
    #endif
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}