#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, w;

int last(vector<int>& a, int x) {
  // last a[i] <= x;
  int l = 0, r = a.size() - 1;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (a[mid] <= x) {
      l = mid;
    }
    else {
      r = mid - 1;
    }
  }
  if (a[l] <= x) {
    return l;
  }
  else {
    return -1;
  }
}

int getSize(vector<int>& v) {
  if (v.size() == 0) {
    return 0;
  }
  int ans = 0;
  int x = v[0], y = w - x;
  int index = last(v, y);
  #ifdef DEBUG
  cout << x << " find " << y << " at " << index << "\n";
  #endif
  if (index <= 0) {
    ans += v.size();
  }
  else {
    // [0, index] (index + 1 + 1) / 2
    // [index + 1, size - 1]
    ans += (index - 0 + 1 + 1) / 2;
    ans += (v.size() - 1 - (index + 1) + 1);
  }
  return ans;
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
    cin >> n >> w;
    vector<int> odd, even;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      if (x % 2 == 0) {
        even.push_back(x);
      }
      else {
        odd.push_back(x);
      }
    }

    // [(n + 1) / 2, n];
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());


    int ans = 0;

    // odd;
    ans += getSize(odd);
    ans += getSize(even);
    
    cout << ans << "\n";
  }
    
  return 0;
}