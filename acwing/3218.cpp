#include <bits/stdc++.h>
using namespace std;
#define int long long

int is_leap(int x) {
    return x % 400 == 0 or (x % 4 == 0 and x % 100 != 0);
}
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Calender {
    int y, m, d;
    void add1() {
        d++;

        if(m == 2 and d == 30 and is_leap(y)) {
            d = 1;
            m++;
        }

        if(!(m == 2 and is_leap(y)) and d == days[m] + 1) {
            d = 1;
            m++;
        }

        if(m == 13) {
            m = 1;
            y++;
        }
    }
};

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int y, d;
    cin >> y >> d; 

    Calender c;
    c.y = y;
    c.m = 1;
    c.d = 1;

    while(--d) {
        c.add1();
    }

    cout << c.m << "\n" << c.d << "\n";




}