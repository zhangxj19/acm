// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
// 5) use cout << '\n'; instead of cout << endl; (cout << endl is really slow)
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
#include <numeric>
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
#define pll pair<ll, ll>

using namespace std;

struct UF{
    vi f, sz; // father and component size
    int cnt; // set number 
    UF(int n): cnt(n), f(n), sz(n,1){
        rep(i, n){f[i] = i;}
    }

    int find(int x){
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    bool unite(int x, int y){
        x=find(x), y=find(y);
        if(x==y) return false;
        else{
            if(sz[x] < sz[y]) swap(x, y);
            f[y] = x;
            sz[x] += sz[y];
            cnt--;
            return true;
        }
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

};

int lowerbound(vector<int>& a, int x){
    int l = 0, r = a.size() -1 ;
    while(l < r){
        int m = (l + r) >> 1;
        if(a[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

template<typename T>
void print(vector<T> &v){rep(i, v.size()){if(i != 0) cout << " "; cout << v[i];}cout << '\n';}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p != begin) cout << " "; cout << *p;}cout << '\n';}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){ll re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}

const int cardnum = 52;

void solve(){
    while(1){
        deque<int> deck;
        unordered_set<string> s;
        int x;
        cin >> x;
        if(x == 0) break;
        else deck.push_back(x);
        rep(i, cardnum - 1){
            deck.push_back(read());
        }
        int pilenum = 7;
        vector<deque<int>> piles(pilenum);
        
        int re = 0;
        auto check = [&](deque<int>& dq){
            if(dq.size() < 3) return 0;
            // 2 .. 1
            while(dq.size() >= 3){
                int pick = 0;
                if((dq[0] + dq[1] +dq.back()) % 10 == 0){
                    deck.push_back(dq[0]); deck.push_back(dq[1]); deck.push_back(dq.back());
                    dq.pop_front();
                    dq.pop_front();
                    dq.pop_back();
                    pick = 1;
                }
                // 1 .. 2
                else if((dq[0] + dq[dq.size()-2] +dq.back()) % 10 == 0){
                    deck.push_back(dq[0]); deck.push_back(dq[dq.size()-2]); deck.push_back(dq.back());
                    dq.pop_front();
                    dq.pop_back();
                    dq.pop_back();
                    pick = 1;
                }
                // .. 3
                else if((dq[dq.size()-3] + dq[dq.size()-2] +dq.back()) % 10 == 0){
                    deck.push_back(dq[dq.size()-3]); deck.push_back(dq[dq.size()-2]); deck.push_back(dq.back());
                    dq.pop_back();
                    dq.pop_back();
                    dq.pop_back();
                    pick = 1;
                }
                if(!pick)break;
            }

            
            if(dq.size() == 0) return 1;
            else return 0;
        };
        
        int i = 0;
        int isdraw = 0;
        while(!deck.empty()){

            string key = "";
            each(x, deck){
                key += ",";
                key += to_string(x);
            }
            rep(i, piles.size()){
                key += ",";
                key += to_string(i);
                each(y, piles[i]){
                    key += ",";
                    key += to_string(y);
                }
            }
            if(s.count(key)){
                isdraw = 1;
                break;
            } 
            else s.insert(key);

            piles[i].push_back(deck.front()); re++;
            deck.pop_front();

            if(check(piles[i]) == 1){
                piles.erase(piles.begin() + i);
                pilenum--;
                if(piles.empty()) break;
            }
            else{
                i++;
            }

            i %= pilenum;
        }

        if(piles.empty()){
            cout << "Win : " << re << '\n';
            continue;
        }

        if(deck.empty()){
            cout << "Loss: " << re << '\n';
            continue;
        }

        if(isdraw){
            cout << "Draw: " << re << '\n';
            continue;
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