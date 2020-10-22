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
const int maxm = 1286, maxn = 128, maxl = 60;

int M, N, L, T, a[maxm][maxn][maxl], bk[maxm][maxn][maxl], vol, dir[6][3] = {
    // front back up down left rigth
    //         _  
    //       /_/|
    //      /_/|/
    //      |_|/ 
    //
    { 0,  0,  1},
    { 0,  0, -1},
    {-1,  0,  0},
    { 1,  0,  0},
    { 0, -1,  0},
    { 0,  1,  0},
};

struct Node{
    int x,y,z;
    Node(int x, int y, int z):x(x), y(y), z(z){};
};

void bfs(int x, int y, int z){
    // a[x][y][z] == 1 and bk[x][y][z] == 0
    #ifdef DEBUG
    pf("###############################\n");
    pf("detect a new region at %d %d %d\n", x, y, z);
    #endif
    queue<Node> Q;
    Q.push(Node(x, y, z));
    bk[x][y][z] = 1;
    int v = 1;
    while(!Q.empty()){
        Node n = Q.front(); Q.pop();
        for(int d = 0; d < 6; d++){
            Node newn(n.x + dir[d][0], n.y + dir[d][1], n.z + dir[d][2]);
            if(0 <= newn.x and newn.x < M and 0 <= newn.y and newn.y < N and 0 <= newn.z and newn.z < L and bk[newn.x][newn.y][newn.z] == 0 and a[newn.x][newn.y][newn.z] == 1){
                Q.push(newn);
                bk[newn.x][newn.y][newn.z] = 1;
                #ifdef DEBUG
                pf("step at %d %d %d\n", newn.x, newn.y, newn.z);
                #endif
                v++;
            }
        }
    }
    #ifdef DEBUG
    pf("this region has %d stroke\n", v);
    pf("!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    #endif
    if(v >= T) vol += v;
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d%d%d\n", &M, &N, &L, &T);
    uu(i, 0, L){
        uu(j, 0, M){
            uu(k, 0, N){
                sf("%d", &a[j][k][i]);
            }
        }
    }

    uu(i, 0, L){
        uu(j, 0, M){
            uu(k, 0, N){
                if(bk[j][k][i] == 0 and a[j][k][i] == 1) bfs(j, k, i);
            }
        }
    }

    pf("%d\n", vol);



    return 0;
}