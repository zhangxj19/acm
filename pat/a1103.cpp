// #include <bits/stdc++.h>
/*
DFS搜索为了保证答案的字典序，选择从大到小搜索节点；
注意点：
1.赋值：每位和大于全局变量后赋值答案（已保证字典序最大）
2.减枝：和大于目标 或者 因子数大于K
*/
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
// #define DEBUG2

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
const int maxn = 400;

int N, K, P, fac[maxn]={0}, sizef; // 1 < P <= 7

int maxsum=-1;
vector<int> re, ans;
// vector<vector<int>> ans;

bool cmp(const int &i1, const int &i2){
    return i1 > i2;
}

bool cmp2(const vector<int>& v1, const vector<int>& v2){
    // v1.size() == v2.size()
    for(int i = 0, n = v1.size(); i < n; ++i){
        if(v1[i] != v2[i]) return v1[i] > v2[i];
    }
    return false;
}

void dfs(int sum, int sumFac, int idx){
    #ifdef DEBUG2
    pf("sum = %d, sumFac = %d, idx = %d, re.size()=%d\n", sum, sumFac, idx, (int)re.size());
    #endif
    if(re.size() == K and sum == N){
        // if(sumFac >= maxsum){
        //     if(sumFac > maxsum){
        //         ans.clear();
        //     }
        //     maxsum = sumFac;
        //     #ifdef DEBUG2
        //     pf("get a re.\n");
        //     #endif
        //     sort(re.begin(), re.end(), cmp);
        //     ans.push_back(re);
        // }
        if(sumFac > maxsum){
            maxsum = sumFac;
            // ans.push_back(re);
            ans = re;
        }
        return;
    }

    if(sum > N or re.size() > K) return ;
    if(idx - 1 >= 0){
        re.push_back(idx);
        dfs(sum + fac[idx], sumFac + idx, idx);
        re.pop_back();        

        dfs(sum, sumFac, idx-1);

    }
    // int nxt = idx;
    // // while(nxt > 0 and fac[nxt] <= sum){
    // while(nxt < sizef and fac[nxt] <= sum){
    //     re.push_back(nxt);
    //     dfs(sum - fac[nxt], sumFac + nxt, nxt);
    //     re.pop_back();
    //     nxt++;
    // }
    return;
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d%d\n", &N, &K, &P);

    for(sizef = 0; (int)pow(sizef, P) <= N; sizef++){
        fac[sizef] = (int)pow(sizef, P);
    }
    #ifdef DEBUG
    pf("sizef=%d\n", sizef);
    for(int i = 0; i < sizef; i++){
        pf("(%d, %d) ", i, fac[i]);
    }
    pf("\n");
    #endif

    // dfs(N, 0, sizef-1);
    dfs(0, 0, sizef-1);
    // sort(ans.begin(), ans.end(), cmp2);

    #ifdef DEBUG
    pf("ans.size()=%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            pf("%d", ans[i][j]);
            if(j != ans[i].size()-1) pf("+");
        }
        pf("(%d)\n", P);
    }
    #endif

    // if(ans.size()){
    if(maxsum != -1){
        pf("%d = ", N);
        for(int j = 0, sizen = ans.size(); j < sizen; j++){
            pf("%d^%d", ans[j], P);
            if(j != ans.size()-1) pf(" + ");
        }
        pf("\n");
    }
    else{
        pf("Impossible\n");
    }


    return 0;
}