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

const int maxn = 1000;

int N;
vector<int> pre;


struct Node{
    int d;
    Node *l, *r;
    Node(){
        l=r=nullptr;
    }
};

void insert(Node* &root, int x){
    #ifdef DEBUG2
    pf("in insert\n");
    #endif
    if(root == nullptr){
        #ifdef DEBUG2
        pf("find a null to insert.\n");
        #endif
        root = new Node;
        root->d = x;
    }
    else if(x < root->d){
        #ifdef DEBUG2
        pf("x = %d < root->d=%d.\n", x, root->d);
        #endif
        insert(root->l, x);
    }
    else if(x >= root->d){
        #ifdef DEBUG2
        pf("x = %d >= root->d=%d.\n", x, root->d);
        #endif
        insert(root->r, x);
    }
}

void preT(Node *root, vector<int>& re){// preorder travel
    re.push_back(root->d);
    if(root->l) preT(root->l, re);
    if(root->r) preT(root->r, re);
}

void preTR(Node *root, vector<int>& re){// preorder travel
    re.push_back(root->d);
    if(root->r) preTR(root->r, re);
    if(root->l) preTR(root->l, re);
}

void postT(Node *root, vector<int>& re){// postorder travel
    if(root->l) postT(root->l, re);
    if(root->r) postT(root->r, re);
    re.push_back(root->d);
}

void postTR(Node *root, vector<int>& re){// postorder travel
    if(root->r) postTR(root->r, re);
    if(root->l) postTR(root->l, re);
    re.push_back(root->d);
}

void printv(vector<int>& re){
    uu(i, 0, re.size()){
        if(i == 0) pf("%d", re[i]);
        else pf(" %d", re[i]);
    }
    pf("\n");
}

bool isSame(vector<int>& v1, vector<int>& v2){
    if(v1.size() != v2.size()) return false;
    uu(i, 0, v1.size()){
        if(v1[i] != v2[i]) return false;
    }
    return true;
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    sf("%d", &N);
    pre.resize(N);
    Node *bst = nullptr;
    uu(i, 0, N){
        sf("%d", &pre[i]);
        insert(bst, pre[i]);
    }   

    vector<int> re;
    re.clear();
    preT(bst, re);
    #ifdef DEBUG
    pf("raw preorder:\n");
    printv(pre);
    pf("bst preorder:\n");
    printv(re);
    #endif
    if(isSame(pre, re)){
        pf("YES\n");
        re.clear();
        postT(bst, re);
        printv(re);
    }
    else{
        re.clear();
        preTR(bst, re);
        #ifdef DEBUG
        pf("mirror bst preorder:\n");
        printv(re);
        #endif
        if(isSame(pre, re)){
            pf("YES\n");
            re.clear();
            postTR(bst, re);
            printv(re);
        }
        else{
            pf("NO\n");
        }
    }


    return 0;
}