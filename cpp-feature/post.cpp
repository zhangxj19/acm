#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#include <memory>

using namespace std;
using pii = pair<int, int>;

struct Node {
  int d;
  Node *left, *right;
};

void solve(Node *root) {
  stack<Node*> stk, opt;
  stk.push(root);

  while (stk.size()) {
    Node *cur = stk.top();
    stk.pop();

    opt.push(cur);

    if (cur->left != nullptr) {
      stk.push(cur->left);
    }

    if (cur->right != nullptr) {
      stk.push(cur->right);
    }
  }
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

    
  return 0;
}