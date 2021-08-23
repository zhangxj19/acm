#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MXN = 1005, MXM = 505, MXK = 105;
int N, M, K;
int a[MXN], b[MXN];
int C[MXN][MXM]; // [number of demon, number of ball, number of red]

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> N >> M >> K;
  for (int i = 1; i <= K; ++i) {
    cin >> a[i] >> b[i];
  }

  for (int i = 1; i <= K; ++i) {
    for (int j = N; j - a[i] >= 0; --j) {
      for (int k = M; k - b[i] >= 0; --k) {
        C[j][k] = max(C[j][k], C[j - a[i]][k - b[i]] + 1); 
      }
    }
  }

  int mxc = 0, res = 0;
  for (int j = 0; j <= N; ++j) {
    for (int k = 0; k < M; ++k) {
      if (C[j][k] > mxc or C[j][k] == mxc and k < res) {
        mxc = C[j][k];
        res = k;  
      }
    }
  }
  cout << mxc << " " << M - res << "\n";

  return 0;
}