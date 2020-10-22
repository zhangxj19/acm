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

#define DEBUG

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
const int maxn = 21;

int n, r, bk[maxn];
vector<int> re;
void printre(){
    for(int i = 0, n = re.size(); i < n; i++){
        pf("%d", re[i]);
        if(i != re.size()-1) pf(" ");
    }
    pf("\n");
}


void dfs(int num){
    re.push_back(num);
    bk[num] = 1;

    if(re.size() == r){
        printre();
        re.pop_back();
        bk[num] = 0;
        return ;
    }
    if(re.size() > r){
        re.pop_back();
        bk[num] = 0;
        return ;       
    }

    for(int i = num+1 ; i <= n; ++i){
        if(bk[i] == 0) dfs(i);
    }

    re.pop_back();
    bk[num] = 0;

}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &n, &r);
    for(int i = 1; i <= n; i++){
        dfs(i);
    }
    // dfs(1);

    return 0;
}