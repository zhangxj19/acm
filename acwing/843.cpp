#include <bits/stdc++.h>

using namespace std;
const int maxn = 10;
int n, vis[3][2*maxn], r[maxn];

void dfs(int cur) {
    if(cur == n){
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(j == r[i]) cout << "Q";
                else cout << ".";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }    
    for(int c = 0; c < n; ++c) {
        if(!vis[0][c] and !vis[1][cur + c] and !vis[2][cur - c + n]) {
            vis[0][c] = vis[1][cur + c] = vis[2][cur - c + n] = 1;
            r[cur] = c;
            dfs(cur+1);
            vis[0][c] = vis[1][cur + c] = vis[2][cur - c + n] = 0;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    dfs(0);
    
}