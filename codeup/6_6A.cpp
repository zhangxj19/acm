// #include <bits/stdc++.h>
// 2 options:
// 1) cin cout 
// 2) scanf printf
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

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
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

const int maxn = 1e5;

int n, ind[maxn], bk[maxn]; // indegree

struct Node{
    int d;
    vector<int> nei;
}node[maxn];

string s;

int findNext0Indegree(){
    uu(i, 0, n){
        if(bk[i] == 0 and ind[i] == 0){
            bk[i] = 1;
            return i;
        }
    }
    return -1;
}


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);

    cin >> n;
    uu(i, 0, n){
        cin >> s;
        #ifdef DEBUG
        cout << s << endl;
        #endif
        int idx_l = s.find('(');
        int id;
        sscanf(s.substr(0, idx_l).c_str(), "Task%d", &id);
        int idx_r = s.find(')');
        if(s[idx_r-1] == 'L'){ // NULL
            continue;
        }
        else{
            int idx_comma = s.find(','), nei = 0;
            while(idx_comma != string::npos){
                sscanf(s.substr(idx_l+1, idx_comma-1-idx_l).c_str(), "Task%d", &nei);
                node[id].nei.push_back(nei);
                s.replace(s.begin() + idx_l+1, s.begin()+ idx_comma+1, "");
                idx_comma = s.find(',');
            }
            sscanf(s.substr(idx_l+1, idx_r-1-idx_l).c_str(), "Task%d", &nei);
            node[id].nei.push_back(nei);
        }
    }


    #ifdef DEBUG
    uu(i, 0, n){
        pf("Task%d: ", i);
        uu(j, 0, node[i].nei.size()){
            pf("%d ", node[i].nei[j]);
        }
        pf("\n");
    }
    #endif

    // topo sort;

    uu(i, 0, n){
        // sort(node[i].nei.begin(), node[i].nei.end());
        uu(j, 0, node[i].nei.size()){
            int nei = node[i].nei[j];
            ind[nei]++;
        }
    }

    int next = findNext0Indegree();
    vector<int> re;
    while(next != -1){
        re.push_back(next);

        uu(i, 0, node[next].nei.size()){
            int nei = node[next].nei[i];
            ind[nei]--;
        }

        next= findNext0Indegree();
    }
    uu(i, 0, re.size()){
        if(i == 0) cout << "Task" << i;
        else cout << " Task" << i;
    }
    cout << endl;




    return 0;
}