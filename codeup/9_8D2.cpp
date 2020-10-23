// #include <bits/stdc++.h>
// 2 options:
// 1) cin cout 
// 2) scanf printf
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
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

// #define DEBUG

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;

bool equ(double a, double b){
    return fabs(a-b) < eps;
}

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return a/gcd(a, b)*b;
}

using namespace std;

int n, size;

struct Node{
    int w, idx;
    Node *l, *r, *f;
    char c;
    string huff;
    // friend bool operator < (const Node &n1, const Node &n2){
    //     return n1.w > n2.w;
    // }
    Node(char c, int w, Node* l=nullptr, Node* r=nullptr, Node* f=nullptr):c(c), w(w), l(l), r(r), f(f){};
};

struct cmp{
    bool operator()(const Node* n1, const Node* n2){
        if(n1->w != n2->w) return n1->w > n2->w;
        else return n1->c > n2->c;
    }
};

priority_queue<Node*, vector<Node*>, cmp> pq;
vector<Node*> leaf;

string huff;

void inorder(Node *root){
    if(root == root->f->l) huff += '0';
    if(root == root->f->r) huff += '1';
    if(root->l != nullptr) inorder(root->l);

    if(root->l == nullptr and root->r == nullptr) root->huff = huff;

    if(root->r != nullptr) inorder(root->r);

    huff.pop_back();
}


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    while(cin >> n){
        size = 0;
        while(!pq.empty()) pq.pop();
        leaf.clear();
        uu(i, 0, n){
            char c;
            int w;
            cin >> c >> w;
            Node *tmp = new Node(c, w);
            leaf.push_back(tmp);
            pq.push(tmp);
        }

        while(pq.size() > 1){
            Node *n1 = pq.top(); pq.pop();
            Node *n2 = pq.top(); pq.pop();
            Node *n = new Node(n1->c, n1->w + n2->w, n1, n2);
            #ifdef DEBUG
            pf("pick %d and %d, sum is %d\n", n1->w, n2->w, n->w);
            #endif
            n1->f = n2->f = n;
            pq.push(n);
        }
        Node *root = pq.top(); pq.pop();

        #ifdef DEBUG
        queue<Node*> Q;
        Q.push(root);
        int bk[maxn];
        memset(bk, 0, sizeof(bk));
        bk[root->idx] = 1;
        while(!Q.empty()){
            Node * n = Q.front(); Q.pop();

            cout << n->w << " ";
            
            if(n->l != -1){
                cout << "left is " << node[n->l].w << " ";
                Q.push(&node[n->l]);
            }
            if(n->r != -1){
                cout << "right is " << node[n->r].w << " ";
                Q.push(&node[n->r]);
            }
            cout << endl;
        }
        #endif

        inorder(root);

        uu(i, 0, n){
            cout << leaf[i]->c << ":" << leaf[i]->huff << endl;
        }


    
    }


    return 0;
}