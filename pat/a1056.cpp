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

int np, ng, rk[1000];

vector<int> w, id, q;

vector<int> findMaxWt(int l, int r){
    // id[l, r)
    int maxwt = -1;
    vector<int> re;
    for(int i = l; i < r; i++){
        if(w[id[i]] > maxwt){
            maxwt = w[id[i]];
            re.clear();
            re.push_back(id[i]);
        }
        else if(w[id[i]] == maxwt){
            re.push_back(id[i]);
        }
    }
    return re;
}

bool isSame(vector<int>& id){
    for(int i = 1; i < id.size(); i++){
        if(w[id[i]] != w[id[i-1]]) return false;
    }
    return true;
}

bool inMaxId(vector<int>& maxid, int x){
    for(const auto& it : maxid){
        if(it == x) return true;
    }
    return false;
}


struct Node{
    int id, score, rk;
};

bool cmpscore(const Node& p1, const Node& p2){
    return p1.score < p2.score;
}

bool cmpid(const Node& p1, const Node& p2){
    return p1.id < p2.id;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    cin >> np >> ng;
    w.resize(np);
    id.resize(np);
    uu(i, 0, np){
        cin >> w[i];
    }
    uu(i, 0, np){
        cin >> id[i];
    }
    #ifdef DEBUG
    for(const auto & it : w){
        pf("%d ", it);
    }
    pf("\n");
    for(const auto & it : id){
        pf("%d ", it);
    }
    pf("\n");
    #endif
    int rank = np;
    while(!id.empty()){
        #ifdef DEBUG
        pf("=============\nids now is: ");
        for(const auto& it : id){
            cout << it << " ";
        }
        cout << endl;
        #endif
        q.clear();
        for(int i = 0; i < id.size(); i += ng){
            vector<int> maxid = findMaxWt(i, _min(i+ng, id.size()));
            #ifdef DEBUG
            pf("maxid now is: ");
            for(const auto& it : maxid){
                cout << it << " ";
            }
            cout << endl;
            #endif
            if(id.size() <= ng and isSame(id)){
                for(int j = i, upb=_min(i+ng, id.size()); j < upb; j++){
                    rk[id[j]] = rank;
                }              
            }
            else{
                for(int j = i, upb=_min(i+ng, id.size()); j < upb; j++){
                    if(!inMaxId(maxid, id[j])){
                        // q.push_back(id[j]);
                        rk[id[j]] = rank;
                    }
                    else{
                        q.push_back(id[j]);
                    }
                }
            }

            #ifdef DEBUG
            pf("q now is: ");
            for(const auto& it : q){
                cout << it << " ";
            }
            cout << endl;
            #endif
        }
        id = q;
        rank--;
        #ifdef DEBUG
        pf("rk now is: ");
        for(int i = 0; i < np; i++){
            cout << rk[i] << " ";
        }
        cout << endl;
        #endif        
    }
    vector<Node> torank; // <id, score> small is better;
    for(int i = 0; i < np; i++){
        Node tmp;
        tmp.id = i; tmp.score = rk[i];
        torank.push_back(tmp);
    }
    sort(torank.begin(), torank.end(), cmpscore);
    torank[0].rk = 1;
    for(int i = 1; i < np; i++){
        if(torank[i].score == torank[i-1].score){
            torank[i].rk = torank[i-1].rk;
        }
        else{
            torank[i].rk = i+1;
        }
    }
    sort(torank.begin(), torank.end(), cmpid);
    for(int i = 0; i < np; i++){
        cout << torank[i].rk;
        if(i != np-1) cout << " ";
    }
    cout << endl;
    
    return 0;
}