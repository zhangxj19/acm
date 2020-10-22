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

const int maxn = 10;

int N, bk[maxn];

vector<pair<int, int>> v;

struct Node{
    int d;
    Node *l, *r;
    Node(){
        l = r = NULL;
    }
};

Node *create(int rtnum){
    Node *node = new Node;
    node->d = rtnum;

    if(v[rtnum].first != -1) node->l = create(v[rtnum].first);
    if(v[rtnum].second != -1) node->r = create(v[rtnum].second);

    return node;
}

#ifdef DEBUG
void printIn(Node *root){
    if(root->l) printIn(root->l);
    pf("%d ", root->d);
    if(root->r) printIn(root->r);
}
#endif

void invert(Node *root){
    Node *tmp = root->l;
    root->l = root->r;
    root->r = tmp;

    if(root->l) invert(root->l);
    if(root->r) invert(root->r);
}

vector<int> relevel, rein;

void levelOrder(Node *root){
    queue<Node*> Q;
    unordered_set<int> S;
    Q.push(root);
    S.insert(root->d);

    while(!Q.empty()){
        Node *node = Q.front(); Q.pop();
        relevel.push_back(node->d);

        if(node->l and S.find(node->l->d) == S.end()){
            Q.push(node->l);
            S.insert(node->l->d);
        }
        if(node->r and S.find(node->r->d) == S.end()){
            Q.push(node->r);
            S.insert(node->r->d);
        }
    }
}

void inOrder(Node *root){
    if(root->l) inOrder(root->l);
    rein.push_back(root->d);
    if(root->r) inOrder(root->r);
}

void printre(vector<int>& re){
    for(int i = 0, sizen = re.size(); i < sizen; ++i){
        pf("%d", re[i]);
        if(i != sizen-1) pf(" ");
    }
    pf("\n");
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    getchar();
    uu(i, 0, N){
        char c[2];
        sf("%c %c", &c[0], &c[1]);
        getchar();
        int num[2];
        for(int i = 0; i < 2; ++i){
            if('0' <= c[i] and c[i] <= '9') num[i] = c[i] - '0';
            else num[i] = -1;
            if(num[i] != -1) bk[num[i]] = 1; // bk[root] = 0;
        }
        v.push_back(make_pair(num[0], num[1]));
    }

    // get number of root
    int rtnum = 0;
    for(; bk[rtnum] != 0; ++rtnum);

    Node *root = create(rtnum);

    #ifdef DEBUG
    printIn(root);
    pf("\n");
    #endif

    invert(root);

    #ifdef DEBUG
    printIn(root);
    pf("\n");
    #endif

    levelOrder(root);
    inOrder(root);
    printre(relevel);
    printre(rein);



    return 0;
}