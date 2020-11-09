// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
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

// #define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;
const int maxn = 101;
int n, a[maxn][maxn], dp[maxn], b[maxn];



int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> n){
        memset(dp, 0, sizeof(dp));
        memset(b, 0, sizeof(b));
        uu(i, 1, n+1){
            uu(j, 1, n+1){
                cin >> a[i][j];
            }
        }
        int ans = INT_MIN;
        uu(i, 1, n+1){
            uu(j, i, n+1){
               // [i,  j] rows 
                uu(k, 1, n+1){
                    b[k] = 0;
                    dp[k] = INT_MIN;
                    uu(l, i, j+1){
                        b[k] += a[l][k];
                    }
                } 
                // dp for b


                uu(l, 1, n+1){
                   dp[l] = _max(dp[l-1] + b[l], b[l]);
                   ans = _max(dp[l], ans);
                }
                #ifdef DEBUG
                cout << "b and dp now is" << endl;
                uu(k, 1, n+1){
                    cout << b[k] << " ";
                }
                cout << ";";
                uu(k, 1, n+1){
                    cout << dp[k] << " ";
                }
                cout << endl;
                
                #endif

            }
        }
        cout << ans << endl;


    }
    
    return 0;
}