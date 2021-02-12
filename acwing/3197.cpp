#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
unordered_set<int> s;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int re = 0;
    for(int i =0 ; i < n; ++i) {
        int x;
        cin >> x;
        if(s.count(-x)) re++;
        s.insert(x);
    }
    
    cout <<re <<"\n";
    
}