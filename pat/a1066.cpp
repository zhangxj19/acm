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

int N;
struct Node{
    int d, h;
    Node *l, *r;
    Node(int x, Node *l=nullptr, Node *r=nullptr): d(x), l(l), r(r){
        h = 1;
    };
};

int getH(Node *root){
    if(root == nullptr) return 0;
    else return root->h;
}

void updateH(Node *root){
    root->h = _max(getH(root->l), getH(root->r)) + 1;
}

int getBF(Node *root){
    return getH(root->l) - getH(root->r);
}

void R(Node *&root){
    Node *tmp = root->l;
    root->l = tmp->r;
    tmp->r = root;
    updateH(root);
    updateH(tmp);
    root = tmp;
}

void L(Node *&root){
    Node *tmp = root->r;
    root->r = tmp->l;
    tmp->l = root;
    updateH(root);
    updateH(tmp);
    root = tmp;
}


void insert(Node* &root, int x){
    if(root == nullptr){
        root = new Node(x);
        return ;
    }
    if(x < root->d){
        insert(root->l, x);
        updateH(root);
        if(getBF(root) == 2){
            if(getBF(root->l) == 1){
                R(root);
            }
            else if(getBF(root->l) == -1){
                L(root->l);
                R(root);
            }
        }
    }
    else{
        insert(root->r, x);
        updateH(root);
        if(getBF(root) == -2){
            if(getBF(root->r) == -1){
                L(root);
            }
            else if(getBF(root->r) == 1){
                R(root->r);
                L(root);
            }
        }
    }
}

void printLevel(Node *avl){
    queue<Node*> Q;
    set<Node*> S;
    Q.push(avl);
    S.insert(avl);
    while(!Q.empty()){
        Node *node = Q.front(); Q.pop();
        pf("%d ", node->d);

        if(node->l and S.find(node->l) == S.end()){
            Q.push(node->l);
            S.insert(node->l);
        } 
        if(node->r and S.find(node->r) == S.end()){
            Q.push(node->r);
            S.insert(node->r);
        }

    }
    cout << endl;
}



int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> N;
    Node *avl = nullptr;
    uu(i, 0, N){
        int x;
        cin >> x;
        insert(avl, x);

        #ifdef DEBUG
        cout << "insert: " << x << endl;
        // level order
        printLevel(avl);
        #endif
    }



    cout << avl->d << endl;


    return 0;
}