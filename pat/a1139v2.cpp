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



using namespace std;
const int maxn = 1e5+1;

int N, M, K;



struct Node{
    int isg; // is girl 
    set<int> n;
}node[maxn];


#define pii pair<int, int>
#define piv pair<int, vector<int>>


void print(pii &p){
    cout << setw(4) << setfill('0') << p.first << " " << setw(4) << setfill('0') << p.second << endl;
}


vector<pii> re;


bool cmp(pii & v1, pii & v2){
    if(v1.first != v2.first) return v1.first < v2.first;
    else return v1.second < v2.second;
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
    // cout << setw(4) << setfill('0');  // add this every time when cout int with width and left padding '0'
    cin >> N >> M;
    uu(i, 0, M){
        string s1 , s2;
        cin >>s1 >> s2;
        int x, y;
        sscanf(s1.c_str(), "%d", &x);
        sscanf(s2.c_str(), "%d", &y);
        
        if(x < 0) x = -x;
        if(y < 0) y = -y;
        if(s1[0] == '-') node[x].isg = 1;
        else node[x].isg = 0;
        if(s2[0] == '-') node[y].isg = 1;
        else node[y].isg = 0;
        node[x].n.insert(y);
        node[y].n.insert(x);
    }

    cin >> K;
    while(K--){
        int x , y;
        cin >> x >> y;
        re.clear();

        if(x < 0) x = -x;
        if(y < 0) y = -y;

        if(node[x].n.size() == 0 or node[y].n.size() == 0){
            cout << 0 << endl;
            continue;
        }

        vector<int> af, bf;
        each(fri, node[x].n){
            if(node[fri].isg == node[x].isg and fri != y) af.push_back(fri);
        }

        each(fri, node[y].n){
            if(node[fri].isg == node[y].isg and fri != x) bf.push_back(fri);
        }

        each(a, af){
            each(b, bf){
                if(node[x].isg == node[y].isg){
                    if(node[a].isg == node[b].isg and node[a].n.find(b) != node[a].n.end()){
                        re.push_back({a, b});
                    }
                }
                else{
                    if(node[a].isg != node[b].isg and node[a].n.find(b) != node[a].n.end()){
                        re.push_back({a, b});
                    }                    
                }
            }
        }


        cout << re.size() << endl;
        sort(re.begin(), re.end(), cmp);
        each(p, re){
            print(p);
        }
    }
    
    return 0;
}