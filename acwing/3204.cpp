#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char s[101];
    cin >> s;
    int slen = 0;
    for(int i = 0; s[i] != '\0'; ++i) {
        slen++;
    }
    int sen;
    cin >> sen;
    if(!sen) {
        for(int i = 0; s[i] != '\0'; ++i) {
            if(s[i] >= 'A' and s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }
        }
    }

    int n;
    cin >> n;
    while(n--) {
        char x[101], ori[101];
        cin >> x;
        memcpy(ori, x, sizeof(x));

        // cout << x << " " << ori << "\n";
        int len = 0;
        if(!sen) {
            for(int i = 0; x[i] != '\0'; ++i) {
                if(x[i] >= 'A' and x[i] <= 'Z') {
                    x[i] = x[i] - 'A' + 'a';
                }
                len++;
            }
        }

        int ok = 0;
        for(int i = 0; x[i] != '\0'; ++i) {
            int j = i;
            while(x[j] != '\0' and x[j] == s[j - i]) {
                j ++;
            }
            if(j - i == slen) {
                ok = 1;
            }
        }
        
        if(ok) {
            cout << ori << "\n";
        }


        


    }
    
}