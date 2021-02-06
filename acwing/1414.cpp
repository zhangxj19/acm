#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 1;
int n, a[maxn], s[maxn];

struct Node {
    int ch[2], cnt, idx;
    Node() {
        cnt = 0;
        ch[0] = ch[1] = 0;
        idx = 0;
    }
}node[maxn];

int nsize, head;
void init() {
    nsize = 1;
    head = 0;
}
int newnode() {
    return nsize++;
}

void add(int x, int idx) {
    int nd = head;
    for(int i = 31; i >= 0; --i) {
        int bit = x >> i & 1;
        if(!node[nd].ch[bit]) {
            node[nd].ch[bit] = newnode();
        }
        nd = node[nd].ch[bit];
    }
    node[nd].cnt = 1;
    node[nd].idx = max(node[nd].idx, idx);
}

int check(int x, int& idx) {
    int nd = head;
    int re = 0;
    for(int i = 31; i >= 0; --i) {
        int bit = x >> i & 1;
        if(node[nd].ch[!bit]) {
            nd = node[nd].ch[!bit];
            re |= 1 << i;
        }
        else {
            nd = node[nd].ch[bit]; 
        }
    }
    idx = node[nd].idx;
    return re;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    init();
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        s[i + 1] = s[i] ^ a[i];
        add(s[i+1], i + 1);
    } 

    int re = 0, st, ed;
    for(int i = 1; i <= n; ++i) {
        int ted;
        int t = check(s[i], ted);
        if(t >= re) {
            re = t;
            st = i;
            ed = ted;
            cout << t << " " << st << " " << ed << "\n";
        }
    }
    if(st > ed) swap(st, ed);
    if(st == ed) cout << re << " " << st << " " << ed << "\n";
    else 
        cout << re << " " << st+1 << " " << ed << "\n";



}