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

void print(std::vector<int> &v){
    uu(i, 0, v.size()){
        if(i == 0) std::cout << setw(4) << setfill('0') << v[i];
        else std::cout << "->" << setw(4) << setfill('0')<< v[i];
    }
    std::cout << std::endl;
}

const int maxn = 1e4;
int N;
struct Node{
    vector<int> n;
}node[maxn];
map<int, int> mp; // depth to node id ;


vector<int> re;

void find(vector<int> &tmp, int root, int id){
    tmp.push_back(root);
    if(root == id){
        re = tmp;
        tmp.pop_back();
        return;
    }
    each(to, node[root].n) find(tmp, to, id);

    tmp.pop_back();
}

void solve(){
    cin >> N;
    getchar();
    uu(i, 0, N){
        string s;
        getline(cin, s);
        // #ifdef DEBUG2
        // cout << s << endl;
        // #endif
        int dep = 0;
        for(int i = 0; s[i] == ' '; ++i) dep++;
        int id;
        sscanf(s.c_str(), "%d", &id);
        mp[dep] = id;
        if(dep != 0){
            int fa = mp[dep-1];
            node[fa].n.push_back(id);
        }
    }
    // #ifdef DEBUG2
    // queue<int> Q;
    // Q.push(0);
    // while(!Q.empty()){
    //     int x = Q.front(); Q.pop();

    //     cout << x  << " ";

    //     each(to, node[x].n) Q.push(to);
    // }
    // cout << endl;
    // #endif
    int K;
    cin >> K;
    while(K--){
        int id;
        cin >> id;
        // #ifdef DEBUG2
        // cout << id << endl;
        // #endif
        vector<int> tmp;
        re.clear();
        find(tmp, 0, id);
        if(re.size()){
            print(re);
        }
        else{
            cout << "Error: " << setw(4) << setfill('0') << id << " is not found." << endl;
        }
        

        
    }
    
}

int main(){
    // #ifndef DEBUG
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("o", "w", stdout);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    // cout << setw(4) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}