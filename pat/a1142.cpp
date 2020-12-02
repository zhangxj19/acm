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

const int maxn = 2*1e2+1;

int Nv, Ne, M, K, mp[maxn][maxn];

int isclique(vector<int>& v){
    int cnt = 0;
    // is clique
    uu(i, 0, v.size()){
        uu(j, i+1, v.size()){
            int from = v[i], to = v[j];
            if(mp[from][to] == 1) cnt++;
        }
    }
    return cnt == (v.size()-1)*v.size()/2;
}

struct Node{
    vector<int> n;
}node[maxn];

void solve(){
    cin >> Nv >> Ne;
    uu(i, 0, Ne){
        int x, y;
        cin >> x>> y;
        mp[x][y] = 1;
        mp[y][x] = 1;
        node[x].n.push_back(y);
        node[y].n.push_back(x);
    }

    cin >> M;
    while(M--){
        cin >> K;
        set<int> S;
        uu(i, 0, K){
            int x;
            cin >> x;
            S.insert(x);
        }
        
        int ismax = true, is_clique = true;
        
        vector<int> tmp(S.begin(), S.end());
        if(!isclique(tmp)){
            is_clique = false;
        }

        if(is_clique){
            vector<int> vertics(S.begin(), S.end()); 
            each(v, S){                
                each(nei, node[v].n){
                    if(S.find(nei) == S.end()){
                        vertics.push_back(nei);
                        if(isclique(vertics)){
                            ismax = false;
                        }
                        vertics.pop_back();
                        if(!ismax) break;
                    }
                }
                if(!ismax) break;
            }
        }
        if(!is_clique){
            cout << "Not a Clique" << endl;
        }
        else if(isclique and !ismax){
            cout << "Not Maximal" << endl;
        }
        else{
            cout << "Yes" << endl;
        }

     
    }
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