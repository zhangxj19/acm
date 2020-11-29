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

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define uuit(i, a) for (auto it = (a.begin()); i != (a.end()); ++i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}
#define lowbit(x) (x&(-x))

using namespace std;

// const int maxn = 501;
// int mp[maxn][maxn];

int N, M;

vector<int> degree;
vector<vector<int>> mp;


int alleven(vector<int> &v){
    uuit(it, v){
        if(*it % 2 != 0) return false;
    }
    return true;
}

int _2odd(vector<int> &v){
    int cnt = 0;
    uuit(it, v){
        if(*it % 2 == 1) cnt++;
    }
    return cnt == 2;
}

#define pii pair<int, int>
set<pii> S;

int isconnected(){
    set<int> Set;
    queue<int> Q;
    Set.insert(0);
    Q.push(0);
    while(!Q.empty()){
        int from = Q.front(); Q.pop();

        uu(to, 0, N){
            if(mp[from][to] == 1 and Set.find(to) == Set.end()){
                Set.insert(to);
                Q.push(to);
            }
        }
    }
    return Set.size() == N;
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
    cin >> N >> M;
    degree.resize(N, 0);
    mp.resize(N, vector<int>(N, 0));

    uu(i, 0, M){
        int x, y;
        cin >> x >> y;
        x--; y--;

        degree[x]++;
        degree[y]++;
            
        mp[x][y] = 1;
        mp[y][x] = 1;

    }   

    uu(i, 0, degree.size()){
        if(i == 0) cout << degree[i];
        else cout << " " << degree[i];
    }
    cout << endl;

    bool isc = isconnected();
    if(alleven(degree) and isc){
        cout << "Eulerian" << endl;
    }
    else if(_2odd(degree) and isc){
        cout << "Semi-Eulerian" << endl;
    }
    else{
        cout << "Non-Eulerian" << endl;
    }
    
    return 0;
}