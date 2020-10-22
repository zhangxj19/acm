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

const int maxn = 15;

int a[maxn][maxn], bk[maxn][maxn],
    dir[4][2]{
        {0, -1},
        {-1, 0},
        {0, 1},
        {1, 0},
    }, n, m, sx, sy, ex, ey, havesolution=0;

vector<pair<int, int>> re;

void printre(){
    havesolution = 1;
    for(int i = 0; i < re.size(); i++){
        if(i == 0){
            pf("(%d,%d)", re[i].first+1, re[i].second+1);
        }
        else{
            pf("->(%d,%d)", re[i].first+1, re[i].second+1);
        }
    }
    pf("\n");
}

bool havepath(int x, int y){
    // [x, y] -> [nx-1, ny-1]

    for(int i = 0; i <= ex-1; ++i){
        bool allzero = true;
        for(int j = 0; j <= ey-1; ++j){
            if(a[i][j] == 1) allzero = false;
        }
        if(allzero) return false;
    }
    return true;
}

void dfs(int x, int y){
    #ifdef DEBUG2
    pf("detect at (%d, %d)\n", x, y);
    #endif
    re.push_back(make_pair(x, y));
    bk[x][y] = 1;

    if(x == ex-1 and y == ey-1){
        printre();
        re.pop_back();
        bk[x][y] = 0;
        return ;
    }

    for(int i = 0; i < 4; ++i){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        #ifdef DEBUG2
        pf("testing (%d, %d)\n", nx, ny);
        #endif
        // if(0 <= nx and nx < n and 0 <= ny and ny < m and bk[nx][ny] == 0 and a[nx][ny] == 1 and havepath(nx, ny)){
        if(0 <= nx and nx < n and 0 <= ny and ny < m and bk[nx][ny] == 0 and a[nx][ny] == 1){
            dfs(nx, ny);
        }
    }

    re.pop_back();
    bk[x][y] = 0;
}


int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &n, &m);
    uu(i, 0, n){
        uu(j, 0, m){
            sf("%d", &a[i][j]);
        }
    }
    sf("%d%d%d%d", &sx, &sy, &ex, &ey);

    // if(havepath(sx-1, sy-1))
    dfs(sx-1, sy-1);

    if(!havesolution) pf("-1\n");


    return 0;
}