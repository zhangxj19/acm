#include <bits/stdc++.h>

using namespace std;
const int maxn= 1e5+1;
int n, m;
unsigned long long s[maxn], p[maxn];
const int P = 131;
string x;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> x;
    p[0] = 1;
    for(int i = 0; i < n; ++i){
        s[i+1] = s[i]*P + x[i];
        p[i+1] = p[i] * P;
    }
    // for(int i = 0; i <= n; ++i) cout << s[i] << " ";
    // cout << "\n";
    // for(int i = 0; i <= n; ++i) cout << p[i] << " ";
    // cout << "\n";
    while(m--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--; r1--; l2--; r2--;
        if((s[r1+1] - s[l1] * p[r1-l1+1]) == (s[r2+1] - s[l2] * p[r2-l2+1])) cout << "Yes";
        else cout << "No";
        cout << "\n";
    }

    
}