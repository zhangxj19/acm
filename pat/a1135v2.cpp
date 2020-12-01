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
#define lowbit(x) (x&(-x))

using namespace std;
const int maxn = 1e5+1;

int head, N, K;

struct Node{
    int d, ad, n;
}node[maxn];

vector<Node> a;

bool cmp(Node& n1, Node& n2){
    if(n1.d < 0){
        if(n2.d < 0) return false;
        if(n2.d >=0) return true;
    }
    else if(n1.d >= 0 and n1.d <= K){
        if(n2.d < 0) return true;
        if(n2.d >= 0 and n2.d <= K) return false;
        return true;
    }
    else{
        if(n2.d >= K) return false;
        else return true;
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
    // cout << setw(5) << setfill('0');  // add this every time when cout int with width and left padding '0'
    cin >> head >> N >> K;

    uu(i, 0, N){
        int ad;
        cin >> ad;
        cin >> node[ad].d >> node[ad].n;

    }

    int tmp = head;
    while(tmp != -1){
        node[tmp].ad = tmp;
        a.push_back(node[tmp]);
        tmp = node[tmp].n;
    }
    vector<Node> A, B, C;
    for(auto& it: a){
        if(it.d < 0) A.push_back(it);
        else if(it.d >= 0 and it.d <= K) B.push_back(it);
        else C.push_back(it);
    }
    // sort(a.begin(), a.end(), cmp);
    a.clear();
    for(auto & it: A) a.push_back(it);
    for(auto & it: B) a.push_back(it);
    for(auto & it: C) a.push_back(it);
    // negtive number 
    // int cnt = 0;
    // for(int i = a.size()-1, lb = -1; i > lb;){
    //     if(a[i].d < 0){
    //         Node n;
    //         n.ad = a[i].ad;
    //         n.d = a[i].d;
    //         a.erase(a.begin()+i);
    //         a.insert(a.begin(), n);
    //         lb += 1;
    //         cnt++;
    //     }
    //     else{
    //         i--;
    //     }
    // }

    // // [0, K]
    // for(int i = a.size()-1, lb = cnt-1; i > lb;){
    //     if(0 <= a[i].d and a[i].d <= K){
    //         Node n;
    //         n.ad = a[i].ad;
    //         n.d = a[i].d;
    //         a.erase(a.begin()+i);
    //         a.insert(a.begin()+cnt, n);
    //         lb += 1;          
    //     }
    //     else{
    //         i--;
    //     }
    // }

    uu(i, 0, a.size()-1){
        a[i].n = a[i+1].ad;
    }
    a[a.size()-1].n = -1;


    uu(i , 0, a.size()){
        cout << setw(5) << setfill('0') << a[i].ad << " " << a[i].d << " ";
        if(a[i].n == -1) cout << -1 << endl;
        else cout << setw(5) << setfill('0') << a[i].n << endl;
    }




    return 0;
}