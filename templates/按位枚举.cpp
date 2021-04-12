#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; // number of elements
    cin >> n;
    for(int s = 0; s < (1 << n); ++s){
        for(int i = 0; i < n; ++i){ // 检查n位是否为1,若是输出i
            if(s & (1 << i)) cout << i << " ";
        }
        cout << "\n";
    }    
}

signed main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    solve();
    
    return 0;
}