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

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  for (int i = 0; i < 8; ++i) {
    string x;
    cin >> x;
    a += x;
  }

  priority_queue<pis, vector<pis>, greater<pis>> pq;
  pq.push({0, "12345678"});
  unordered_set<string> vis;
  unordered_map<string, char> pre;
  int ans = 0; 
  while (pq.size()) {
    string cur = pq.top().second;
    int dist = pq.top().first;
    pq.pop();

    if (vis.count(cur)) {
      continue;
    }
    vis.insert(cur);

    if (cur == a) {
      ans = dist;
      break;
    }

    pq.push({dist + 1, A(cur)});
    pre[A(cur)] = 'A';
    pq.push({dist + 1, B(cur)});
    pre[B(cur)] = 'B';
    pq.push({dist + 1, C(cur)});
    pre[C(cur)] = 'C';
  }

  cout << ans << "\n";

  vector<char> res;
  string x = a;
  string beg("12345678");


    
  return 0;
}