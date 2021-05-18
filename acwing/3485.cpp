#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 31e5 + 5;
int n, m, a[N], sum[N];

struct TrieNode {
    int d, cnt;
    int next[3];
}t[N]; // root at 0
int nt, sz;

int newnode() {
   return ++nt; 
}

void add(int x, int c) {
    int cur = 0;
    for (int i = 31; i > -1; --i) {
        int v = (x >> i) & 1;
        if (!t[cur].next[v]) {
            t[cur].next[v] = newnode();
        }
        cur = t[cur].next[v];
        t[cur].cnt += c;
    }
    ++ sz;
}

int findmax(int x) {
    int cur = 0;
    int ret = 0;
    for (int i = 31; i > -1 ; --i) {
        int v = (x >> i) & 1;
        int nxt = t[cur].next[!v];
        if (t[nxt].cnt) {
            ret |= 1 << i;

            cur = nxt;
        }
        else {
            cur = t[cur].next[v];
        }
    }

    return ret;
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
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i-1] ^ a[i];
    }

    int ret = 0;
    add(sum[0], 1);
    for (int i = 1; i <= n; ++i) {
        if (sz > m) {
            add(sum[i - m - 1], -1);
        }
        ret = max(ret, findmax(sum[i]));
        #ifdef DEBUG
        cout << ret << " " << sz << "\n";
        #endif
        add(sum[i], 1);
    }
    
    cout << ret << "\n";

    
    return 0;
}