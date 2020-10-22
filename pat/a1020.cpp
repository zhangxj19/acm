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

#define DEBUG

#define uu(i, a, b) for (int i = (a); i < (b); ++i)
#define dd(i, a, b) for (int i = (a); i > (b); --i)
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
const int maxn = 30;

int N, post[maxn], inorder[maxn];

struct Node{
    int d;
    Node *l, *r;
    Node(){
        d = INT_MIN;
        l=r=NULL;
    }
    Node(Node *l, Node *r, int d){
        l = l; r = r; d = d;
    }
};

Node *create(int pl, int pr, int inl, int inr){
    if(pl > pr) return NULL;
    Node *root = new Node;
    root->d = post[pr];

    int k = 0;
    for(k = inl; inorder[k] != post[pr]; ++k);
    int len = k - inl;
    root->l = create(pl, pl+len-1, inl, k-1);
    root->r = create(pl+len, pr-1, k+1, inr);
    
    return root;
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    uu(i, 0, N){
        sf("%d", &post[i]);
    }
    uu(i, 0, N){
        sf("%d", &inorder[i]);
    }

    Node *root = create(0, N-1, 0, N-1);

    queue<Node*> Q;
    set<int> S;
    Q.push(root);
    S.insert(root->d);
    vector<int> re;
    while(!Q.empty()){
        Node *n = Q.front(); Q.pop();
        re.push_back(n->d);

        if(n->l){
            Q.push(n->l);
            S.insert(n->l->d);
        }
        if(n->r){
            Q.push(n->r);
            S.insert(n->r->d);
        }

    }

    for(int i = 0; i < N; ++i){
        pf("%d", re[i]);
        if(i != N-1) pf(" ");
    }
    pf("\n");

    return 0;
}