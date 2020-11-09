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
const int maxn = 31, maxv = 200100;
int V, N, dp[maxv];
double dV;
vector<ll> ca, wa;

int ans, bk[maxn];

void dfs(int idx, int sum){
    bk[idx] = 1;
    if(sum >= V) return;

    ans= _max(ans, sum);

    for(int i = idx +1; i < N; ++i){
        if(bk[idx] == 0) dfs(i, sum + ca[i]);
    }


    bk[idx] = 0;
    return ;

}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    cout << setiosflags(ios::fixed);
    cout << setprecision(2);
    while(cin >> dV >> N, N){
        ca.clear();
        wa.clear();
        memset(dp, 0, sizeof(dp));
        V =  (ll)(dV*100);

        uu(i, 0, N){
            int m = 0;
            cin >> m;
            string s;
            double v = 0;
            int islegal = true;
            ll A=0, B=0, C=0;
            uu(j, 0, m){
                cin >> s;
                char type;
                sscanf(s.c_str(), "%c:%lf", &type, &v);
                ll lv = (ll)(v*100);
                if(type == 'A'){
                    A += lv;
                }
                else if(type == 'B'){
                    B += lv;
                }
                else if(type == 'C'){
                    C += lv;
                }
                else{
                    islegal = false;
                }
            }
            if(islegal and A <= 60000 and B <= 60000 and C <= 60000 and A+B+C <= 100000){
                ca.push_back(A+B+C);
                wa.push_back(A+B+C);
            }
        }
        N = ca.size();
        
        // ll ans = 0;
        // uu(i, 0, N){
        //     dd(v, V, wa[i]-1){
        //         dp[v] = _max(dp[v], dp[v - wa[i]] + ca[i]);
        //         ans = _max(ans, dp[v]);
        //     }
        // }
        // cout << (double)ans/100 << endl;
        // cout << (double)dp[V]/100 << endl;

        dfs(0, ca[0]);
        cout << ans/100.0 << endl;
    }
    
    return 0;
}