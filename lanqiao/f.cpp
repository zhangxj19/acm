#include <bits/stdc++.h>
using namespace std;
#define int long long
int second = 1000;
int minute = second * 60;
int hour = minute * 60;
int day = 24 * hour; 

int ms;

struct Day {
    int hh, mm, ss;
    void add() {
        ss += 1;
        if (ss == 60) {
            ss = 0;
            mm ++;
        }

        if (mm == 60) {
            mm = 0;
            hh += 1;
        }
    }
}d;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> ms;
    ms %= day;
    int s = ms / second;

    while (s--) {
        d.add();
    }
    cout << setw(2) << setfill('0') << d.hh << ":"
         << setw(2) << setfill('0') << d.mm << ":"
         << setw(2) << setfill('0') << d.ss << "\n";

    // int hh = ms / hour;
    // int mm = ms / minute;
    // int ss = ms /  




    return 0; 
}