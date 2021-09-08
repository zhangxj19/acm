#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long

const int mod = 1e9 + 7, N = 100005;
int n, a, b, fact[N], infact[N];

int qmi(int a, int b, int p) {
  int res = 1;
  for (;b;b >>= 1) {
    if (b & 1) {
      res = res * a % p;
    }
    a = a * a % p;
  }
  return res;
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
  fact[0] = infact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i % mod;
    infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
  }


  cin >> n;
  while (n--) {
    cin >> a >> b;
    cout << fact[a] * infact[a - b] % mod * infact[b] % mod << "\n";
  }

    
  return 0;
}