#include <bits/stdc++.h>
using namespace std;
#define int long long

priority_queue<int, vector<int>, greater<int>> mnq, mne;
priority_queue<int, vector<int>, less<int>> mxq, mxe;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    int p;
    cin >> p;
    while (p--) {
        int id, m;
        cin >> id >> m;
        mnq = mne;
        mxq = mxe;
        int cnt = 0;
        cout << id << ' ' << (m + 1) / 2 << "\n";
        for (int i = 1; i <= m; ++i) {
            int x;
            cin >> x;
            // push x
            if (mnq.size() == 0 or mnq.top() <= x) {
                // push x to mnq;
                if (mnq.size() > mxq.size()) {
                    mxq.push(mnq.top());
                    mnq.pop();
                }

                mnq.push(x);
            }  
            else if (mxq.size() == 0 or x <= mxq.top()) {
                // push x to mxq;
                if (mxq.size() > mnq.size()) {
                    mnq.push(mxq.top());
                    mxq.pop();
                }

                mxq.push(x);
            }
            else if (mxq.top() <= x and x <= mnq.top()){
                if (mnq.size() <= mxq.size()) {
                    mnq.push(x);
                }
                else {
                    mxq.push(x);
                }
            }
            // pop median
            if (i % 2 == 1) {
                cnt ++;
                if (mnq.size() > mxq.size()) {
                    cout << mnq.top();
                }
                else {
                    cout << mxq.top();
                }
                if (cnt % 10 == 0) {
                    cout << "\n";
                }
                else {
                    cout << " ";
                }
            }
        }
        if (cnt % 10 != 0) {
            cout << "\n";
        }
    }
    
    return 0;
}