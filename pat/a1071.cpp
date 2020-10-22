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

char cs[1048577];
string s;

bool isAlphaNumerical(char x){
    if((x >= '0' and x <= '9') or (x >= 'a' and x <= 'z') or (x >= 'A' and x <= 'Z')) return true;
    else return false;
}

map<string, int> m;

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%[^\n]", cs); 
    for(int i = 0, nsize = strlen(cs); i < nsize; i++){
        if(cs[i] >= 'A' and cs[i] <= 'Z') cs[i] = tolower(cs[i]);
    }
    s = cs;
    int beg=0, end=0;
    #ifdef DEBUG
    pf("s=\"%s\", size of s is %d\n", s.c_str(), (int)s.size());
    #endif
    while(end < s.size()){
        #ifdef DEBUG
        pf("(beg, end) = (%d, %d) s=\"%s\"\n", beg, end, s.substr(beg, end-beg).c_str());
        #endif
        if(isAlphaNumerical(s[end])) end++;
        else{
            // end at non-alpha-numerical, [beg, end)
            string tmp = s.substr(beg, end-beg);
            if(m.find(tmp) == m.end()) m[tmp] = 0;
            m[tmp]++;

            while(!isAlphaNumerical(s[end])) end++;
            // end at alpha-numerical
            beg = end;
        }
    }
    if(isAlphaNumerical(s[end-1])){ // incase a word at the end of string, the "end" == s.size() s[beg, end) should be packed.
        string tmp = s.substr(beg, end-beg);
        if(m.find(tmp) == m.end()) m[tmp] = 0;
        m[tmp]++;        
    }
    #ifdef DEBUG
    for(const auto& it : m){
        pf("\"%s\" : %d\n", it.first.c_str(), it.second);
    }    
    #endif
    int maxn = -1;
    string maxs;
    for(const auto& it : m){
        if(it.second > maxn){
             maxn = it.second;
             maxs = it.first;
        }
    }
    pf("%s %d\n", maxs.c_str(), maxn);

    return 0;
}