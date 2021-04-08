#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N =35;
int n, m, a[N][N], b[N][N];


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            // row
            int k = j + 1; 
            while(k < m and a[i][k] == a[i][k-1]) ++k;
            if(k-j >= 3) {
                for(int kk = j; kk < k; ++kk) {
                    b[i][kk] = 1;
                }
            }

            k = j - 1; 
            while(k > -1 and a[i][k] == a[i][k+1]) --k;
            if(j - k >= 3) {
                for(int kk = j; kk > k; --kk) {
                    b[i][kk] = 1;
                }
            }

            // col

            k = i + 1;
            while(i < n and a[k][j] == a[k-1][j]) ++k;
            if(k - i >= 3) {
                for(int kk = i; kk < k; ++kk) {
                    b[kk][j] = 1;
                }
            }


            k = i - 1;
            while(i > -1 and a[k][j] == a[k+1][j]) --k;
            if(i - k >= 3) {
                for(int kk = i; kk > k; --kk) {
                    b[kk][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(b[i][j]) {
                cout << "0 ";
            }
            else {
                cout << a[i][j] << " ";
            }
        }
        cout << "\n";
    }


    
}