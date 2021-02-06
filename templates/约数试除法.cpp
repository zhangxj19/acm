// 约数i和x/i成对出现,注意i!=x/i避免重复加入
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n ;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        vector<int> re;
        for(int i = 1; i <= x / i; ++i) {
            if(x % i == 0) {
                re.push_back(i);
                if(i != x / i)
                re.push_back(x / i);
            } 
        }
        sort(re.begin(), re.end());
        for(int i = 0; i < re.size(); ++i) cout << re[i] << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();    
}