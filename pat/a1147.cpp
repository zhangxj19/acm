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
#define each(it, a) for(auto & (it) : (a))
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define lowbit(x) (x&(-x))
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(std::vector<int> &v){
    uu(i, 0, v.size()){
        if(i == 0) std::cout << v[i];
        else std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

using namespace std;
#define lc(x) (2*(x)+1)
#define rc(x) (2*(x)+2)

int M, N;

int havelc(int x){
    return lc(x) < N;
}

int haverc(int x){
    return rc(x) < N;
}

vector<int> a, post;

int isheap(){
    // 0 not heap
    // -1 min heap
    // 1 max heap

    int ismax = true;
    if(a[0] >= a[lc(0)] and a[0] >= a[rc(0)]){
        // test max 
        ismax = true;
    }
    else if(a[0] <= a[lc(0)] and a[0] <= a[rc(0)]){
        // test min
        ismax = false;
    }

    // level order;
    queue<int> Q;
    Q.push(0);
    int isheap = true;
    while(!Q.empty()){
        int x= Q.front(); Q.pop();
        if(ismax){
            if(!((!havelc(x) or (havelc(x) and a[x] >= a[lc(x)])) and (!haverc(x) or (haverc(x) and a[x] >= a[rc(x)])))){
                isheap = false;
                break;
            }
        }
        else{
            if(!((!havelc(x) or (havelc(x) and a[x] <= a[lc(x)])) and (!haverc(x) or (haverc(x) and a[x] <= a[rc(x)])))){
                isheap = false;
                break;
            }           
        }

        if(havelc(x)) Q.push(lc(x));
        if(haverc(x)) Q.push(rc(x));
        
    }
    if(!isheap) return 0;
    if(isheap and ismax) return 1;
    if(isheap and !ismax) return -1;
}

void post_travel(int root){
    if(root >= N) return;
    post_travel(lc(root));
    post_travel(rc(root));
    post.push_back(a[root]);
    
}

void solve(){
    cin >> M >> N;
    while(M--){
        a.resize(N, 0);
        post.clear();
        uu(i, 0, N) cin >> a[i];
        int flag = isheap();
        if(flag == 0){
            cout << "Not Heap" << endl;
        }
        else if(flag == -1){
            cout << "Min Heap" << endl;
        }
        else if(flag == 1){
            cout << "Max Heap" << endl;
        }
        post_travel(0);
        print(post);
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
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}