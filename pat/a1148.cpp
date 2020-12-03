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
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(std::vector<int> &v){
    uu(i, 0, v.size()){
        if(i == 0) std::cout << v[i];
        else std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

using namespace std;
int N;
vector<int> a, id;
#define pii pair<int, int>
vector<pii> re;
void solve(){
    cin >> N;
    a.resize(N+1, 0);
     // 1 for human and 2 for wolf
    uu(i, 1, N+1) cin >> a[i];
    uu(i, 1, N+1){
        uu(j, 1, N+1){
            // i and j is liar
            
            // i is wolf and j is human
            uu(k, 1, N+1){ // k is wolf
                if(k == i or k == j) continue;
                id.resize(N+1, 0);
                id[i] = 2;
                id[k] = 2;
                int isfind = true;
                uu(l, 1, N+1){
                    int re = a[l];
                    // if(l == i or l == j) re *= -1; // re should be the truth
                    int idx = abs(re);
                    if(id[idx] == 0) id[idx] = (re > 0) ? 1 : 2;
                    else{
                        if(!((id[idx] == 1 and re > 0) or (id[idx] == 2 and re < 0))) isfind = false;
                    }
                }
                if(isfind) re.push_back({i, k});
            }


            // i is human and j is wolf
            


        }
    }
    #ifdef DEBUG
    each(e, re){
        cout << e.first << " " << e.second << endl;
    }
    #endif
    if(re.size() > 1 or re.size() == 0) cout << "No Solution" << endl;
    else cout << re[0].first << " " << re[0].second << endl;

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