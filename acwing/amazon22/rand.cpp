#include <bits/stdc++.h>
using namespace std;
#define int long long

int randInt(int a, int b) {
  return (double)rand() / RAND_MAX * (b - a + 1) + a;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  srand((unsigned)time(NULL));
  int n = randInt(10, 10);
  cout << n << "\n";
  for (int i = 0; i < n; ++i) {
    cout << randInt(1, 100);
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << "\n";


    
  return 0;
}