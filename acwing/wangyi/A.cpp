#include <bits/stdc++.h>
using namespace std;
#define int long long
int e[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char r[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
string gs;
char Get(const string& x) {
    int sum = 0;
    for (int i = 0; i < x.size() - 1; ++i) {
        int num = x[i] - '0';
        sum += e[i] * num;
    }

    int m = sum % 11;
    return r[m];
}

int cnt;
void dfs(string s, int cur) {
    if (cur == 17) {
        if (Get(s) == s[17]) {
            cnt ++;
        }
        return ;
    }

    if (s[cur] == '*') {
        for (char i = '0'; i <= '9'; ++i) {
            s[cur] = i;
            dfs(s, cur + 1);
        }
    }
    else {
        dfs(s, cur + 1);
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
    int T;
    cin >> T;
    while (T--) {
        cnt = 0;
        cin >> gs;

        dfs(gs, 14);

        cout << cnt << "\n";
    }
    
    return 0;
}