// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

#define rep(i, n) for (int i = 0, size = (n); i < size; ++i)
#define repu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define repd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define each(it, a) for(auto & (it) : (a))
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define lowbit(x) (x&(-x))
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(vi &v){
    rep(i, v.size()){
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

int n, m;


set<pii> H, V;

int checkline(int x, int y, int ish, int size){
    if(ish){
        // H
        repu(i, y, y + size){
            if(H.find(make_pair(x, i)) == H.end()) return false;
        }
        return true;
    }
    else{
        // V
        repu(i, x, x + size){
            if(V.find(make_pair(i, y)) == V.end()) return false;
        }
        return true;
    }
}


void solve(){
    int kcase = 1;
    while(cin >> n){
        if(kcase > 1){
            cout << endl;
            cout << "**********************************" << endl;
            cout << endl;
        }
        cout << "Problem #" << kcase++ << endl;
        cout << endl;
        H.clear(); V.clear();
        cin >> m;
        rep(i, m){
            char c;
            cin >> c;
            pii p;
            cin >> p.first >> p.second;
            if(c == 'H') H.insert(p);
            else if(c == 'V') V.insert(make_pair(p.second, p.first));
        }

        // scan
        int ok = false;
        repu(size, 1, n+1){
            int cnt = 0;
            repu(r, 1, n+1 - size){
                repu(c, 1, n+1 - size){
                    // check square size of "size"
                    int r1 = r, c1 = c;
                    int r2 = r, c2 = c + size;
                    int r3 = r + size, c3 = c;
                    #ifdef DEBUG2
                    cout << r << " " << c << endl;
                    pf("(%d, %d)-|, (%d, %d)|, (%d, %d)-, size=%d \n", r1, c1, r2,c2,r3,c3,size);

                    #endif
                    if(checkline(r1, c1, true, size) and checkline(r1,c1, false, size) and checkline(r2, c2, false, size) and checkline(r3,c3,true,size)){
                        cnt++;
                        #ifdef DEBUG2
                        cout << "yes" << endl;
                        #endif
                    }
                }
            }
            if(cnt){
                ok = true;
                cout << cnt << " square (s) of size " << size << endl;
            }
        }
        if(!ok) cout << "No completed squares can be found." << endl;
    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("o", "w", stdout);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}