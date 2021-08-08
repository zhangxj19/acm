#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, P = 131;
using ull = unsigned long long;
string s;
int n;
ull p[N], f[N], rf[N];

ull getHash(int l, int r) {
    if (l > r) {
        return 0;
    }
    return f[r + 1] - f[l] * p[r - l + 1];
}

ull getHashR(int l, int r) {
    // 假设原来的字符串是 a0 ... an - 1
    // rf存储的hash前缀和是按照 an-1 ... a0 顺序生成的
    // 当需要取 al ... ar 的字符串hash值，其实是取 rf 的 ar ar+1 ... al-1 al 部分hash值
    // 输入 [l, r] 是按照原来字符串顺序给定，其在 rf 中位置是 [n-1-r, n-1-l] = "l, r", 即可以使用原来的
    // 求部分字串 hash 公式 rf[r + 1] - rf[l] * p[r - l + 1];
    if (l > r) {
        return 0;
    }
    l = n - 1 - l;
    r = n - 1 - r;
    swap(l, r);
    return rf[r + 1] - rf[l] * p[r - l + 1];
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
    int caseId= 0;
    while (cin >> s, s != "END") {
        cout << "Case " << ++caseId << ": ";

        // presum of f
        n = s.size();
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] * P;
            f[i] = f[i - 1] * P + s[i - 1] - 'a' + 1;
            // i - 1 -> n - 1 - (i - 1) = n - i
            rf[i] = rf[i - 1] * P + s[n - i] - 'a' + 1;
        }

        int ans = 1;
        int l, r;
        for (int i = 0; i < n; ++i) {
            // od 
            #ifdef DEBUG
            cout << "\n" <<  i << " " << s[i] << " ";
            #endif
            l = 0, r = min(i, n - 1 - i);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (getHashR(i - mid, i - 1) == getHash(i + 1, i + mid)) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            #ifdef DEBUG
            cout << "len = " << l << "; ";
            #endif
            ans = max(ans, 2 * l + 1);

            // even      
            l = 0, r = min(i + 1, n - 1 - i);
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (getHashR(i - mid + 1, i) == getHash(i + 1, i + mid)) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            #ifdef DEBUG
            cout << "len = " << l << "\n";
            #endif
            ans = max(ans, 2 * l);
        }
        cout << ans << "\n";
    }
    
    return 0;
}