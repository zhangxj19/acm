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
    vector<int> n;
}node[maxn];

void print(std::vector<int> &v){
    uu(i, 1, v.size()-1){
        if(i == 1) std::cout << setw(4) << setfill('0') << v[i];
        else std::cout << " " << setw(4) << setfill('0')<< v[i];
    }
    std::cout << std::endl;
}


#define pii pair<int, int>
#define piv pair<int, vector<int>>

vector<vector<int>> re;
vector<int> tmp;
int mode, tofind;

void dfs(int x, int dep, int bk[], int s, int e){
    bk[x] = 1;
    tmp.push_back(x);

    if(dep == 3 and x == e){
        re.push_back(tmp);

        bk[x] = 0;
        tmp.pop_back();
        return ;
    }


    // each(to, node[x].n){
    //     if(bk[to] == 0) dfs(to, dep+1, bk, s, e);
    // }

    if(mode == 1){  // find same gender always
        each(to, node[x].n){
            if(bk[to] == 0 and node[to].isg == tofind){
                dfs(to, dep+1, bk, s, e);
            }
        }   
    }
    else{
        each(to, node[x].n){
            if(bk[to] == 0){
                if(dep == 0 and node[to].isg == tofind) dfs(to, dep+1, bk, s, e);
                if(dep == 1 and node[to].isg != tofind) dfs(to, dep+1, bk, s, e);
                if(dep == 2 and to == e) dfs(to, dep+1, bk, s, e);
            }
        }          
    }


    bk[x] = 0;
    tmp.pop_back();
    return ;
}


bool cmp(vector<int> & v1, vector<int> & v2){
    if(v1[1] != v2[1]) return v1[1] < v2[1];
    else return v1[2] < v2[2];
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
        node[x].n.push_back(y);
        node[y].n.push_back(x);
    }

    cin >> K;
    while(K--){
        int x , y;
        cin >> x >> y;
        re.clear();
        tmp.clear();
        int bk[maxn] = {0}; 
        if(x < 0) x = -x;
        if(y < 0) y = -y;
        if(node[x].n.size() == 0 or node[y].n.size() == 0){
            cout << 0 << endl;
            continue;
        }

        if(node[x].isg == node[y].isg) mode = 1;
        else mode = 0;
        tofind = node[x].isg;

        dfs(x, 0, bk, x, y);
        cout << re.size() << endl;
        sort(re.begin(), re.end(), cmp);
        each(v, re){
            print(v);
        }
    }
    
    return 0;
}