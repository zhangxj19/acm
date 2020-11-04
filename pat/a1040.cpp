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
const int maxn = 1e3+1;
string s;
int dp[maxn][maxn];

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    getline(cin, s);
    int n = s.size();
    uu(i, 0, n){
        dp[i][i] = 1;
        if(i+1 < n){
            dp[i][i+1] = (s[i] == s[i+1]) ? 1 : 0;
        }
    }

    dd(i, n-1, -1){
        uu(j, i+2, n){
            if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
            else dp[i][j] = 0;
        }
    }
    int maxl = INT_MIN;
    uu(i, 0, n){
        uu(j, i, n){
            if(j - i + 1 > maxl and dp[i][j] == 1){
                maxl = j - i + 1;
            }
        }
    }
    #ifdef DEBUG
    uu(i ,0, n){
        uu(j ,0 , n){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    #endif

    cout << maxl << endl;

    return 0;
}