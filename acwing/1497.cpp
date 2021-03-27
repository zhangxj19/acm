#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 35;
struct Node {
    int x;
    int lc, rc;
}a[N];
int sz;
void init() {
    sz = 0;
}
int newnode() {
    return ++sz;
}
int n;
int post_od[N], in_od[N];

int build(int pl, int pr, int il, int ir) {
    // pl,..., pr-1, pr
    // il, ...,left_r, r, ..., ir
    if(pl > pr) return 0;
    // else if(pl == pr) {
    //     int rt = newnode();
    //     a[rt].x = post_od[pr];
    //     return rt;
    // }
    else {
        int rt = newnode(), rt_v = post_od[pr];
        a[rt].x = rt_v;
        int in_rt = 0;
        for(in_rt = il; in_rt <= ir and in_od[in_rt] != rt_v; ++in_rt);
        int left_len = in_rt - il;
        
        a[rt].lc = build(pl, pl + left_len - 1, il, in_rt - 1);
        a[rt].rc = build(pl + left_len, pr - 1, in_rt + 1, ir);

        return rt;
    }
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> post_od[i];
    for(int i = 0; i < n; ++i) cin >> in_od[i];
    int rt = build(0, n-1, 0, n-1);

    queue<int> que({rt});
    while(!que.empty()) {
        int x = que.front();
        que.pop();

        cout << a[x].x << " ";

        if(a[x].lc) que.push(a[x].lc);
        if(a[x].rc) que.push(a[x].rc);
    }
    cout << "\n";
    
}