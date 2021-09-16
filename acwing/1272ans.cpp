#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>
#include <iostream>
inline long long IO() {
    long long x = 0;
    bool f = false;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') f = true;
        c = getchar();
    }
    while (isdigit(c)) {
        x = (x << 1) + (x << 3) + (c - '0');
        c = getchar();
    }
    return f ? -x : x;
}
using namespace std;

const int N = 2e6 + 5, M = 2e5 + 5, dif = 1e6;
int lg[M] = {-1}, st[M][30], n, m, len[M], a[M], cnt[N], indx[M];
// st表预处理, 注意下标从1开始到n结束
void init(int *a, int n) {
    for (int i = 1; i <= n; ++i) lg[i] = lg[i >> 1] + 1, st[i][0] = a[i];
    for (int j = 1; j <= lg[n]; ++j) {
        int k = 1 << (j - 1);
        for (int i = 1; i + k - 1 <= n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + k][j - 1]);
        }
    }
}
// 询问
int get(int l, int r) {
    int x = lg[r - l + 1];
    return max(st[l][x], st[r - (1 << x) + 1][x]);
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
    n = IO(), m = IO();
    for (int i = 1; i <= n; ++i) a[i] = IO();
    for (int l = 1, r = 1; r <= n; ++r) {
        int i = a[r] + dif;
        ++cnt[i];
        while (l < r && cnt[i] > 1) --cnt[a[l++] + dif];
        len[r] = r - l + 1, indx[r] = l;
    }

  #ifdef DEBUG
  for (int i=  1;i <= n; ++i) {
    cout << indx[i] << " ";
  }
  cout << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << len[i] << " ";
  }
  cout << '\n';
  #endif
    init(len, n);
    while (m--) {
        int a = IO() + 1, b = IO() + 1;
        int l = a, r = b, res = a;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (indx[mid] < a) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        int ans = res - a + 1;
        if (res < b) ans = max(ans, get(res + 1, b));
        printf("%d\n", ans);
    }
    return 0;
}
