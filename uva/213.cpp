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

// const char * bin[] = {
//     "0",
//     "00",
//     "01",
//     "10",
//     "000",
//     "001",
//     "010",
//     "011",
//     "100",
//     "101",
//     "110",
// };
vector<string> bin;

int val(string s){
    int re = 0;
    each(c, s){
        re *= 2;
        if(c == '1'){
            re += 1;
        }
    }
    return re;
}

void add_one(string &code){
    // code != "11..1"
    int i = code.size()-1;
    while(1){
        if(code[i] == '0'){
            code[i] = '1';
            break;
        }
        else{
            code[i] = '0';
            i -= 1;
        }
    }
}

int all1(string &code){
    each(c, code){
        if(c == '0') return false;
    }
    return true;
}

void next_code(string &code){
    add_one(code);
    if(all1(code)){
        int newsize = code.size() + 1;
        code = "";
        rep(i, newsize) code.append("0");
    }
}

void make_bin(){
    string code = "0";
    while(code.size() < 8){
        bin.push_back(code);
        next_code(code);
    }
}

string readline(){
    string re;
    char ch;
    for(;;){
        ch = getchar();
        if(ch == '\n' or ch == '\r') break;
        else re += ch;
    }
    return re;
}

void solve(){
    make_bin();
    string head;
    // while(getline(cin, head) and head != ""){
    while(1){
        head = readline();
        if(head == "") break;
        string s, tmp;
        do{
            // cin >> tmp;
            // cin.ignore(256, '\n');
            // getline(cin, tmp);
            tmp = readline();
            s += tmp;
            if(tmp.size() < 3) continue;
            if(tmp.substr(tmp.size()-3, 3) == "000"){
                break;
            }
        }while(1);

        
        map<string, char> mp;
        int cnt = 0;
        // string code = "0";
        each(c, head){
            mp[bin[cnt]] = c;
            // mp[code] = c;
            // next_code(code);
            cnt++;
        }

        string re;
        int r = 0;
        while(r < s.size()){
            int len = val(s.substr(r, 3));
            if(len == 0) break;
            r += 3;
            do{
                string sub = s.substr(r, len);
                r += len;
                string END;
                rep(i, len) END.append("1");
                if(sub == END) break;
                // re += mp[sub];
                putchar(mp[sub]);
            }while(1);
        }
        putchar('\n');
        // cout << re << endl;


    }
}

int main(){
    // #ifndef DEBUG
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // #endif
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