#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+1;
int n, m, ind[maxn], vis[maxn];
vector<vector<int>> g;
vector<int> re;
queue<int> que;

int get() {
    if(que.empty()) return -1;
    else{
        int re = que.front();
        que.pop();
        return re;
    }
}

void solve(){
    int x = -1;
    while((x = get()) != -1) {
        re.push_back(x);
        for(auto& v : g[x]) {
            ind[v]--;
            if(ind[v] == 0) que.push(v);
        }
    }
    if(re.size() != n) cout << "-1" << "\n";
    else {
        for(int i = 0; i < n; ++i){
            cout << re[i] + 1 << " ";
        }
        cout<< "\n";
    }
}

int main(){
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>n >> m;
    g.assign(n, vector<int>());
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        ind[y]++;
    }
    for(int i = 0 ;i < n; ++i) if(ind[i] == 0) que.push(i);

    solve(); 
}