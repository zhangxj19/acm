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
const int maxn = 1e4+1, maxv = 1e2+1;
int n, V, c[maxn], flag[maxn]={0}, choice[maxn][maxv], dp[maxv];

/*
     v
    __________________\
 n  |                 /
    |
    |
    |
    \/
*/

bool cmp(int i1, int i2){
    return i1 > i2;
}


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    cin >> n >> V;
    uu(i, 1, n+1){
        cin >> c[i];
    }

    sort(c+1, c+n+1, cmp);

    uu(i, 1, n+1){
        dd(v, V, c[i]-1){
            if(dp[v-c[i]] + c[i] >= dp[v]){
                choice[i][v] = 1;
                dp[v] = dp[v-c[i]] + c[i]; 
            }
            else{
                choice[i][v] = 0;
            }
        }
    }

    #ifdef DEBUG
    uu(i, 0, V+1){
        cout << dp[i] << " ";
    }
    cout << endl;

    uu(i, 0, n+1){
        uu(j, 0, V+1){
            cout << choice[i][j] << " ";
        }
        cout << endl;
    }
    #endif 

    if(dp[V] != V){
        cout << "No Solution" << endl;
        return 0;
    }
    
    int k = n, num = 0, v=V;
    while(k >= 0){
        if(choice[k][v] == 1){
            flag[k] = true;
            v -= c[k];
            num++;
        }
        else{
            flag[k] = false;    
        }
        k--;
    }

    for(int i =n; i >= 1; --i){
        if(flag[i] == 1){
            if(num == 1) cout << c[i];
            else cout << c[i] << " ";
            num--;
        } 
    }




    return 0;
}