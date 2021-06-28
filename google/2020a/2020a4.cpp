#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;

int n, k, dist[N];

struct Node{
    int pcnt, cnt;
    int c[26]; // child
}node[N];

int head, sz;

void init() {
    head = 0;
    sz = 0;
    memset(node, 0, sizeof node);
    memset(dist, 0, sizeof dist);
}

int newnode() {
    return ++sz;
}

void insert(string& x) {
    int n = head;
    for(auto& ch : x) {
        if(node[n].c[ch - 'A'] == 0) {
            int nx = newnode();
            node[n].c[ch-'A'] = nx;
        }
        node[n].pcnt++;
        n = node[n].c[ch - 'A'];
    }
    node[n].cnt++;
    node[n].pcnt++;
}

void solve() {
    cin >> n >> k;
    init();
    for(int i = 0;i < n; ++i) {
        string x;
        cin >> x;
        insert(x);
    }

    int re = 0;
    queue<int> que({head});
    while(!que.empty()) {
        int x = que.front(); que.pop();

        if(x != head) re += node[x].pcnt / k;
        #ifdef DEBUG
        cout << node[x].pcnt << " ";
        #endif

        if(node[x].pcnt / k > 0) {
            for(int i = 0; i < 26; ++i) {
                int v = node[x].c[i];
                if(v != 0) {
                    que.push(v);
                }
            }
        }
    }

    cout << re << "\n";
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}