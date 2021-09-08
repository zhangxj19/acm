#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long
const int N = 5005;
int a, b, p;

int qmi(int a, int b, int p) {
  int res = 1;
  for (;b; b >>= 1) {
    if (b & 1) {
      res = res * a % p;
    }
    a = a * a % p;
  }

  return res;
}

int C(int a, int b, int p) {
  if (a < b) {
    return 0;
  }
  int res = 1;
  for (int i = a, j = 1; j <= b; ++j, -- i) {
    res = res * i % p;
    res = res * qmi(j, p - 2, p) % p;
  }

  return res;

}

int lucas(int a, int b, int p) {
  if (a < p and b < p) {
    return C(a, b, p);
  }
  return C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
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
    cin >> a >> b >> p;
    cout << lucas(a, b, p) << "\n";   
  }

    
  return 0;
}