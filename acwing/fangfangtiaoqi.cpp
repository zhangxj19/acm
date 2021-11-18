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

#define int long long
using namespace std;
using pii = pair<int, int>;

struct Node;
map<string, Node*> mp;
string getKey(int row, int col) {
  return to_string(row) + ' ' + to_string(col);
}
struct Node {
  int row, col;
  int valid, isocupied;
  Node *l, *r, *ul, *ur, *ll, *lr;// left, right, up left, up right, low left, low right;
  Node (int row, int col):row(row), col(col) {
    valid = isocupied = 0;
    mp[getKey(row, col)] = this;
  }
};

Node* getNode(int row, int col) {
  string key = getKey(row, col);
  if (!mp.count(key)) {
    mp[key] = new Node(row, col);
  }
  return mp[key];
}

void generateBoard() {
  for (int row = 0; row <= 18; ++row) {
    for (int col = 0; col <= 14; ++col) {
      getNode(row, col);
    }
  }

  // 1 - 4;
  for (int row = 1; row <= 4; ++row) {
    for (int col = 1; col <= row; ++col) {
      Node * n = getNode(row, col);
      

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

  generateBoard();


    
  return 0;
}