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

int n;

struct Node{
    int ns;
    string name;
    ll b, a, t;
    ll tws;
    int rk;
    Node(){
        b = a = t= 0;
        tws = 0;
        ns = 0;
    }
};
vector<Node*> node;

unordered_map<string, Node*> mp;

Node* getnode(string &name){
    if(mp.find(name) == mp.end()){
        Node *x = new Node;
        x->name = name;
        node.push_back(x);
        mp[name] = x;
        return x;
    }
    else{
        return mp[name];
    }
}

void solve(){
    cin >> n;
    uu(i, 0, n){
        string id, name;
        int s;
        cin >> id >> s >> name;

        char cname[10];
        sscanf(name.c_str(), "%s", cname);
        for(int j = 0; cname[j]!='\0'; ++j){
            cname[j] = tolower(cname[j]);
        }
        name = cname;

        Node * x = getnode(name);
        
        if(id[0] == 'B'){
            x->b += s;
        }
        else if(id[0] == 'A'){
            x->a += s;
        } 
        else{
            x->t += s;
        }
        x->ns++;
    }

    each(x, node){
        x->tws = (ll)(x->b*1.0/1.5 + x->a*1.0 + x->t*1.5);
    }

    // getod is abandoned after sort the node
    sort(node.begin(), node.end(), [](Node* &n1, Node* &n2){
        if(n1->tws != n2->tws) return n1->tws > n2->tws;
        else{
            if(n1->ns != n2->ns) return n1->ns < n2->ns;
            else return n1->name < n2->name;
        }
    });

    cout << node.size() << endl;
    int rk = 1;
    node[0]->rk = rk;
    cout << 1 << " " << node[0]->name << " " << node[0]->tws << " " << node[0]->ns << endl;
    uu(i, 1, node.size()){
        rk++;
        if(node[i]->tws == node[i-1]->tws){
            node[i]->rk = node[i-1]->rk;
        }
        else{
            node[i]->rk = rk;
        }
        cout << node[i]->rk << " " << node[i]->name << " " << node[i]->tws << " " << node[i]->ns << endl;
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