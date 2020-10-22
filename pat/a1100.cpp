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

// mars to earth
vector<string> e2m1 = {
    "tret",
    "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
},
e2m2 = {
    "tret",
    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
}
;
map<string, int> m2e1, m2e2;

string e2m(int x){
    vector<string> vre;
    vre.push_back(e2m1[x%13]); x/=13;
    if(x) vre.push_back(e2m2[x%13]);
    reverse(vre.begin(), vre.end());
    if(vre.size() == 2 and vre[1] == "tret") vre.pop_back();
    string re;
    for(int i = 0; i < vre.size(); i++){
        re += vre[i];
        if(i != vre.size()-1) re += " ";
    }
    return re;
}

int m2e(string& x){
    int re = 0, i = x.find(" ");
    #ifdef DEBUG
    pf("x = %s and part1 = %d, part2 = %d\n", x.c_str(), m2e2[x.substr(0, i)], m2e1[x.substr(i+1, x.size()-i-1)]);
    #endif
    re = re * 13 + m2e2[x.substr(0, i)];
    re = re * 13 + m2e1[x.substr(i+1, x.size()-i-1)];
    return re;
}


int N;

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    for(int i = 0; i < e2m1.size(); i++){
        #ifdef DEBUG
        pf("e2m1[%d] = %s e2m2[%d] = %s\n", i, e2m1[i].c_str(), i , e2m2[i].c_str());
        #endif
        m2e1[e2m1[i]] = i;
        m2e2[e2m2[i]] = i;
    }
    #ifdef DEBUG
    for(const auto & it : m2e1){
        pf("%s -> %d\n", it.first.c_str(), it.second);
    }
    pf("\n");
    for(const auto & it : m2e2){
        pf("%s -> %d\n", it.first.c_str(), it.second);
    }
    pf("\n");
    #endif
    sf("%d\n", &N);
    while(N--){
        char cmd[8];
        sf("%[^\n]", cmd);
        getchar();
        #ifdef DEBUG
        pf("cmd = \"%s\"\n", cmd);
        #endif
        if(cmd[0] >= '0' and cmd[0] <= '9'){ // digit
            int num=0;
            sscanf(cmd, "%d", &num);
            pf("%s\n", e2m(num).c_str());
        }
        else{
            string scmd(cmd);
            pf("%d\n", m2e(scmd));
        }
    }

    return 0;
}