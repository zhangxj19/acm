#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<string> msg {
        "Hello",
        "there",
    };
    for (const auto& word : msg) {
        cout << word << " ";
    }
    cout << "\n";

}