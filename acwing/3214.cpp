#include <bits/stdc++.h>
using namespace std;
#define int long long

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int is_leap(int x) {
    return x % 400 == 0 or (x % 4 == 0 and x % 100 != 0);
}
struct Calender {
    int y, m, d, w;
    Calender() {
        y = 1850;
        m = 1;
        d = 1;
        w = 2;
    }
    void addone() {
        d++;
        if(m == 2 and d == 30 and is_leap(y)) {
            m++;
            d = 1;
        }

        if(!(m == 2 and is_leap(y)) and d == days[m] + 1) {
            d = 1;
            m++;
        }

        if(m == 13) {
            m = 1;
            y++;
        }

        w++;
        if(w == 8) {
            w = 1;
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
    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;
    Calender calender;
    while(calender.y != y1) {
        calender.addone();
    }
    // cout << calender.y << " " << calender.m << " " << calender.d << " "  << calender.w << "\n";

    for(int yy = y1; yy <= y2; ++yy) {
        int cnt = 0;
        int ok = 0;
        int t = yy + 1;
        while(!ok and calender.y != t) {
            if(calender.m == a and calender.w == c) {
                cnt++;
                if(cnt == b) {
                    cout << setw(4) << setfill('0') <<  calender.y << "/" << 
                    setw(2) << setfill('0') << calender.m << "/" <<
                    setw(2) << setfill('0') << calender.d << "\n";
                    ok = 1;
                }
            }
            calender.addone();

        }
        if(!ok) {
            cout << "none\n";
        }
        while(calender.y != t) {
            calender.addone();
        }
    }

    
}