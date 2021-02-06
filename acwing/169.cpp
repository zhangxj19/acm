#include <bits/stdc++.h>

using namespace std;

const int maxn = 17, N = 16, M = (1 << 17) + 1 ; 
#define lowbit(x) (x & (-x))
#define pii pair<int, int>
int a[maxn][maxn], mp[M], ones[M];
int row[maxn], col[maxn], vis[maxn], box[maxn][maxn];

void init(){
    for(int i = 0; i < maxn; ++i) {
        row[i] = (1 << N) - 1;
        col[i] = (1 << N) - 1;
        vis[i] = (1 << N) - 1;
    }
}

void print(){
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cout << (char)(a[i][j] + 'A');
        }
        cout << "\n";
    }
    cout << "\n";
}

int get(int x, int y) {
    return row[x] & col[y] & vis[box[x][y]];
}


int dfs(int cnt) {
    #ifdef DEBUG
    // print();
    cout << cnt << "\n";
    #endif
    if(!cnt) return 1;
    
    int x, y;
    int mind = maxn;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(a[i][j] == -1){
                int cango = get(i, j);
                int one = ones[cango];
                if(one < mind) {
                    mind = one;
                    x = i;
                    y = j;
                }
            }
        }
    }

    int bid = box[x][y];
    for(int cango = get(x, y); cango; cango -= lowbit(cango)) {
        int i = mp[lowbit(cango)];

        row[x] &= (~(1 << i));
        col[y] &= (~(1 << i));
        vis[bid] &= (~(1 << i));
        a[x][y] = i;
        if(dfs(cnt - 1)) return 1;
        a[x][y] = -1;
        row[x] |= 1 << i;
        col[y] |= 1 << i;
        vis[bid] |= 1 << i;

    }

    return 0;
}

int main(){
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string x;
    for(int i = 0; i <= 12; i += 4) {
        for(int j = 0; j <= 12; j += 4) {
            int id = i + j / 4;
            for(int p = i; p < i + 4 and p < N; ++p){
                for(int q = j; q < j + 4 and q < N; ++q){
                    box[p][q] = id;
                }
            }
        }
    }
    for(int i = 0; i < maxn; ++i) mp[1 << i] = i;
    for(int i = 0; i < M; ++i) {
        int cnt = 0;
        for(int j = i; j; j -= lowbit(j)) {
            cnt++;
        }
        ones[i] = cnt;
    }
    while(cin >> x) {
        int cnt= 0;
        init();
        for(int i = 0; i < N; ++i) {
            if(x[i] == '-') a[0][i] = -1, cnt++;
            else {
                a[0][i] = x[i] - 'A';
                row[0] &= (~(1 << a[0][i]));
                col[i] &= (~(1 << a[0][i]));
                int id = box[0][i];
                vis[id] &= (~(1 << a[0][i]));
            }
        }
        for(int i = 1; i < N; ++i) {
            cin >> x;
            for(int j = 0; j < N; ++j) {
                if(x[j] == '-') a[i][j] = -1, cnt++;
                else {
                    a[i][j] = x[j] - 'A';
                    row[i] &= (~(1 << a[i][j]));
                    col[j] &= (~(1 << a[i][j]));
                    int id = box[i][j];
                    vis[id] &= (~(1 << a[0][i]));
                }
            }
        }
        dfs(cnt);
        print();
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                cout << box[i][j] << " ";
            }
            cout << '\n';
        }
        cout << "\n";
    }
}