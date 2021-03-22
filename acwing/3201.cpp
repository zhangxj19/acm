#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
struct Node {
    int x;
    Node * nxt;
}a[N];

int sz;
Node * newnode(int x) {
    sz++;
    Node * re = new Node;
    re->x = x;
    re->nxt = nullptr;
    return re;
}
int m, n;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    Node *head = newnode(-1);
    Node *now;
    now = head;
    while(cin >> x, x != 0) {
        Node *nn = newnode(x);
        now->nxt = nn;
        now = nn;
    }
    cin >> m >> n;

    #ifdef DEBUG
    now = head->nxt;
    while(1) {
        cout << now->x << " ";
        if(now->nxt != nullptr) now = now->nxt;
        else break;
    }
    cout << "\n";
    #endif

    now = head->nxt;
    Node *prenow = head;
    int cnt = 0;
    
    cnt = 0;
    while(cnt != m) {
        now = now->nxt;
        prenow = prenow->nxt;
        cnt++;
    }
    Node* pre = prenow, *pnxt = now;
    Node* rear;

    for(; cnt <= n; ++cnt) {
        Node *t = now->nxt, *pt = now;
        now->nxt = prenow;
        prenow = pt;
        if(cnt == n) pre->nxt = now;
        now = t;
        if(cnt == n) {
            pnxt->nxt = now;
        }
    }

    now = head;
    while(now->nxt != nullptr) {
        now = now->nxt;
        cout << now->x << " ";
        if(now == nullptr) break;
    }
    cout << "\n";

    






    
}