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

int N, M, K;


vector<int> seq;

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    cin >> M >> N >> K;
    uu(i, 0, K){
        stack<int> S;
        seq.clear(); seq.resize(N);
        bool is_handle = true, is_yes = true;
        int cnt = 1;
        #ifdef DEBUG
        pf("new query ========================\n");
        #endif
        uu(j, 0, N){
            cin >> seq[j];
            if(!(seq[j]>=0 and seq[j] <= N)) is_handle = false;
            if(is_handle){
                #ifdef DEBUG
                pf("(cnt vs seq) = (%d vs %d)\n", cnt, seq[j]);
                #endif
                if(cnt == seq[j]){ // push and pop. nothing to do
                    cnt++;
                    continue;
                }
                else if(cnt < seq[j]){
                    // still not in stack
                    while(cnt != seq[j] and S.size() < M){
                        S.push(cnt++);
                    }
                    if(cnt == seq[j] and S.size() < M){
                        cnt++;
                    }
                    else{
                        #ifdef DEBUG
                        pf("cnt=%d, seq=%d, S.size()=%d, M=%d\n", cnt, seq[j], (int)S.size(), M);
                        #endif
                        is_yes = false;
                        is_handle = false;                       
                    }

                }
                else if(cnt > seq[j]){
                    // already in the stack, need to pop
                    while(!S.empty() and S.top() != seq[j]){
                        S.pop();
                    }
                    if(S.empty()){
                        is_yes = false;
                        is_handle = false;
                    }
                    else{
                        S.pop();
                    }
                }
            }
        }
        if(is_yes) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}