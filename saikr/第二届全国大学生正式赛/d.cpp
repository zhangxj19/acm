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

using namespace std;

const int maxn = 101;
int n;
string s;

double solve(){
    double re = 0, v = 1;
    double t = 0;
    for(int i = 0, n = s.size(); i < n;){
        if(s[i] == '.'){
            if(t > 0){
                if(t < 0.5){
                    re += (1-2*t) / 1 + t;
                    t = 0;
                }
                else{
                    v = 2;
                    re += 1/v;
                    t -= 1/v;
                }
            }
            else{
                v = 1;
                re += 1/v;
            }
            
            i++;
        }
        else if(s[i] == 'w'){
            if(t > 0){
                if(t < 1){
                    re += (1-t) / 0.5 + t;
                    t = 0;
                }
                else{
                    v = 1;
                    re += 1/v;
                    t -= 1/v;
                }
            }
            else{
                v = 0.5;
                re += 1/v;                
            }
            i++;
        }
        else if(s[i] == '>'){
            s.replace(s.begin() + i, s.begin() + i + 1, ".");
            t = 5;
        }
        else if(s[i] == 's'){
            s.replace(s.begin() + i, s.begin() + i + 1, ".");
            re += 1;
            t = _max(t-1, 0);
        }
        else if(s[i] == 'm'){
            s.replace(s.begin() + i, s.begin() + i + 1, ".");
            re += 2;
            t = _max(t-2, 0);            
        }
    }
    return re;
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
    cout << setiosflags(ios::fixed);
    cout << setprecision(1);
    cin >> n;
    uu(i, 0, 4){
        cin >> s;
        if(i == 0) cout << solve();
        else cout << " " << solve();
    }
    cout << endl;

    
    return 0;
}