#include <bits/stdc++.h>
using namespace std;
#define int long long
using pis = pair<int, string>;
const int n = 8;
string a;
const string beg = "12345678";

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

  unordered_set<string> vis;
  unordered_map<string, int> dist;
  unordered_map<string, pair<char, string>> pre;
  queue<string> que;
  que.push(beg);
  vis.insert(beg);
  dist[beg] = 0;

  int ans = 0; 
  while (que.size()) {
    string cur = que.front();
    que.pop();

    if (cur == a) {
      ans = dist[cur];
      break;
    }

    string v[3];
    v[0] = A(cur);
    v[1] = B(cur);
    v[2] = C(cur);

    for (int i = 0; i < 3; ++i) {
      if (!vis.count(v[i])) {
        vis.insert(v[i]);
        dist[v[i]] = dist[cur] + 1;
        que.push(v[i]);
        pre[v[i]] = {'A' + i, cur};
      }
    }
  }

  cout << ans << "\n";

  if (ans) {
    vector<char> res;
    string x = a;
    string beg("12345678");

    while (x != beg) {
      char op = pre[x].first;
      x = pre[x].second; 
      res.push_back(op);
    }
    for (int i = res.size() - 1; i > -1; --i) {
      cout << res[i];
    }
    cout << "\n";

  }


    
  return 0;
}