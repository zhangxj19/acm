#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m;
int a[N];

struct SegmentTree {
    int l, r;
    int dat;
    int sum, lmax, rmax;
} t[4 * N];

void build(int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    if (l == r) {
        t[p].dat = t[p].sum = t[p].lmax = t[p].rmax = a[l];
        return ;
    }
    else {
        int mid = (l + r) / 2;
        build(2*p, l, mid);
        build(2*p + 1, mid + 1, r);

        t[p].sum = t[2*p].sum + t[2*p+1].sum;
        t[p].lmax = max(t[2*p].lmax, t[2*p].sum+t[2*p+1].lmax);
        t[p].rmax = max(t[2*p+1].rmax, t[2*p+1].sum+t[2*p].rmax);
        t[p].dat = max(t[p*2].dat, max(t[p*2+1].dat, t[p*2].rmax + t[p*2+1].lmax));
    }
}

void change(int p, int x, int v) {
    if (t[p].l == t[p].r) {
        t[p].dat = t[p].sum = t[p].lmax = t[p].rmax = v;
        return ;
    }
    else {
        int mid = (t[p].l + t[p].r) / 2;
        if (x <= mid) {
            change(2*p, x, v);
        }
        else {
            change(2*p+1, x, v);
        }
        t[p].sum = t[2*p].sum + t[2*p+1].sum;
        t[p].lmax = max(t[2*p].lmax, t[2*p].sum+t[2*p+1].lmax);
        t[p].rmax = max(t[2*p+1].rmax, t[2*p+1].sum+t[2*p].rmax);
        t[p].dat = max(t[p*2].dat, max(t[p*2+1].dat, t[p*2].rmax + t[p*2+1].lmax));
    }
}

int ask(int p, int l, int r) {
    if (t[p].l >= l and t[p].r <= r) {
        return t[p].dat;
    }
    int mid = (t[p].l + t[p].r) / 2;
    int val = -1e9;
    if (l <= mid) {
        val = max(val, ask(p * 2, l, r));
    }
    if (r > mid) {
        val = max(val, ask(p * 2 + 1, l, r));
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
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; ++i){
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1) {
            if (x > y) {
                swap(x, y);
            }
            cout << ask(1, x, y) << "\n";
        }
        else {
            change(1, x, y);
        }
    }


}