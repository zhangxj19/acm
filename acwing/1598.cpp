#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;

struct Node {
    int v;
    int l, r;
}node[N];
int n, a[N], idx;
void inorder(int cur) {
    if (cur == -1) return ;
    inorder(node[cur].l);

    node[cur].v = a[idx++];

    inorder(node[cur].r);
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
    int n; 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> node[i].l >> node[i].r;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    idx = 0;
    inorder(0);
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        if (cur != -1) {
            cout << node[cur].v << " ";
            que.push(node[cur].l);
            que.push(node[cur].r);
        }
    }

    return 0;
}