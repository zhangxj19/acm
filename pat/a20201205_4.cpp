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
const int maxn =21;
vector<int> reactant, product;
map<int, int> setreactant; // value to index

int lt(vector<int>& v1, vector<int>& v2){
    if(v2.size() == 0) return true;

    vector<int> i1, i2;
    each(e, v1) i1.push_back(setreactant[e]);
    each(e, v2) i2.push_back(setreactant[e]);
    sort(i1.begin(), i1.end());
    sort(i2.begin(), i2.end());
    

    for(int i = 0, size = _min(i1.size(), i2.size()); i < size; ++i){
        if(i1[i] < i2[i]) return true;
        else if(i1[i] > i2[i]) return false;
    }
    return false;
}


struct Node{
    int d;
    vector<vector<int>> eqs;
}node[maxn];

vector<int> re, tmp;
int bk[maxn];

int allbk0(vector<int>& v){
    each(e, v) if(bk[e] == 1) return false;
    return true;
}

int allinreact(vector<int> &v){
    each(it, v) if(setreactant.find(it) == setreactant.end()) return false;
    return true;
}

void dfs(vector<int> &eq){ // transform x    
    each(e, eq) bk[e] = 1;

    if(allinreact(eq) and lt(eq, re)){
        re = eq;
    }

    for(int i = 0 ; i < eq.size(); ++i){
        int e = eq[i];
        if(e == 0){ // can replace
            eq.erase(eq.begin()+i);
            each(teq, node[e].eqs){
                if(allbk0(teq)){
                    each(te, teq) eq.push_back(te);
                    dfs(eq);
                    each(te, teq) eq.pop_back();
                }
            }
            eq.insert(eq.begin() + i, e);
        }
    }
    

    each(e, eq) bk[e] = 0;
    return;
}

void solve(){
    int N, M;
    cin >> N;

    uu(i, 0, N){
        int x;
        cin >> x;
        reactant.push_back(x);
        setreactant[x] = i;
    }

    uu(i, 1, N+1){
        if(setreactant.find(i) != setreactant.end()){
            node[i].eqs.push_back({i});
        }
    }

    cin >> M;
    uu(i, 0, M){
        int x;
        cin >> x;
        product.push_back(x);
    }

    int K;
    cin >> K;
    getchar();
    uu(i, 0, K){
        string s;
        getline(cin, s);
        vector<int> reac;
        for(int i = 0; i < s.size(); ){
            int j = i;
            for(; s[j] != ' '; ++j);
            if(s[j+1] == '+' or s[j+1] == '-'){
                int x;
                sscanf(s.substr(i, j-i).c_str(), "%d", &x);
                reac.push_back(x);
                if(s[j+1] == '+'){
                    i = j + 3;
                }
                else{
                    int y;
                    j += 4;
                    sscanf(s.substr(j, s.size()-j).c_str(), "%d", &y);
                    node[y].eqs.push_back(reac);
                    break;
                }
            }
        }
    }
    #ifdef DEBUG
    uu(i, 1, N+1){
        each(eq, node[i].eqs){
            cout << i << ": ";
            print(eq);
        }
    }
    #endif

    each(pro, product){
        re.clear();

        each(eq, node[pro].eqs){
            tmp.clear();
            memset(bk, 0, sizeof(bk));
            // tmp = eq;
            // each(e, eq) bk[e] = 1;
            dfs(eq);
        }

        uu(i, 0, re.size()){
            if(i == 0) cout << setw(2) << setfill('0') <<  re[i];
            else cout << " + " << setw(2) << setfill('0') << re[i];
        }
        cout << " -> " << setw(2) << setfill('0') << pro << endl;
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