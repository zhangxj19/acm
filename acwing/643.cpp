#include <bits/stdc++.h>

using namespace std;
int t;
int r, c;

int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1},
};

void dfs(int x, int y, vector<vector<int>>& a, vector<vector<int>>& vis){
    vis[x][y] = 1;
    for(int i = 0; i < 4; ++i){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx < 0 or nx >= r or ny < 0 or ny >= c or vis[nx][ny] or a[nx][ny] == 0) continue;
        dfs(nx, ny, a, vis);
    }    
}

int floodfill(vector<vector<int>>& a){
    vector<vector<int>> vis(r, vector<int>(c, 0));
    int re = 0; 
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(!vis[i][j] and a[i][j] == 1){
                re++;
                dfs(i, j, a, vis); 
            }
        }
    }
    return re;
}

int main(){
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    cin >> t;
    int kcase = 0;
    while(t--){
        cout  << "Case #" << ++kcase << ":\n";
        cin >> r >> c;
        vector<vector<int>> a(r, vector<int>(c, 0));
        for(int i = 0 ;i < r; ++i){
            string x;
            cin >> x;
            for(int j = 0; j < c; ++j){
                a[i][j] = x[j] - '0';
            }
        }
        int n;
        cin >> n;
        // getchar();
        while(n--){
            char ch;
            cin >> ch;
            if(ch == 'M'){
                int x, y, z;
                cin >> x >> y >> z;
                #ifdef DEBUG2
                cout << x << " " << y << " " << z << endl;
                #endif
                // getchar();
                a[x][y] = z;
            }
            else if(ch == 'Q'){
                cout << floodfill(a) << "\n";
            }
        }
    }
    
    
}

