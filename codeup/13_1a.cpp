// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
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

// #define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;
const int maxn = 3*1e4+1, bn = 174, en = 173;

int T, N;

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    cin >> T;
    uu(casenum, 1, T+1){
        int a[maxn] = {0}, block[bn] = {0};
        cout << "Case " << casenum << ":" << endl;
        cin >> N;
        uu(j, 0, N){
            cin >> a[j];
            block[j / en] += a[j];
        }
        string cmd;
        while(cin >> cmd){

            int x, y; 
            if(cmd == "Add"){
                cin >> x >> y;
                x -= 1;
                #ifdef DEBUG
                pf("Add %d %d\n", x, y);
                #endif
                a[x] += y;
                block[x / en] += y;
            }
            else if(cmd == "Sub"){
                cin >> x >> y;
                x -= 1;
                #ifdef DEBUG
                pf("Sub %d %d\n", x, y);
                #endif
                a[x] -= y;
                block[x / en] -= y;
            }
            else if(cmd == "Query"){ // Query
                cin >> x >> y;
                x -= 1;
                y -= 1;
                #ifdef DEBUG
                pf("Query %d %d\n", x, y);
                #endif        
                int beg = x / en, end = y / en;
                int sum = 0;
                if(beg == end){
                    for(int j = x; j <= y; ++j) sum += a[j];
                }
                else{
                    for(int j = beg + 1 ; j < end; ++j) sum += block[j];
                    for(int j = x; j < (beg+1)*en; ++j) sum += a[j];
                    for(int j = end*en; j <= y; ++j) sum += a[j];
                    
                }

                cout << sum << endl;
            }
            else break;
        }
    }
    
    return 0;           
}