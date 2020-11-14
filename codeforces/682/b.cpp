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

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}
#define lowbit(x) (x&(-x));

// #define DEBUG
// #define LOCAL

using namespace std;
const int maxn = 1001;
int t, n, a[maxn], b[maxn];


int issame(vector<int> &v1, vector<int> &v2){
    if(v1.size() != v2.size()) return 0;
    else{
        uu(i, 0, v1.size()){
            if(v1[i] != v2[i]) return 0;
        }
        return 1;
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
    cin >> t;
    while(t--){
        cin >> n;
        uu(i, 0, n){
            cin >> b[i];
        }

        #ifdef DEBUG2
        vector<int> v(b+1, b+n);
        sort(v.begin(), v.end());
        uu(i, 0, v.size()){
            cout << v[i] << " ";
        }
        cout << endl;
        #endif
        int isfind = false;
        uu(l1, 0, n){
            uu(r1, l1, n){
                uu(l2, r1+1, n){
                    uu(r2, l2, n){
                        // b[l1:r1], b[l2:r2]
                        vector<int> v1(b+l1, b+r1+1), v2(b+l2, b+r2+1);
                        sort(v1.begin(), v1.end());
                        sort(v2.begin(), v2.end());
                        string s1, s2;
                        for(int r = 0, size = v1.size(); r < size; ){
                            if(r < size - 1 and v1[r] == v1[r+1]){
                                s1 += to_string(v1[r]+1);
                                r += 2;
                            }
                            else{
                                s1 += to_string(v1[r]);
                                r++;
                            }                          
                        }
                        for(int r = 0, size = v2.size(); r < size; ){
                            if(r < size - 1 and v2[r] == v2[r+1]){
                                s2 += to_string(v2[r]+1);
                                r += 2;
                            }
                            else{
                                s2 += to_string(v2[r]);
                                r++;
                            }                          
                        }
                        if(s1 == s2) isfind = true;
                        #ifdef DEBUG
                        if(isfind){
                            pf("s1=%s, s2=%s\n", s1.c_str(), s2.c_str());
                        }
                        #endif
                        if(isfind) break;
                    }
                    if(isfind) break;
                }
                if(isfind) break;
            }
            if(isfind) break;
        }
        if(isfind) cout << "YES" << endl;
        else cout << "NO" <<endl;

    }
    
    return 0;
}