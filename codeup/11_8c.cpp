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
const int maxn = 1e2+2;

int n, a[maxn], ils[maxn], dls[maxn];
int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> n, n ){
        fill(ils, ils+maxn, 1);
        ils[0] = 0;
        fill(dls, dls+maxn, 1);
        dls[n+1] = 0;
        uu(i, 1, n+1) cin >> a[i];
        
        //ILS
        uu(i, 1, n+1){
            uu(j, 1, i){
                if(a[j] < a[i])
                    ils[i] = _max(ils[i], ils[j]+1);
            }
        }

        #ifdef DEBUG
        uu(i, 1, n+1){
            cout << ils[i] << " ";
        }
        cout << endl;
        #endif


        //ILS from right to left (can be considered as "dls")
        dd(i, n, 0){
            dd(j, n, i){
                if(a[j] < a[i])
                    dls[i] = _max(dls[i], dls[j]+1);
            }
        }
        #ifdef DEBUG
        uu(i, 1, n+1){
            cout << dls[i] << " ";
        }
        cout << endl;
        #endif

        int maxsum = 0;
        uu(i, 1, n+1){
            maxsum = _max(maxsum, ils[i] + dls[i]);
        }
        cout << n - (maxsum - 1) << endl;
    }
    return 0;
}