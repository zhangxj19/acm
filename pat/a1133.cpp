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
const int maxn = 1e5+1;

int head, N, K;

struct Node{
    int d, n;
}node[maxn];

int find_non_neg(){ // return address
    int x = -1, y = head;
    while(y != -1 and node[y].d < 0){
        x = y;
        y = node[x].n;
    }

    return x; // insert after x
}

int find_K(){
    int x = -1, y = head;
    while(y != -1 and node[y].d <= K){
        x = y;
        y = node[x].n;
    }

    return x; // insert after x
}

int find_x(int ad){
    int x = -1, y = head;
    while(y != -1 and y != ad){
        x = y;
        y = node[x].n;
    }
    return x; // insert after x   
}

void del(int x){ // delete after x
    if(x == -1){
        head = node[head].n; 
    }
    else{
        int nxt = node[x].n;
        node[x].n = node[nxt].n;    
    }
}

void insert(int x, int ad){
    if(x == -1){
        // insert at head
        node[ad].n = head;
        head = ad;
    }
    else{
        int nxt = node[x].n;
        node[x].n = ad;
        node[ad].n = nxt;
    }
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
    // cout << setw(5) << setfill('0');  // add this every time when cout int with width and left padding '0'
    cin >> head >> N >> K;

    uu(i, 0, N){
        int ad;
        cin >> ad;
        cin >> node[ad].d >> node[ad].n;

    }
    #ifdef DEBUG2
    cout << "raw" << endl;
    int tmp = head;
    while(tmp != -1){
        cout << setw(5) << setfill('0') << tmp << " " << node[tmp].d << " " ;
        if(node[tmp].n != -1)
            cout << setw(5) << setfill('0') << node[tmp].n << endl;
        else cout << -1 << endl;

        tmp = node[tmp].n;
    }
    cout << endl;
    #endif
    // find negtive
    int x = head;
    while(x != -1){
        if(node[x].d < 0){
            int adtodel = find_x(x);
            int adtoinsert = find_non_neg();
            del(adtodel);
            insert(adtoinsert, x);
        }
        x = node[x].n;
    }

    // find [0, K]
    x = head;
    while(x != -1){
        if(node[x].d >= 0 and node[x].d <= K){
            int adtodel = find_x(x);
            int adtoinsert = find_K();
            del(adtodel);
            insert(adtoinsert, x);
        }
        x = node[x].n;
    }

    x = head;
    while(x != -1){
        cout << setw(5) << setfill('0') << x << " " << node[x].d << " " ;
        if(node[x].n != -1)
            cout << setw(5) << setfill('0') << node[x].n << endl;
        else cout << -1 << endl;

        x = node[x].n;
    }


    return 0;
}