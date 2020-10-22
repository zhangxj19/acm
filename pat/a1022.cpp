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

// title, author, keywords, publisher, publishedyear
//     0       1         2          3              4
map<string, vector<string>> maps[5]; 

int N, M;

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    cin >> N; cin.get();
    uu(i, 0, N){
        string id;
        cin >> id; cin.get();
        string s[5];
        uu(j, 0, 5){
            if(j == 2){ // keywords
                string keywords, keyword;
                getline(cin, keywords);
                int beg=0, end=0;
                keywords += " ";
                while(end < keywords.size()){
                    if(keywords[end] != ' ') end++;
                    else{
                        // end at space
                        keyword = keywords.substr(beg, end-beg);
                        if(maps[j].find(keyword) == maps[j].end()) maps[j][keyword].clear();
                        maps[j][keyword].push_back(id);

                        while(keywords[end] == ' ') end++; // end at alpha;
                        beg = end;                      
                    }   
                }
            }
            else{
                getline(cin, s[j]);
                if(maps[j].find(s[j]) == maps[j].end()) maps[j][s[j]].clear();
                maps[j][s[j]].push_back(id);
            }

        }
    }
    #ifdef DEBUG
    uu(i, 0, 5){
        cout << "======" << endl;
        for(const auto& it : maps[i]){
            cout << it.first << " : ";
            for(const auto & it2 : it.second){
                cout << it2 << " "; 
            }
            cout << endl;
        }
        cout << "!!!!!!" << endl;
    }
    #endif
    cin >> M; cin.get();
    uu(i, 0, M){
        string cmd, content;
        getline(cin, cmd); content = cmd.substr(3, cmd.size()-3);
        cout << cmd << endl;
        int idx = cmd[0] - '0' - 1;
        if(maps[idx].find(content) != maps[idx].end()){
            sort(maps[idx][content].begin(), maps[idx][content].end());
            for(const auto& it : maps[idx][content]){
                cout << it << endl;
            }
        }
        else{
            cout << "Not Found" << endl;
        }
        
    }
    return 0;
}