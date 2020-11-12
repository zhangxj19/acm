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
#define lowbit(x) (x&(-x));

// #define DEBUG

using namespace std;

const int maxn = 1e4+1, maxk = 101;
int N, K, q[maxk];


int second(int h, int m , int s){
    return h*3600 + m * 60 + s;
}

int serve_beg, serve_end;

struct Node{
    int beg, c;
}node[maxn];

bool cmp(const Node &n1, const Node &n2){
    return n1.beg < n2.beg;
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    cout << setiosflags(ios::fixed);
    cout << setprecision(1);

    cin >> N >> K;
    serve_beg = second(8, 0, 0);
    serve_end = second(17, 0, 0);

    int cnt = 0;
    uu(i, 0, N){
        int h, m, s, process_time;
        char c;
        cin >> h >> c >> m >> c >> s;
        cin >> process_time;
        int arrive_time = second(h, m, s);


        if(arrive_time <= serve_end){
            node[cnt].beg = arrive_time;
            node[cnt].c = _min(process_time * 60, 3600);
            cnt++;
        }

    }

    N = cnt;
    sort(node, node+N, cmp);

    #ifdef DEBUG
    uu(i, 0, N){
        pf("(%d, %d)", node[i].beg, node[i].c);
    }
    #endif

    uu(i, 0, K){
        q[i] = serve_beg;
    }

    int sum = 0; // sum of wait time;
    uu(i, 0, N){
        // customers arrived before 17:00 must be served finally. So 
        // the minbeg should be INF but not 17:00
        int minbeg=INT_MAX, minidx=-1; 
        uu(j, 0, K) if(q[j] < minbeg) minbeg = q[minidx=j];

        // add wait time
        if(q[minidx] <= node[i].beg){
            q[minidx] = node[i].beg + node[i].c;
        }
        else{
            sum += q[minidx] - node[i].beg;
            q[minidx] += node[i].c;
        }
        
    }

    if(sum == 0){
        cout << 0.0 << endl;
    }
    else{
        cout << sum / 60.0 / N << endl;
    }
    
    return 0;
}