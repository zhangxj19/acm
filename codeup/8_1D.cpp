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

const int maxn = 10;

int n, a[maxn][maxn], bk[maxn][maxn], bkoblique[2][2*maxn-2], bkc[maxn]; // bk for col
bool isnosulute = true;

void getc(int x, int y, int &c1, int &c2){  
    // --------------------->y
    // |
    // |
    // |
    // |
    // |
    // |
    // v
    // x
    // c1 \
    // c2 /

    c1 = y + x; 
    c2 = y - x + n - 1; // offset = y - x = 0 - (n-1) = 1 - n
}

bool conflict(int x1, int y1, int x2, int y2){
    // row 
    // col
    if(x1 == x2 or y1 == y2) return true;

    // oblique
    double slope = (double)abs(y1 - y2) / abs(x1 - x2);  
    if(equ(slope, 1.)) return true;
    // if((abs(y1 - y2)/ abs(x1 - x2)) == 1) return true;

    #ifdef DEBUG2
    pf("(%d, %d) is ok with (%d, %d)\n", x1, y1, x2, y2);
    #endif

    return false;
}

vector<int> re;

void printre(){
    isnosulute = false;
    for(int i = 0, sizen = re.size(); i < sizen; ++i){
        pf("%d", re[i]+1);
        if(i != sizen-1) pf(" ");
    }
    pf("\n");
}

void indfs(int c1, int c2, int row, int col){
    bkoblique[0][c1] = 1;
    bkoblique[1][c2] = 1;
    bk[row][col] = 1;
    bkc[col] = 1;
    re.push_back(col);
}

void outdfs(int c1, int c2, int row, int col){
    bkoblique[0][c1] = 0;
    bkoblique[1][c2] = 0;   
    bk[row][col] = 0;
    bkc[col] = 0;
    re.pop_back();
}

void dfs(int row, int col){
    #ifdef DEBUG
    pf("detect (%d, %d)\n", row, col);
    #endif
    int c1=0, c2=0;
    getc(row, col, c1, c2);
    indfs(c1, c2, row, col);

    if(re.size() == n){
        printre();
        outdfs(c1, c2, row, col);

        return ;
    }

    for(int i = row + 1; i < n; ++i){
        int is_row_selected = false;
        for(int j = 0; j < n; ++j){
            int _c1=0, _c2=0;
            getc(i, j, c1, c2);
            bool isconflict = false;
            for(int k = 0; k <= row; ++k){
                for(int l = 0; l < n; ++l){
                    if(bk[k][l] == 1 and conflict(k, l, i, j)){
                        #ifdef DEBUG
                        pf("(%d,%d) is conflict with (%d, %d).\n", i, j, k, l);
                        #endif
                        isconflict = true;
                        break;
                    }
                }
                if(isconflict) break;
            }
            if(!isconflict){
                if(bk[i][j] == 0){
                    #ifdef DEBUG
                    pf("(%d, %d) is ok\n", i, j);
                    #endif
                    dfs(i, j);
                    is_row_selected = true;
                }
            }
            // if(bk[i][j] == 0 and bkc[j] == 0 and bkoblique[0][c1]  == 0 and bkoblique[1][c2] == 0){
            //     dfs(i, j);
            //     is_row_selected = true;
            // }
        }
        if(!is_row_selected){
            #ifdef DEBUG
            // for(int i = 0; i < n; ++i) pf("%d ", bk[i][j]);
            pf("\n");
            pf("no %d row is selected.\n", i);
            #endif
            break;
        }
    }

    #ifdef DEBUG
    pf("out at (%d, %d)\n\n", row, col);
    if(row == n-1){
        pf("!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
    #endif
    outdfs(c1, c2, row, col);
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    cin >> n;

    for(int i = 0; i < n; i++){
        dfs(0, i);
    }

    if(isnosulute){
        pf("no solute!\n");
    }

    return 0;
}