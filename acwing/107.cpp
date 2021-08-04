#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, a[N];

int mergeSort(int a[], int l, int r) {
    if (l >= r) {
        return 0;
    }

    int mid = (l + r) >> 1;
    int res = 0;
    res += mergeSort(a, l, mid);
    res += mergeSort(a, mid + 1, r);

    // merge
    // l ... mid, mid + 1, ..., r
    int i = l, j = mid + 1, k = 0;
    vector<int> t(r - l + 1, 0);
    while (i <= mid and j <= r) {
        if (a[i] <= a[j]) {
            t[k++] = a[i++];
        }
        else {
            res += (mid - i + 1);
            t[k++] = a[j++];
        }
    }

    while (i <= mid) {
        t[k ++] = a[i ++];
    }
    while (j <= r) {
        t[k ++] = a[j ++];
    }

    for (int i = l; i <= r; ++i) {
        a[i] = t[i - l];
    }

    return res;
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
    while (cin >> n, n != 0) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int t = mergeSort(a, 1, n);

        cout << t << "\n";
    }

    
    return 0;
}