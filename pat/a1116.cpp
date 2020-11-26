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
const int maxn = 1e4+1;
int N, mp[maxn], K, bk[maxn]; // name to rank and checked book

int prime[maxn];


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

    fill(prime, prime+maxn, 1);
    //make prime
    prime[0] = 0;
    prime[1] = 0;
    uu(i, 2, maxn){
        for(int j = i+i; j <= maxn; j +=i){
            prime[j] = 0;
        }
    }
    #ifdef DEBUG2
    uu(i, 0, N+1){
        cout << i << " " << prime[i] << endl;
    }
    #endif

    uu(i, 1, N+1){
        int id;
        cin >> id;
        mp[id] = i; // name to rank
    }

    cin >> K;
    while(K--){
        int id;
        cin >> id;
        cout << setw(4) << setfill('0') << id << ": ";
        if(mp[id] == 0) cout << "Are you kidding?" << endl;
        else{
            if(bk[id] == 1){
                cout << "Checked" << endl;
            }
            else{
                bk[id] = 1;
                if(mp[id] == 1) cout << "Mystery Award" << endl;
                else if(prime[mp[id]]) cout << "Minion" << endl;
                else cout << "Chocolate" << endl;
            }
        }

    }


    
    return 0;
}