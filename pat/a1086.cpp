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
const int maxn = 30;

int N, inorder[maxn];
char cmd[8];

stack<int> S;

vector<pair<int, int>> push; // (value, order);

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.second < p2.second;
}

struct Node{
    int d;
    Node *l, *r;
    Node(){
        l=r=NULL;
    }
};

Node *create(int l, int r){
    Node *root = new Node;
    if(l > r) return NULL;
    // if(l == r){
    //     root->d = inorder[l];
    //     return root;
    // }
    for(int i = 0, sizen = push.size(); i < sizen; ++i){
        int min_order_num = push[i].first;
        for(int j = l; j <= r; ++j){
            if(inorder[j] == min_order_num){
                #ifdef DEBUG2
                pf("root is %d\n", inorder[j]);
                #endif
                root->d = inorder[j];
                root->l = create(l, j-1);
                root->r = create(j+1, r);
                return root;
            }
        }
    }
    return root;
}

vector<int> re;

void postorder(Node* root){
    if(root->l) postorder(root->l);
    if(root->r) postorder(root->r);
    re.push_back(root->d);

}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    getchar();
    int cnt = -1, order = -1;
    for(int i = 0; i < 2*N; ++i){
        sf("%[^\n]", cmd);
        getchar();
        if(cmd[1] == 'u'){
            // push
            int num;
            char cmd1[5];
            sscanf(cmd, "%s %d", cmd1, &num);
            #ifdef DEBUG2
            pf("cmd1 = \"%s\" %d\n", cmd1, num);
            #endif
            S.push(num); 
            push.push_back(make_pair(num, ++order));
        }
        else{
            // pop
            inorder[++cnt] = S.top(); S.pop();
        }
    }
    sort(push.begin(), push.end(), cmp);

    #ifdef DEBUG
    for(int i = 0; i < N; ++i){
        pf("%d ", inorder[i]);
    }
    pf("\n");
    uu(i, 0, push.size()){
        pf("(%d, %d) ", push[i].first, push[i].second);
    }
    pf("\n");
    #endif

    Node *root = create(0, N-1);
    postorder(root);
    for(int i = 0, sizen = re.size(); i < sizen; ++i){
        pf("%d", re[i]);
        if(i != sizen - 1) pf(" ");
    }
    pf("\n");

    return 0;
}