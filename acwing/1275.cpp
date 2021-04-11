#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;

struct SegmentTree {
    int l, r;
    int dat;
}t[4 * N];
int a[N];

void build(int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    if (l == r) {
        t[p].dat = a[l];
        return ;
    }

    int mid = (l + r) / 2;
    build(p*2, l, mid);
    build(p*2 + 1, mid + 1, r);

    t[p].dat = max(t[p*2].dat, t[p*2 + 1].dat);
}

void change(int p, int x, int v) {
    if (t[p].l == t[p].r) {
        t[p].dat = v;
        return ;
    } 

    int mid = (t[p].l + t[p].r) / 2;
    if (x <= mid) {
        change(2*p, x, v);
    }
    else {
        change(2*p+1, x, v);
    }
    t[p].dat = max(t[p*2].dat, t[p*2 + 1].dat);
}


int ask(int p, int l, int r) {
    if (l <= t[p].l and t[p].r <= r) {
        return t[p].dat;
    }
    int mid = (t[p].l + t[p].r) / 2;
    int val = -(1 << 30);
    if (l <= mid) {
        val = max(val, ask(2*p, l, r));
    }
    if (r > mid) {
        val = max(val, ask(2*p + 1, l, r));
    }
    return val;
}



signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, p;
    cin >> m >> p;
    build(1, 1, 2e5);
    int a = 0, sz = 0;
    while (m--) {
        char c;
        cin >> c;
        if (c == 'Q') {
            int l;
            cin >> l;
            cout << (a = ask(1, sz - l + 1, sz)) << "\n";
        }
        else {
            int t;
            cin >> t;
            change(1, ++sz, (t + a) % p);
        }
    }

    
}