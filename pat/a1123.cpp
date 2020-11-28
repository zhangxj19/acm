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


int N;
vector<int> a;

struct Node{
    int d, h;
    Node *l, *r;
    Node(int d, Node *l=nullptr, Node *r=nullptr):d(d), l(l), r(r){
        h = 1;
    };
};

int height(Node *root){
    if(root == nullptr) return 0;
    else return root->h;
}

int bf(Node *root){ // balence factor
    return height(root->l) - height(root->r);
}

void updateH(Node *root){
    int lh = height(root->l), rh = height(root->r);
    root->h = _max(lh, rh) + 1;
}

void right(Node *& root){ // bf = -2
    #ifdef DEBUG
    cout << "left" << endl;
    #endif
    Node * lc = root->l;
    root->l = lc->r;
    lc->r = root;

    updateH(root);
    updateH(lc);
    root = lc;
}

void left(Node *& root){ // bf = 2
    #ifdef DEBUG
    cout << "left" << endl;
    #endif
    Node * rc = root->r;
    root->r = rc->l;
    rc->l = root;

    updateH(root);
    updateH(rc);
    root = rc;
}

void insert(Node *&root, int d){
    if(root == nullptr){
        root = new Node(d);
    }
    else{
        if(d <= root->d){
            insert(root->l, d);
            updateH(root);
            if(bf(root) == 2){
                if(bf(root->l) == 1){ // LL
                    right(root);
                }
                else{ // LR
                    left(root->l);
                    right(root);
                }
            }
        }
        else{
            insert(root->r, d);   
            updateH(root);
            if(bf(root) == -2){
                if(bf(root->r) == -1){ // RR
                    left(root);
                }
                else{
                    right(root->r);
                    left(root);
                }
            } 
        }
    }
}


#define pni pair<Node*, int>



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
    cin >> N;
    a.resize(N);
    Node *root = nullptr;
    uu(i, 0, N){
        int x;
        cin >> x;
        insert(root, x);
    }

    //level order
    vector<int> re;
    queue<pni> Q;
    Q.push(make_pair(root, 0)); // node and index of cbt
    map<int, int> mp;
    while(!Q.empty()){
        pni x = Q.front(); Q.pop();
        re.push_back(x.first->d);

        mp[x.second] = x.first->d;

        #ifdef DEBUG
        pf("(%d, %d) ", x.first->d, x.second);
        #endif

        if(x.first->l != nullptr) Q.push(make_pair(x.first->l, x.second*2+1));
        if(x.first->r != nullptr) Q.push(make_pair(x.first->r, x.second*2+2));
    }
    #ifdef DEBUG
    pf("%\n");
    #endif

    for(auto it = re.begin(); it != re.end(); ++it){
        if(it == re.begin()) cout << *it;
        else cout << " " << *it;
    }
    cout << endl;

    uu(i, 0, N){
        if(mp.find(i) == mp.end()){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    
    return 0;
}