#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>

#define int long long
using namespace std;
using pii = pair<int, int>;
int n, sum[500005], f[500005][20];
int k, L, R;

int query(int l, int r) {
  int t = log2(r - l + 1);
  int x = f[l][t];
  int y = f[r - (1 << t) + 1][t];
  return sum[x] > sum[y] ? x : y;
}

struct Node {
  int beg, t;
  int l, r;
  Node() {}
  Node (int beg, int l, int r):beg(beg), l(l), r(r), t(query(l, r)) {}

  friend bool operator < (const Node& x, const Node& y) {
    return sum[x.t] - sum[x.beg - 1] < sum[y.t] - sum[y.beg - 1];
  }

};


signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n >> k >> L >> R;
  for (int i = 1; i <= n; ++i) {
    cin >> sum[i];
    sum[i] += sum[i - 1];
  }

  for (int j = 0; j < 20; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      if (!j) {
        f[i][j] = i;
      }
      else {
        int a = f[i][j - 1], b = f[i + (1 << (j - 1))][j -1];
        f[i][j] = sum[a] > sum[b] ? a : b;
      }
    }
  }
  
  // pii <sum, index>
  priority_queue<Node> pq;
  for (int i = 1; i + L - 1 <= n; ++i) {
    pq.push(Node(i, i + L - 1, min(i + R - 1, n)));
  }

  int res = 0;
  while (k--) {
    int beg = pq.top().beg;
    int t = pq.top().t;
    int l = pq.top().l;
    int r = pq.top().r;
    pq.pop();
    res += sum[t] - sum[beg - 1];

    if (t != l) {
      pq.push(Node(beg, l, t - 1));
    }

    if (t != r) {
      pq.push(Node(beg, t + 1, r));
    }
  }

  cout << res << "\n";
  return 0;
}