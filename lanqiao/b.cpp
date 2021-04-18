// . . .
// . . .

// . . .
// . . .
// . . .

// . . . . 
// . . . . 
// . . . . 
// . . . . 

// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .
// . . . . . . . . . . . . . . . . . . . . .

// y = kx + b
// x1 y1, x2, y2
// if x2 == x1 then
//  line : x = x2 / x = x1
// k = (y2 - y1) / (x2 - x1)
// b = y1 - kx1

#include <bits/stdc++.h>
using namespace std;
#define int long long

int X, Y;

string get_key(int x1, int y1, int x2, int y2, int inf) {
    double k = 0;
    if (x1 == x2) {
        return "x=" + to_string(x1);
    }
    else {
        k = (double)(y2 - y1) / (double)(x2 - x1);
    }
    double b = y1 - k * x1;
    
    int intk = k * inf;
    int intb = b * inf;
    return to_string(intk) + "_" + to_string(intb);
}

int get_size(int inf) {
    unordered_set<string> st;
    for (int x1 = 0; x1 < X; ++x1) {
        for (int y1 = 0; y1 < Y; ++y1) {
        
            for (int x2 = 0; x2 < X; ++x2) {
                for (int y2 = 0; y2 < Y; ++y2) {
                    if (x1 == x2 and y1 == y2) {
                        continue;
                    }

                    string key = get_key(x1, y1, x2, y2, inf);

                    #ifdef DEBUGi
                    cout << "(" << x1 << "," << y1 << "), " << "(" << x2 << "," << y2 << ")" << " " << key << " " << "\n";
                    #endif
                    st.insert(key);
                }
            }
        }
    }
    return st.size();
 
}


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> X >> Y;
    vector<int> inf = {
        (int)1e5,
        (int)1e6,
        (int)1e7,
        (int)1e8,
        (int)1e9,
        (int)1e10,
        (int)1e11,
        (int)1e12,
        (int)1e13,
        (int)1e14,
        (int)1e15,
        (int)1e16,
        (int)1e17,
        (int)1e18,
    };
    for (auto &x : inf) {
        int sz = get_size(x);
        cout << sz << " " << x << "\n";
    }
   
}