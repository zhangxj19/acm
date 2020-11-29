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
const int maxn = 21;
int N;

struct Node{
    string d;
    int l, r;
}node[maxn];


vector<string> re;

int find_root(){
    int b[maxn] = {0};
    uu(i, 0, N){
        if(node[i].l != -1) b[node[i].l] = 1;
        if(node[i].r != -1) b[node[i].r] = 1;
    }
    uu(i, 0, N){
        if(b[i] == 0) return i;
    }
}
int isop(string s){
    if(s.size() == 1){
        char c = s[0];
        // if(!isalpha(c) and !isalnum(c) and c != '.') return true;
        // else return false;
        if(c == '+' or c == '-' or c == '*' or c == '/' or c == '%') return true;
        else return false;
    }
    else if(s.size() == 2){
        if(s == "**" or s == "+=" or s == "*=" or s == "/=" or s == "-=" or s == "<<" or s == ">>") return true;
    else return false;
    }
    else{
        return false;
    }

}

void inorder(int root){
    if(root == -1) return;
    if(isop(node[root].d))
        re.push_back("(");
    inorder(node[root].l);

    re.push_back(node[root].d);

    inorder(node[root].r);
    if(isop(node[root].d))
        re.push_back(")");
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
    cin >> N;
    uu(i, 1, N+1){
        cin >> node[i].d >> node[i].l >> node[i].r;
    }

    int root = find_root();
    // int root = 3;
    inorder(root);

    if(re[0] == "(") re.erase(re.begin());
    if(re[re.size()-1] == ")") re.pop_back();

    uu(i, 0, re.size()){
        cout << re[i];
    }
    cout << endl;

    #ifdef DEBUG
    uu(i, 0, re.size()){
        cout << re[i] << " ";
    }
    cout << endl;
    #endif

    return 0;
}