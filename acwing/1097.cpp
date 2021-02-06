#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[1001][1001];

int dir[8][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1},
};
int re;
void dfs(int x, int y){
    // re++;
    a[x][y] = '.';
    for(int i = 0; i < 8; ++i){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(0 <= nx and nx < n and 0 <= ny and ny < m and a[nx][ny] == 'W'){
            dfs(nx, ny);
        }
    }
}

int main(){
    freopen("in", "r", stdin);
    cin >>n >> m;
    getchar();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }   
        getchar();
    }
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i][j] == 'W'){
                dfs(i, j);
                re++;
            }
        }
    }
    cout << re << '\n';
    
}