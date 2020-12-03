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
const int maxn = 2*1e4;

int isprime[maxn];

void makeprime(){
    fill(isprime, isprime+maxn, 1);
    isprime[0] = 0;
    isprime[1] = 0;
    for(int i = 2; i < maxn; ++i){
        if(isprime[i] == 1){
            for(int j = i + i; j < maxn; j += i){
                isprime[j] = 0;
            }
        }
    }
}

int MSize, N, M;

vector<int> a; // hash table

int Hash(int x){ // x > 0
    return x%MSize;
}

int insert(int x){
    int re = 0;
    // uu(i, 0, sqrt(MSize)+2){
    uu(i, 0, MSize+1){
        re++;
        int hc = Hash(x + i*i);
        if(a[hc] == 0){
            a[hc] = x;
            return re;            
        }
    }
    return -1;
}

int find(int x){
    int re = 0;
    uu(i, 0, MSize+1){
        re++;
        int hc = Hash(x + i*i);
        if(a[hc] == x or a[hc] == 0){
            return re; // find x in hash table or no x in hash table
        }
    }
    return re; // fail to find x in hash table(hash table is full)
}

void solve(){
    cin >> MSize >> N >> M;
    makeprime();
    #ifdef DEBUG2
    uu(i, 0, 24){
        pf("isprime[%d] = %d\n", i, isprime[i]);
    }
    cout << endl;
    #endif
    if(!isprime[MSize]){
        for(; MSize < maxn; ++MSize){
            if(isprime[MSize]) break;
        }
    }
    #ifdef DEBUG
    cout << MSize << endl;
    #endif
    a.resize(MSize, 0);
    uu(i, 0, N){
        int x;
        cin >> x;
        int re = insert(x);
        if(re == -1){
            cout << x << " cannot be inserted." << endl;
        }
    }

    int re = 0;
    uu(i, 0, M){
        int x;
        cin >> x;
        re += find(x);
    }
    cout << re*1.0 / M << endl;
    #ifdef DEBUG
    pf("re = %d, M = %d\n", re, M);
    #endif


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
    cout << setiosflags(ios::fixed);
    cout << setprecision(1);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}