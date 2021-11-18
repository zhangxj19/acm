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
  int data;
  Node * next;
};

// 0 1 2 3 4 5 (miss) 6... 99
// 

int sum(Node * head) {
  int res = 0;

  // 99 add * 1
  // 200 load * 100 
  auto p = head->next;
  while (head) {
    res += head->data; // 1 cycle add 100 cycle load
    head = head->next; // 100 
  }

  return res;
}

Node* reverse(Node *head) {
  if (head == nullptr or head->next == nullptr) {
    return head;
  }

  Node * next = head->next;
  Node * res = reverse(head->next);
  if (next) {
    next->next = head;
  }

  head->next = nullptr;

  return res;
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