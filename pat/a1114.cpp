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
const int maxn = 1e4+1;
int N;

struct Node{
    int e, a, f;
}node[maxn]; // index is id

set<int> S;

// unordered_map<int, Node> node;


int f(int x){
    if(x == node[x].f) return x;
    else{
        int F = f(node[x].f);
        node[x].f = F;
        return F;
    }
}

void Union(int x, int y){
    int Fx = f(x), Fy = f(y);
    if(Fx < Fy){
        node[Fy].f = Fx;
        // node[Fx].e += node[y].e;
        // node[Fx].a += node[y].a;
    }
    else{
        node[Fx].f = Fy;
        // node[Fy].e += node[x].e;
        // node[Fy].a += node[x].a;
    }
    #ifdef DEBUG
    pf("(x, y) = (%04d, %04d) ,fathers=(%04d, %04d) -> (%04d, %04d)\n", x, y, Fx, Fy, node[x].f, node[y].f);
    #endif
    
}

struct Famliy{
    int e, a, m; // total e total a and m
    int id;
    double ave, ava;
};
map<int, Famliy> mp;

vector<Famliy> re;
bool cmp(Famliy &f1, Famliy &f2){
    if(!equ(f1.ava, f2.ava)) return f1.ava > f2.ava;
    else return f1.id < f2.id; 
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
    cout << setiosflags(ios::fixed);
    cout << setprecision(3);
    // cout << setw(4) << setfill('0');  // add this every time when cout int with width and left padding '0'
    
    cin >> N;

    uu(i, 0, maxn){
        node[i].f = i;
    }

    uu(i, 0, N){
        int id, f, m, k;
        cin >> id >> f >> m;
        S.insert(id);
        
        if(f != -1){
            S.insert(f);
            Union(id, f);
        }
        if(m != -1){
            S.insert(m);
            Union(id, m);
        }
        cin >> k;
        uu(j, 0, k){
            int c;
            cin >> c;
            S.insert(c);
            Union(id, c);
        }
        cin >> node[id].e >> node[id].a;
    }
    #ifdef DEBUG
    for(auto& id : S){
        pf("id=%04d father=%d a=%d e=%d\n", id, f(id), node[id].a, node[id].e);
    }
    #endif

    for(auto& id : S){
        int F = f(id);
        mp[F].m += 1;
        mp[F].a += node[id].a;
        mp[F].e += node[id].e;
        // mp[F].id = F;
    }

    for(auto & id_fam: mp){
        id_fam.second.id = id_fam.first;
        id_fam.second.ava = 1.0*id_fam.second.a / id_fam.second.m;
        id_fam.second.ave = 1.0*id_fam.second.e / id_fam.second.m;
        re.push_back(id_fam.second);
    }

    sort(re.begin(), re.end(), cmp);
    cout << re.size() << endl;
    for(auto& fam: re){
        cout << setw(4) << setfill('0') << fam.id << " " << fam.m << " " << fam.ave << " " << fam.ava << endl;
    }


    return 0;
}