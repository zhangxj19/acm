#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        for(int i = 2; i <= x / i; ++i){
            if(x % i == 0){
                int c = 0;
                while(x % i == 0) c++, x /= i;
                cout << i << " " << c << "\n";
            }
        }
        if(x > 1) cout << x << " " << 1 << "\n";
        cout << "\n";
    }
    
}