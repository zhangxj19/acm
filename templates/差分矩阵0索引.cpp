#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+2;
int n, m, q;
int a[maxn][maxn], b[maxn][maxn];

void update(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x1][y2+1] -= c;
    b[x2+1][y1] -= c;
    b[x2+1][y2+1] += c;
}

int main(){
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
            update(i, j, i, j, a[i][j]);
        }
    }   
    while(q--){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        x1--;y1--;
        x2--;y2--;
        update(x1, y1, x2, y2, c);
    }

    memset(a, 0, sizeof a);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            a[i+1][j+1] = a[i][j+1] + a[i+1][j] - a[i][j] + b[i][j];
            cout << a[i+1][j+1] << " ";
        }
        cout << '\n';
    }
}