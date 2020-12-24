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

int gcd(int a, int b){return !b ? a : gcd(b, a % b);}

template<typename T>
void print(vector<T> &v){rep(i, v.size()){if(i == 0) cout << v[i];else cout << " " << v[i];}cout << endl;}

template<typename T>
void print(T* begin, T* end){for(T *p = begin; p != end; ++p){if(p == begin) cout << *p;else cout << " " << *p;}cout << endl;}

template<typename T>
T sum(T* begin, T* end){T re = 0;for(T *p = begin; p != end; ++p) re = re + *p;return re;}

int sum(vector<int>::iterator begin, vector<int>::iterator end){int re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

ll sum(vector<ll>::iterator begin, vector<ll>::iterator end){ll re = 0;for(auto p = begin; p != end; ++p) re = re + *p;return re;}

int read(){int x; cin >> x; return x;}

int t[5], q; // 
int gbc[26]; // global char
int lock; // 0 for free

struct Node{
    int id;
    vector<string> cmd;
    int idx;
    Node(){
        idx = 0;
        cmd.clear();
    }
};

deque<Node> ready, blocked;

int gettime(string& x){
    if(x == "print") return t[1];
    else if(x == "lock") return t[2];
    else if(x == "unlock") return t[3];
    else if(x == "end") return t[4];
    else return t[0]; // size = 3
}

string token1(string &x){
    string re;
    each(c, x){
        if(c == ' ' or c == '\n') break;
        re += c;
    }
    return re;
}

void solve(){
    int T;
    cin >> T;
    repu(kcase, 1, T+1){
        if(kcase != 1) cout  << endl;
        ready.clear();
        blocked.clear();
        memset(gbc, 0 , sizeof(gbc));
        lock = 0;
        int n;
        cin >> n;
        rep(i, 5) cin >> t[i];
        cin >> q;
        // cin.ignore('\n', 100);
        string s;
        getline(cin, s);
        
        rep(i, n){
            Node x;
            x.id = i + 1;
            while(getline(cin, s), s!="end"){
                x.cmd.push_back(s);
            }
            x.cmd.push_back(s);
            ready.push_back(x);
        }

        while(ready.size()){
            Node x = ready.front(); ready.pop_front();
            int Q = q;
            int is_blocked = 0;
            while(Q > 0 and x.idx < x.cmd.size()){
                // finish the cmd;
                string token = token1(x.cmd[x.idx]);
                int time = gettime(token);
                Q -= time;
                

                if(token == "print"){
                    // print
                    char ch;
                    char c[6];
                    sscanf(x.cmd[x.idx].c_str(), "%s %c", c, &ch);
                    cout << x.id << ": " << gbc[ch-'a'] << endl;
                }
                else if(token == "lock"){
                    // lock
                    if(lock == 0){
                        lock = x.id;
                    }
                    else{
                        // x.idx++;
                        blocked.push_back(x);
                        is_blocked = 1;
                        break;
                    }
                }
                else if(token == "unlock"){
                    // unlock
                    lock = 0;
                    if(blocked.size()){
                        Node y = blocked.front(); blocked.pop_front();
                        // x.idx++;
                        // ready.push_back(x);
                        // is_blocked=1;
                        ready.push_front(y);
                    }
                }
                else if(token == "end"){
                    // end
                }
                else{ // variable = value
                    char c;
                    int v;
                    sscanf(x.cmd[x.idx].c_str(), "%c = %d", &c, &v);
                    gbc[c-'a'] = v;
                }
                x.idx++; 
            }
            if(x.idx < x.cmd.size() and !is_blocked) ready.push_back(x);
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
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}