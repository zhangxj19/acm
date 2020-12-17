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

#define rep(i, n) for (int i = 0, size = (n); i < size; ++i)
#define repu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define repd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define each(it, a) for(auto & (it) : (a))
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define lowbit(x) (x&(-x))
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(vi &v){
    rep(i, v.size()){
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

const int maxn = 10, maxm = 9;

int n, bx, by;
char mp[maxn][maxm], eat[maxn][maxm];

struct Node{
    char c;
    int x,y;
};
vector<Node> node;

int horse_step[8][2] = {
    {-2, -1},
    {-2,  1},
    {-1,  2},
    { 1,  2},
    { 2,  1},
    { 2, -1},
    { 1, -2},
    {-1, -2},
};

int handicap[8][2] = {
    {-1, 0},
    {-1, 0},
    { 0, 1},
    { 0, 1},
    { 1, 0},
    { 1, 0},
    { 0,-1},
    { 0,-1},
};

int onestep_derection[4][2] = {
    {-1, 0},
    { 0, 1},
    { 1, 0},
    { 0,-1},
};


int inmap(int x, int y){
    return -1 < x and x < maxn and -1 < y and y < maxm;
}

int inmap_general(int x, int y){
    return 3 <= y and y <= 5 and 0 <= x and x <= 2; 
}

int iswin(int x, int y){
    rep(i, 4){
        int newx = x + onestep_derection[i][0], newy = y + onestep_derection[i][1];
        if(inmap_general(newx, newy) and (eat[newx][newy] == 0)){
            return false;
        }
    }
    return true;
}


int isblank(int x, int y){
    return mp[x][y] == 0 or mp[x][y] == 'x';
}

void fuckup(int rx, int ry){
    int x, y;
    repd(i, rx-1, -1){
        x = i; y = ry;
        if(isblank(x, y)){
            mp[x][y] = 'x';
            eat[x][y] = 'x';
        }
        else{
            eat[x][y] = 'x';
            break;
        }
    }    
}

void fuckdown(int rx, int ry){
    int x, y;
    repu(i, rx+1, maxn){
        x = i; y = ry;
        if(isblank(x, y)){
            mp[x][y] = 'x';
            eat[x][y] = 'x';
        }
        else{
            eat[x][y] = 'x';
            break;
        }
    }    
}

void fuckleft(int rx, int ry){
    int x, y;
    repd(i, ry-1, -1){
        x = rx; y = i;
        if(isblank(x, y)){
            mp[x][y] = 'x';
            eat[x][y] = 'x';
        }
        else{
            eat[x][y] = 'x';
            break;
        }
    } 
}

void fuckright(int rx, int ry){
    int x, y;
    repu(i, ry+1, maxm){
        x = rx; y = i;
        if(isblank(x, y)){
            mp[x][y] = 'x';
            eat[x][y] = 'x';
        }
        else{
            eat[x][y] = 'x';
            break;
        }
    }  
}



void solve(){

    while(cin >> n >> bx >> by, !(n == 0 and bx == 0 and by == 0)){
        bx--;
        by--;
        memset(mp, 0, sizeof(mp));
        memset(eat, 0, sizeof(eat));
        node.clear();
        rep(i, n){
            Node r;
            cin >> r.c >> r.x >> r.y;
            r.x--;
            r.y--;
            mp[r.x][r.y] = r.c;
            node.push_back(r);
        }
        each(e, node){
            if(e.c == 'R'){
                fuckup(e.x, e.y);
                fuckdown(e.x, e.y);
                fuckleft(e.x, e.y);
                fuckright(e.x, e.y);
            }
            else if(e.c == 'G'){
                fuckup(e.x, e.y);             
            }
            else if(e.c == 'H'){
                rep(i, 8){
                    int newx = horse_step[i][0] + e.x, newy = horse_step[i][1] + e.y;
                    int hx = handicap[i][0] + e.x, hy = handicap[i][1] + e.y;
                    if(inmap(newx, newy) and isblank(hx, hy)){
                        if(isblank(newx, newy)){
                            mp[newx][newy] = 'x';
                            eat[newx][newy] = 'x';
                        }
                        else
                            eat[newx][newy] = 'x';
                    }

                }
            }
            else if(e.c == 'C'){
                int x, y;
                int gox, goy;
                // up
                repd(i, e.x-1, -1){
                    gox = i; goy = e.y;
                    if(!isblank(gox, goy)){
                        // gox -= 1;
                        break;
                    }
                }
                fuckup(gox, goy);

                repu(i, e.x+1, maxn){
                    gox = i; goy = e.y;
                    if(!isblank(gox, goy)){
                        // gox += 1;
                        break;
                    }
                }
                fuckdown(gox, goy);

                repd(i, e.y-1, -1){
                    gox = e.x; goy = i;
                    if(!isblank(gox, goy)){
                        // goy -= 1;
                        break;
                    }
                }
                fuckleft(gox, goy);

                repu(i, e.y+1, maxm){
                    gox = e.x; goy = i;
                    if(!isblank(gox, goy)){
                        // goy += 1;
                        break;
                    }
                }

                fuckright(gox, goy);
            }
        }
        if(iswin(bx, by)) cout << "YES" << endl;
        else cout << "NO" << endl; 
        


    }    
}

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
    solve();
    
    return 0;
}