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

int P, M, N;

struct Node{
    int gp, gm, gf, g;
    string id;
    Node(){
        gp = -1;
        gm = -1;
        gf = -1;
    }
};
vector<Node> node;
map<string, int> mp;

int get_id(string &id){
    if(mp.find(id) == mp.end()){
        return -1;
    }
    else{
        return mp[id];
    }
}

void add_node(Node &x){
    mp[x.id] = node.size();
    node.push_back(x);
}


bool cmp(Node & n1, Node & n2){
    if(n1.g != n2.g) return n1.g > n2.g;
    else{
        return n1.id < n2.id;
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
    cin >> P >> M >> N;

    string id;
    int d;
    uu(i, 0, P){
        cin >> id >> d;
        if(get_id(id) == -1){
            Node x;
            x.id = id;
            x.gp = d;
            add_node(x);
        }
        else{
            node[get_id(id)].gp = d;
        }
    }

    uu(i, 0, M){
        cin >> id >> d;
        if(get_id(id) == -1){
            Node x;
            x.id = id;
            x.gm = d;
            add_node(x);
        }
        else{
            node[get_id(id)].gm = d;
        }       
    }

    uu(i, 0, N){
        cin >> id >> d;
        if(get_id(id) == -1){
            Node x;
            x.id = id;
            x.gf = d;
            add_node(x);
        }
        else{
            node[get_id(id)].gf = d;
        }       
    }

    each(it, node){
        int re = 0;
        if(it.gp >= 200){
            if(it.gf == -1){
                if(it.gm == -1) re = 0;
                else re += round(it.gm*0.4);
            }
            else{
                if(it.gf > it.gm) re += it.gf;
                else{
                    re += round(it.gm * 0.4 + it.gf * 0.6);
                }
            }
        }
        it.g = re;
    }

    sort(node.begin(), node.end(), cmp);
    each(it, node){
        if(it.gp >= 200 and it.g >= 60){
            cout << it.id << " " << it.gp << " " << it.gm << " " << it.gf << " " << it.g << endl;
        }
    }


    return 0;
}