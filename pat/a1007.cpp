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

#define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;

const int maxk = 1e4+1;
int k, a[maxk];

struct Node
{
    int beg, v;
}dp[maxk];


int allneg(){
    uu(i, 0, k){
        if(a[i] >= 0) return false;
    }
    return true;
}

int solve(int idx){
    if(idx == 0){
        dp[idx].beg = 0;
        dp[idx].v = a[0];
        return dp[idx].v;
    }

    if(dp[idx].v != 0) return dp[idx].v;
    else{
        if(solve(idx-1) + a[idx] > a[idx]){
            dp[idx].beg = dp[idx-1].beg;
            dp[idx].v = dp[idx-1].v + a[idx];
        }
        else{
            dp[idx].beg = idx;
            dp[idx].v = a[idx];
        }
        return dp[idx].v;
    }

}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    cin >> k;
    memset(dp, 0, sizeof(dp));

    uu(i, 0, k) cin >> a[i];
    if(allneg()){
        cout << 0 << " " << a[0] << " " << a[k-1] << endl;
        return 0;
    }
    solve(k-1);

    int beg = 0, end = 0, maxsum = INT_MIN;
    uu(i, 0, k){
        if(dp[i].v > maxsum){
            beg = dp[i].beg;
            end = i;
            maxsum = dp[i].v;
        }
    }
    cout << maxsum << " " << a[beg] << " " << a[end] << endl;



    
    return 0;
}