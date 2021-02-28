// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int n;
int islegal(string &S, int idx, char c) {
    if(n < 3 or idx <= 1) return 1;
    if(S[idx-2] == S[idx-1] and S[idx-1] == c) return 0;
    return 1;
}
string re;

void dfs(string &S, int idx) {
    if(idx == n) {
        re = S;
        return ;
    }

    if(S[idx] != '?') {
        if(!islegal(S, idx, S[idx])) return ;
        else dfs(S, idx + 1);
    }
    else {
        for(char c = 'a'; c <= 'b'; ++c) {
            if(islegal(S, idx, c)) {
                // put c at idx
                S[idx] = c;
                dfs(S, idx + 1);
                S[idx] = '?';
            }
        }
    }
}

string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    n = S.size();

    dfs(S, 0);

    return re;
}


#define int long long

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string x;
    cin >> x;
    cout << solution(x) << "\n";
    
}