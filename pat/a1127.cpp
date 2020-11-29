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
// const int maxn = 31;

int N;
vector<int> in, post;

struct Node{
    int d;
    Node *l, *r;
};

Node* create(int il, int ir, int pol, int por){
    if(il > ir or pol > por) return nullptr;
    if(il == ir){
        Node * root = new Node;
        root->d = in[il];
        root->l = nullptr;
        root->r = nullptr;
        return root;
    }
    else{
        Node *root = new Node;
        root->d = post[por];
        
        // find x;
        int x = 0, k = 0;
        uu(i, il, ir+1) if(in[i] == post[por]) x = i; // elements in "in" is distinct

        k = x - il;
        root->l = create(il, x-1, pol, pol+k-1);
        root->r = create(x+1, ir, pol+k, por-1);

        return root;
    }
}

vector<vector<int>> re;
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
    in.resize(N);
    post.resize(N);
    uu(i, 0, N) cin >> in[i];
    uu(i, 0, N) cin >> post[i];

    Node *root = create(0, N-1, 0, N-1);

    queue<pni> Q;
    Q.push(make_pair(root, 0)); // node and depth
    int dep = 0;
    vector<int> tmp;
    while(!Q.empty()){
        pni x = Q.front(); Q.pop();

        if(x.second != dep){
            dep = x.second;
            re.push_back(tmp);
            tmp.clear();
        }

        tmp.push_back(x.first->d);

        if(x.first->l != nullptr) Q.push(make_pair(x.first->l, x.second+1));
        if(x.first->r != nullptr) Q.push(make_pair(x.first->r, x.second+1));

    }
    re.push_back(tmp);

    vector<int> ans;
    uu(i, 0, re.size()){
        if(i % 2 == 0) reverse(re[i].begin(), re[i].end());

        uu(j, 0, re[i].size()){
            ans.push_back(re[i][j]);
            // if(j == 0) cout << re[i][j];
            // else cout << " " << re[i][j];
        }
        // cout << endl;
    }
    for(auto it = ans.begin(); it != ans.end(); ++it){
        if(it == ans.begin()) cout << *it;
        else cout << " " << *it;
    }
    cout << endl;


    
    return 0;
}