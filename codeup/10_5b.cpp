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
const int maxn = 101, INF = 1e9;
int n;
double mp[maxn][maxn];
typedef pair<double, double> pdd;
pdd node[maxn];

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    cout << setiosflags(ios::fixed);
    cout << setprecision(2);
    while(cin >> n, n){
        uu(i, 0, n){
            cin >> node[i].first >> node[i].second;           
        }
        uu(i, 0, n){
            uu(j, 0, n){
                mp[i][j] = sqrt(pow(node[i].first - node[j].first, 2) + pow(node[i].second - node[j].second, 2));
            }
        }

        int bk[maxn];
        double d[maxn];
        memset(bk, 0, sizeof(bk));
        fill(d, d+maxn, INF);
        d[0] = 0; // start from 0;

        double re = 0;
        uu(i, 0, n){
            int from = -1, mind = INF;
            uu(j, 0, n) if(d[j] < mind and bk[j] == 0) mind = d[from = j];

            if(from == -1) break;
            bk[from] = 1;
            re += d[from];
            #ifdef DEBUG
            pf("add %d to set S, re now is %.2lf\n", from, re);
            #endif
            uu(to, 0, n){
                if(mp[from][to] < d[to] and bk[to] == 0){
                    d[to] = mp[from][to];
                }
            }
        }

        cout << re << endl;
    }
    
    return 0;
}