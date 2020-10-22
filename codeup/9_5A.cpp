// #include <bits/stdc++.h>
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

int n, k;

struct Node{
    int d, h;
    Node *l, *r;
    Node(){
        l = r = nullptr;
        h = 1;
    }
    Node(int x, Node *l = nullptr, Node *r = nullptr): d(x), l(l), r(r){
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

int getBF(Node *root){ // balance factor
    return getH(root->l) - getH(root->r);
}

void R(Node* &root){
    Node *tmp = root->l;
    root->l = tmp->r;
    tmp->r = root;
    updateH(root);
    updateH(tmp);
    root = tmp;
}

void L(Node* &root){
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

bool search(Node *root, int x){
    if(root == nullptr) return false;
    if(x < root->d){
        return search(root->l, x);
    }
    else if(x > root->d){
        return search(root->r, x);
    }
    else{
        return true;
    }
    return false;
}   

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> n >> k;
    Node *avl = nullptr;
    uu(i, 0, n){
        int x;
        cin >> x;
        insert(avl, x);
    }

    #ifdef DEBUG
    // level order
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

    #endif
    uu(i, 0, k){
        int x;
        cin >> x;
        cout << search(avl, x) << " ";
    }

    cout << endl;
    return 0;
}   