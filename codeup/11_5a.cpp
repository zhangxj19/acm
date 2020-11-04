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
const int maxn = 5*1e3+1;

string a, b;
int p[maxn], dp[maxn][maxn];

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(getline(cin, a)){
        b.clear();
        memset(p, 0, sizeof(p));
        memset(dp, 0, sizeof(dp));
        int l = 0;
        uu(i, 0, a.size()){
            if(isalpha(a[i])){
                b += toupper(a[i]);
                p[l++] = i;
            }
            else if(isdigit(a[i])){
                b += a[i];
                p[l++] = i;
            }
        }
        // cout << b << endl;
        uu(i, 0, b.size()){
            dp[i][i] = 1;
            if(i < b.size()-1){
                dp[i][i+1] = (b[i] == b[i+1]) ? 1 : 0;
            }
        }
        dd(i, l-1, -1){
            uu(j, i+2, l){
                if(b[i] == b[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = 0;
            }
        }

        int maxl = INT_MIN, beg, end;
        uu(i, 0, l){
            uu(j, i+1, l){
                if(dp[i][j] and j - i + 1 > maxl){
                    maxl = j - i + 1;
                    beg = i;
                    end = j;
                }
            }
        }   
        #ifdef DEBUG
        pf("pl: ");
        uu(i, 0, l){
            cout << p[i] << " ";
        }
        cout <<endl;
        uu(i, 0, l){
            uu(j, 0, l){
                pf("%d ", dp[i][j]);
            }
            pf("\n");
        }
        pf("maxl = %d, beg = %d, end = %d\n", maxl, beg, end);
        #endif
        uu(i, p[beg], p[end]+1){
            cout << a[i];
        }
        cout << endl;
    }

    
    return 0;
}