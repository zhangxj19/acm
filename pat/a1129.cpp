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
#define lowbit(x) (x&(-x))

using namespace std;
int N, K;
struct Node{
    int id, cnt;
    bool operator < (const Node& n){
        if(cnt != n.cnt) return cnt > n.cnt;
        else return id < n.id;
    }
};

#define pin pair<int, Node>
struct cmp
{
    bool operator()(const pin &pin1, const pin &pin2){
        if(pin1.second.cnt != pin2.second.cnt) return pin1.second.cnt > pin2.second.cnt;
        else return pin1.second.id < pin2.second.id;
    }
};


unordered_map<int, Node> mp; // value to node

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
    cin >> N >> K;
    Node x;
    int v;
    cin >> v;
    x.id = v;
    x.cnt = 1;
    mp[v] = x;

    uu(i, 1, N){
        cin >> v;
        cout << v << ":";
        vector<pair<int, Node>> tmp(mp.begin(), mp.end());
        sort(tmp.begin(), tmp.end(), cmp());
        if(tmp.size() < K){
            for(auto & v_node : tmp){
                cout << " " << v_node.first;
                #ifdef DEBUG
                cout << ":" << v_node.second.cnt;
                #endif
            }               
        }
        else{
            int cnt = 0;
            for(auto & v_node : tmp){
                cout << " " << v_node.first;
                #ifdef DEBUG
                cout << ":" << v_node.second.cnt;
                #endif
                cnt++;
                if(cnt == K) break;
            }
        }
        cout << endl;

        
        if(mp.find(v) == mp.end()){
            Node x;
            x.cnt = 1;
            x.id = v;
            mp[v] = x;
        }
        else{
            mp[v].cnt += 1;
        }
    }


    return 0;
}