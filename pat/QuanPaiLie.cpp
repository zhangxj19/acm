// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define DEBUG

#define _U(i, a, b) for (int i = (a); i < (b); ++i)
#define _D(i, a, b) for (int i = (a); i > (b); --i)
#define _P printf

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

const int maxn = 11;

int n, p[maxn+1], ht[maxn] = {0}, cnt=0;
unordered_set<int> s;


void dfs(int idx){
    // s.insert(idx);
    if(idx == n+1){
        // print
        _U(i, 1, n+1){
            _P("%d ", p[i]);
        }
        _P("\n");
        cnt+=1;
        return;
    }
    for(int x = 1; x <= n; x++){
        // if(ht[x] == 0){
        if(s.find(x) == s.end()){
            p[idx] = x;
            s.insert(x);
            dfs(idx+1);
            s.erase(x);
        }

    }
    // s.erase(idx);
    
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d", &n);
    dfs(1);
    printf("cnt = %d\n", cnt);
    return 0;
}