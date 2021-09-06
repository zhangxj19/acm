#include <bits/stdc++.h>
using namespace std;
#define int long long
using pis = pair<int, string>;
const int n = 8;
string a;

string A(const string& x) {
  string ans(8, '0');
  for (int i = 0; i < 8; ++i) {
    ans[i] = x[7 - i];
  }
  return ans;
}

string RA(const string& x) {
  return A(x);
}

string B(const string& x) {
  string ans(8, '0');
  ans[0] = x[3];
  ans[1] = x[0];
  ans[2] = x[1];
  ans[3] = x[2];
  ans[4] = x[5];
  ans[5] = x[6];
  ans[6] = x[7];
  ans[7] = x[4];
  return ans;
}

string RB(const string& x) {
  string ans(8, '0');
  ans[0] = x[1];
  ans[1] = x[2];
  ans[2] = x[3];
  ans[3] = x[0];
  ans[4] = x[4];
  ans[5] = x[7];
  ans[6] = x[6];
  ans[7] = x[5];
  return ans;
}

string C(const string& x) {
  string ans(8, '0');

  ans[0] = x[0];
  ans[1] = x[6];
  ans[2] = x[1];
  ans[3] = x[3];
  ans[4] = x[4];
  ans[5] = x[2];
  ans[6] = x[5];
  ans[7] = x[7];

  return ans;
}

string RC(const string& x) {
  string ans(8, '0');

  ans[0] = x[0];
  ans[1] = x[2];
  ans[2] = x[5];
  ans[3] = x[3];
  ans[4] = x[7];
  ans[5] = x[6];
  ans[6] = x[1];
  ans[7] = x[4];

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
  string op;
  cin >> op;
  string x("12345678");
  for (auto ch : op) {
    if (ch == 'A') {
      x = A(x);
    }
    else if (ch == 'B') {
      x = B(x);
    }
    else if (ch == 'C') {
      x = C(x);
    }
  }
  cout << x << "\n";


    
  return 0;
}