#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int power(int a, int b, int mod) {
  int res = 1;
  for (;b;b >>= 1) {
    if (b & 1) {
      res = res * a % mod;
    }

    a = a * a % mod;
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
  int n;
  cin >> n;
  while (n--) {
    int a, p;
    cin >> a >> p;
    if (gcd(a, p) == 1) { 
      cout << power(a, p - 2, p) % p << "\n";
    } 
    else {
      cout << "impossible\n";
    }
  }

    
  return 0;
}