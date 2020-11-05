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
const int maxn = 1e4+1, maxm = 1e2+1;
int n, m, a[maxn], bk[maxn];

vector<int> re, tmp;
int isfind;

void dfs(int idx, int sum){
    bk[idx] = 1;
    tmp.push_back(a[idx]);

    if(!isfind){
        if(sum == m){
            re = tmp;
            isfind =1;
            tmp.pop_back();
            bk[idx] = 0;
            return ;
        }
        else{
            for(int i = idx+1; i < n; ++i){
                if(bk[i] == 0) dfs(i, sum + a[i]);
            }
        }
    }


    tmp.pop_back();
    bk[idx] = 0;
    return ;
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    cin >> n >> m;
    uu(i, 0, n){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i = 0; i < n; ++i){
        if(bk[i] == 0) dfs(i, a[i]);
    }
    if(re.size()){
        uu(i, 0, re.size()){
            if(i == 0) cout << re[i];
            else cout << " " << re[i];
        }
    }
    else{
        cout << "No Solution";
    }

    cout << endl;    
    return 0;
}