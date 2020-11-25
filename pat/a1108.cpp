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

using namespace std;

const int maxn = 101;;
int N, k;
string s1, s2;
double sum, num;
char cs[100];


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("o", "w", stdout);
    #endif
    cout << setiosflags(ios::fixed);
    cout << setprecision(2);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    cin >> N;
    uu(i, 0, N){
        cin >> s1;
        sscanf(s1.c_str(), "%lf", &num);
        sprintf(cs, "%.2f", num);
        s2 = cs;
        bool islegal = true;
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] != s2[i]) islegal = false;
        }
        
        if(!islegal or num > 1000 or num < -1000){
            cout << "ERROR: " << s1 << " is not a legal number"  << endl;
        }
        else{
            k++;
            sum += num;
        }
    }
    if(k == 0){
        cout << "The average of 0 numbers is Undefined" << endl;
    }
    else if(k == 1){
        cout << "The average of 1 number is " << sum << endl;
    }
    else{
        cout << "The average of "<< k << " numbers is " << sum / k << endl;
    }
    
    return 0;
}   