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
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <unordered_map>


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
#define pii pair<int, int>
#define pis pair<int, string>
int N, M;

struct Node{
    int s;
    string card;
};

bool cmp(const pis & n1, const pis & n2){
    if(n1.first != n2.first) return n1.first > n2.first;
    else return n1.second < n2.second;
}

void solve(){
    cin >> N >> M;
    vector<Node> node; // for 1
    node.resize(N);
    uu(i, 0, N){
        cin >> node[i].card >> node[i].s;
    }

    uu(num, 1, M+1){
        
        string cmd, v;
        cin >> cmd >> v;
        cout << "Case " << num << ": " << cmd << " " << v << endl;
        // vector<Node> ans;
        vector<pis> ans;
        pii ans2;
        ans2.first = ans2.second = 0;
        
        if(cmd == "1"){
            each(it, node) if(it.card.substr(0, 1) == v) ans.push_back({it.s, it.card});
        }
        else if(cmd == "2"){
            int i = 0;
            // for(; i < site.size() and site[i].site != v; ++i);
            each(it, node) if(it.card.substr(1, 3) == v){
                ans2.first++;
                ans2.second += it.s;
            }
        }
        else if(cmd == "3"){
            int i = 0;
            unordered_map<string, int> mp; // site to index
            each(it, node){
                if(it.card.substr(4, 6) == v){
                    if(mp.find(it.card.substr(1, 3)) == mp.end()){
                        mp[it.card.substr(1, 3)] = ans.size();
                        ans.push_back({1, it.card.substr(1, 3)});
                    }
                    else{
                        ans[mp[it.card.substr(1, 3)]].first += 1;
                    }
                } 
            }
            // each(it, node){
            //     if(it.card.substr(4, 6) == v){
            //         mp[it.card.substr(1, 3)]++;
            //     }
            // }
            // each(it, mp) ans.push_back({it.second, it.first});

        }

        sort(ans.begin(), ans.end(), cmp);
        if((cmd == "1" or cmd == "3") and ans.size()){
            each(it, ans) cout << it.second << " " << it.first << endl;
        }
        else if(cmd == "2" and ans2.first != 0){
            cout << ans2.first << " " << ans2.second << endl;
        }
        else{
            cout << "NA" << endl;
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