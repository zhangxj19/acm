#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node {
    int v;
    Node * next;
};

Node* func(Node* head) {
    if (head == nullptr or head->next == nullptr) {
        return head;
    }

    Node *ret = func(head->next);
    head->next = head;

    return ret ;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
}