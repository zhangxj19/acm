#include <bits/stdc++.h>
using namespace std;

// 
ListNode* reverseLink(ListNode* node) {
  // a->b->c;
  // a<-b b->c;
  // a<-b<-c;
  auto p = node;
  ListNode *pre = nullptr;
  while (p) {
    auto q = p->next;
    p->next = pre;
    pre = p;
    p = q;
  }
  return p;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    return 0;
}