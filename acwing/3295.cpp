// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
// 求高部分使用海伦-秦九韶公式精度才可达标
// 普通求高h = ao * sqrt(1-cosa*cosa)极端情况（A、O、B几乎在一条直线上）
// cosA趋近于1、1-cosa*cosa趋近于0，开方后精度不足

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
#include <set>
#include <string>
#include <vector>
#include <cmath>

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
const int maxn = 1e2+1, maxm = 2e3+1;
int n, m;
double r;

struct P{
    double d[maxn];
    double po;
}black, p[maxm];


double line_dis(P& p1, P& p2){
    double re = 0;
    uu(i, 0, n){
        re += pow(p1.d[i] - p2.d[i], 2);
    }

    return sqrt(re);
}

double cur_dis(P& a, P& b){
    double ao = a.po, bo = b.po, ab = line_dis(a, b);
    double cosa = (ab*ab + ao*ao - bo * bo) / (2*ab*ao);
    double cosb = (ab*ab + bo*bo - ao * ao) / (2*ab*bo);
    double p = (ao+bo+ab)/2;
    double s = sqrt(p*(p-ao)*(p-bo)*(p-ab));
    // double h = ao * sqrt(1-cosa*cosa);
    double h = 2 * s / ab;

    if(cosa < 0 or cosb < 0){
        return ab;
    }
    else{
        if(h < r){
            double ae = sqrt(ao*ao - r*r), bf = sqrt(bo*bo - r*r);
            double coso = (ao*ao + bo*bo - ab*ab) / (2*ao*bo);
            double cose = r / ao, cosf = r / bo;
            double ef = (acos(coso) - acos(cose) - acos(cosf)) * r;
            return ae + bf + ef;
        }
        else{
            return ab;
        }

    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("o", "w", stdout);
    #endif
    cout << setiosflags(ios::fixed);
    cout << setprecision(14);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    
    cin >> n >> m >> r;
    uu(i, 0, n){
        cin >> black.d[i];
    }
    uu(i, 0, m){
        uu(j, 0, n){
            cin >> p[i].d[j];
        }
        p[i].po = line_dis(p[i], black);
    }

    vector<double> re(m, 0);

    uu(i, 0, m){
        uu(j, i, m){
            double dis = cur_dis(p[i], p[j]);

            re[i] += dis;
            re[j] += dis;
        }
    }

    uu(i, 0, re.size()){
        cout << re[i] << endl;
    }

    return 0;
}