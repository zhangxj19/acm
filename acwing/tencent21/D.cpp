#include <bits/stdc++.h>
using namespace std;
#define int long long

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
    int q;
    cin >> q;
    vector<int> que(1005, 0);
    int head = 0, rear = -1;

    while (q--) {
      string cmd;
      cin >> cmd;
      int x;
      if (cmd == "PUSH") {
        cin >> x;
        que[++rear] = x;
      }
      else if (cmd == "TOP") {
        if (rear == head - 1) {
          cout << "-1\n";
        }
        else {
          cout << que[head] << "\n";
        }
      }
      else if (cmd == "POP") {
        if (rear == head - 1) {
          cout << "-1\n";
        }
        else {
          head ++;
        }
      }
      else if (cmd == "SIZE") {
        cout << rear - head + 1 << "\n";
      }
      else if (cmd == "CLEAR") {
        head = 0;
        rear = -1;
      }
    }
  }
    
  return 0;
}