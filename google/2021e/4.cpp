#include <bits/stdc++.h>
using namespace std;
#define int long long
double N;

void solve() {
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    a[i] = i + 1;
  }
  double sum = 0;
  double cnt = 0;
  do {
    cnt ++;
    sum ++;
    int cur = a[0];
    for (int i= 1; i < N; ++i) {
      if (a[i] > cur ) {
        cur = a[i];
        sum ++;
      }
    }
  } while (next_permutation(a.begin(), a.end()));

#ifdef DEBUG2
cout << sum << " " << cnt << "\n";
#endif
  cout << to_string(sum / cnt) << "\n";




}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}