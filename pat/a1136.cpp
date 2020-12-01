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
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(std::vector<int> &v){
    uu(i, 0, v.size()){
        if(i == 0) std::cout << v[i];
        else std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

using namespace std;

string s;

struct Int{
    string x;
    Int(string &s){
        x = s;
        reverse(x.begin(), x.end());
    } 

    Int(const Int &i){
        x = i.x;
    } 

    Int(){
        x = "";
    }

    string print(){
        string re = x;
        reverse(re.begin(), re.end());
        return re;
    }
};

Int add(Int &i1, Int &i2){
    Int re;
    int l1 = i1.x.size(), l2 = i2.x.size();
    int c = 0, i = 0;
    for(int size = _min(l1, l2); i < size; ++i){
        int sum = i1.x[i] - '0' + i2.x[i] - '0' + c;
        c = 0;
        if(sum >= 10){
            sum -= 10;
            c++;
        }
        re.x.append(to_string(sum));
    }
    if(i < l1){
        int sum = i1.x[i] - '0' + c;
        c = 0;
        if(sum >= 10){
            sum -= 10;
            c++;
        }
        re.x.append(to_string(sum));
        i++;      
    }

    if(i < l2){
        int sum = i2.x[i] - '0' + c;
        c = 0;
        if(sum >= 10){
            sum -= 10;
            c++;
        }
        re.x.append(to_string(sum));
        i++;      
    }

    if(c > 0){
        int sum = c;
        re.x.append(to_string(c));
    }

    return re;
}

int ispali(Int &x){
    int i = 0, j = x.x.size()-1;
    while(i < j){
        if(x.x[i] != x.x[j]) return false;
        i++;
        j--;
    }
    return true;
}

Int reverse(Int &x){
    Int re(x.x);
    return re;
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
    cin >> s;
    Int a(s);
    
    #ifdef DEBUG
    cout << s <<endl;
    Int b = add(a, a);
    cout << b.print() << endl;
    #endif

    int cnt = 0;

    while(cnt < 10 and !ispali(a)){
        Int b = reverse(a);
        cout << a.print() << " + " ;
        a = add(a, b);
        cout <<  b.print() << " = " << a.print() << endl;
        cnt++;
    }

    if(ispali(a)){
        cout << a.print() << " is a palindromic number." << endl;
    }
    else{
        cout << "Not found in 10 iterations." << endl;
    }

    
    return 0;
}