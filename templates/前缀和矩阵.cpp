#include <bits/stdc++.h>


using namespace std;

int main(){
    int n, m, q;
    cin >>n >> m >> q;
    
    vector<vector<int>> a(n, vector<int>(m, 0)), sum(n+1, vector<int>(m+1, 0));

    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < m;++j){
            cin >> a[i][j];
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + a[i][j];
        }
    }
    
    for(int i = 0; i < q; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        cout << sum[x2+1][y2+1] - sum[x2+1][y1] - sum[x1][y2+1] + sum[x1][y1] << "\n";
    }
    
    
}