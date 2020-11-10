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

#define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;
const int maxn = 1e5+1, maxb = 317;
int n, table[maxn], block[maxb];
int bn, en;
stack<int> S;

int findnum(int blockid, int sum, int mid){
    for(int j = blockid*en; j < (blockid+1)*en; ++j){
        sum += table[j];
        if(sum >= mid){
            return j;
        }
    }
    return -1;
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);

    cin >> n; 
    // n is just n times operation not the upperbound of the input number, sor the bn should be
    // (int)ceil(sqrt(maxn)) not (int)ceil(sqrt(n)) as well as en.
    bn = (int)ceil(sqrt(maxn));
    en = (int)floor(sqrt(maxn));
    
    while(n--){ 
        string cmd;
        cin >> cmd;
        if(cmd == "Push"){
            int x;
            cin >> x;
            table[x]++;
            block[x / en]++;
            S.push(x);
        }
        else if(cmd == "Pop"){
            if(S.empty()){
                cout << "Invalid" << endl;
                continue;
            }
            int x = S.top(); S.pop();
            cout << x << endl;
            block[x / en]--;
            table[x]--;

        }
        else if(cmd == "PeekMedian"){
            if(S.empty()){
                cout << "Invalid" << endl;
                continue;
            }
            int mid = ((S.size()%2&1) ? (S.size()+1)/2 : S.size()/2);
            int sum = 0, i, re;
            for(i = 0; i < bn; ++i){ // i is block id
                if(sum + block[i] < mid){
                    sum += block[i];
                    continue;
                }
                else if(sum + block[i] >= mid){
                    // at block i
                    re = findnum(i, sum, mid);
                    break;
                }  
            }
            cout << re << endl;


        }
    }
    
    return 0;
}