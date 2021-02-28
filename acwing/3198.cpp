#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 2560;
int n, m;

deque<vector<int>> que;

int inrange(int x, int y, vector<int>& a) {
    return a[0] <= x and x <= a[2] and a[1] <= y and y <= a[3];
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        que.push_front({x1, y1, x2, y2, i + 1});
    }

    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        int ok = 0;
        for(int j = 0; j < n; ++j) {
            if(inrange(x, y, que[j])) {
                ok = 1;
                vector<int> t = que[j];
                cout << t[4] << "\n"; 
                que.erase(j + que.begin());
                que.push_front(t);
                break;
            }
        }
        if(!ok) cout << "IGNORED\n";
    }

    
}