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
#define vi vector<int>
#define pii pari<int, int>

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(vi &v){
    uu(i, 0, v.size()){
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

struct Node{
    int x;
    char d;
    int od;
};

void solve(){
    int N;
    cin >> N;
    int L, T, n, kcase = 1;
    while(N--){
        cin >> L >> T >> n;
        cout << "Case #" << kcase++ << ":" << endl;
        vector<Node> node;
        uu(i, 0, n){
            Node x;
            cin >> x.x >> x.d;
            x.od = i;
            node.push_back(x);
        }
        sort(node.begin(), node.end(), [](Node& n1, Node & n2){
            return n1.x < n2.x;
        });
        map<int, int> mp; // order to position
        uu(i, 0, node.size()){
            mp[node[i].od] = i;
        }

        int lf = 0, rf = 0; // left fall and right fall

        vector<Node> tar;
        each(ant, node){
            Node x;
            if(ant.d == 'L'){
                x.x = ant.x - T;
            }
            else{
                x.x = ant.x + T;
            }
            if(x.x < 0 or x.x > L){
                x.d = 'F';
            }
            else{
                x.d = ant.d;
            }
            tar.push_back(x);
        }

        sort(tar.begin(), tar.end(), [](Node & n1 , Node & n2){
            return n1.x < n2.x;
        });
        int size = node.size();
        uu(i, 0, size){
            int po = mp[i], x = tar[po].x;
            if(tar[po].d == 'F'){
                cout << "Fell off" << endl;    
            }
            else{
                cout << x << " ";
                if((po > 0 and tar[po-1].x == x) or (po < size-1 and tar[po+1].x == x)){
                    cout << "Turning" << endl;
                }
                else{
                    cout << tar[po].d << endl;
                }
            }
        }
        cout << endl;
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