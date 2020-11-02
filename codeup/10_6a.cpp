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
const int maxn =51;
int n, mp[maxn][maxn], ind[maxn];


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> n){
        stack<int> S;
        vector<int> re;
        memset(ind, 0, sizeof(ind));
        uu(i, 0, n){
            uu(j, 0, n){
                cin >> mp[i][j];
                if(mp[i][j] == 1){
                    ind[j]++;
                }
            }
        }
        uu(i, 0, n) if(!ind[i]){
            S.push(i);
        }

        
        while(!S.empty()){
            int from = S.top(); S.pop();
            re.push_back(from);
            uu(to, 0, n){
                if(mp[from][to]){
                    ind[to]--;
                    if(!ind[to]){
                        S.push(to);
                    }
                }

            } 
        }
        if(re.size() != n) cout << "ERROR" << endl;
        else{
            uu(i, 0, re.size()){
                cout << re[i] << " ";
            }
            cout << endl;
        }

    }


    
    return 0;
}