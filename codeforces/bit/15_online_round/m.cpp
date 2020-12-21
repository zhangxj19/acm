// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
// override the () operator
// struct cmp{
//     bool operator()(const T &a, const T &b) const{
//         return ;
//     }
// };
// some useful functions:
// unique(it1, it2) upper_bound(it1, it2) lower_bound(it1, it2) equal_range(it1, it2)
// next_permutation(it1, it2)
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

#define rep(i, n) for (int i = 0, size = (n); i < size; ++i)
#define repu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define repd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
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
#define vvi vector<vector<int>>
#define pii pair<int, int>

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

template<typename T>
void print(vector<T> &v){
    rep(i, v.size()){
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

template<typename T>
void print(T* begin, T* end){
    for(T *p = begin; p != end; ++p){
        if(p == begin) cout << *p;
        else cout << " " << *p;
    }
    cout << endl;
}

template<typename T>
T sum(T* begin, T* end){
    T re = 0;
    for(T *p = begin; p != end; ++p) re = re + *p;
    return re;
}

// template<typename T>
// T sum(typename vector<T>::iterator begin, typename vector<T>::iterator end){
//     T re = 0;
//     for(auto p = begin; p != end; ++p) re = re + *p;
//     return re;
// }
int sum(vector<int>::iterator begin, vector<int>::iterator end){
    int re = 0;
    for(auto p = begin; p != end; ++p) re = re + *p;
    return re;
}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){
    ll re = 0;
    for(auto p = begin; p != end; ++p) re = re + *p;
    return re;
}

unsigned seed;
unsigned myrand(unsigned m) {
    seed = seed * 22695477 + 1;
    return seed%m;
}
#define EGG 0
#define DRAGON 1
#define JUNIOR 2
#define CARDE 3

struct Node{
    int type;
    int h, v;
    Node(int t=0):type(t){
        if(type == EGG){
            h = 5;
            v = 1;
        }
        else if(type == DRAGON){
            h = 4;
            v = 4;
        }
        else if(type == JUNIOR){
            h = 6;
            v = 3;
        }
        else if(type == CARDE){
            h = 2;
            v = 2;
        }
    }
};

int cnt_carde[2];
vector<Node> p[2];
deque<int> d[2];
int idx[2];

void add1(int player){
    idx[player]++;
    idx[player] %= p[player].size();
}

void summon(vector<Node>& v, int type, int i, int player){  // insert at i
    Node x(type);
    v.push_back(x);
    if(i < idx[player]) add1(player);
    if(type == CARDE){
        cnt_carde[player]++;
    }
}

void die(vector<Node>& v, int i, int player){
    if(v[i].type == EGG){

        int cnt = cnt_carde[player];
        while(v.size() < 7 and cnt > 0){
            summon(v, DRAGON, i+1, player);
            cnt--;
        }

        d[player].push_back(EGG);
    }
    else if(v[i].type == DRAGON){

        d[player].push_back(DRAGON);
    }
    else if(v[i].type == JUNIOR){
        
        rep(i, min(2, (int)d[player].size())){
            int cnt = cnt_carde[player];
            while(v.size() < 7 and cnt > 0){
                summon(v, d[player].front(), i+1, player);
                d[player].pop_front();
                cnt--;
            }
        }

        d[player].push_back(JUNIOR);
    }
    else if(v[i].type == CARDE){

        d[player].push_back(CARDE);
        cnt_carde[player]--;
    }

}

void solve(){
    cin >> seed;
    int n;
    cin >> n;
    rep(i, n){
        int x;
        cin >> x;
        summon(p[0], x, 0, 0);
    }
    cin >> n;
    rep(i, n){
        int x;
        cin >> x;
        summon(p[1], x, 0, 1);
    }

    rep(i, 10000){
        int re = 0;

        int first = myrand(2);
        int rd = 0;
        while(p[0].size() != 0 and p[1].size() != 0){
            if(rd % 2 == first){
                // player 0 attack 
                int tar = myrand(p[1].size());
                
                p[1][tar].h -= p[0][idx[0]].v;

                if(p[1][tar].h < 0){

                }


            }
            else{
                // player 1 attack 
            }

            rd++;
        }

        cout << re << endl;
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