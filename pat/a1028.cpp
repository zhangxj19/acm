#include <bits/stdc++.h>

#define DEBUG

#define _U(i, a, b) for (int i = (a); i < (b); ++i)
#define _D(i, a, b) for (int i = (a); i > (b); --i)

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int N, C;

struct P{
    int id, g;
    string name;
}p[100000];

bool cmp_1(const P& p1, const P& p2){
    return p1.id < p2.id;
}
bool cmp_2(const P& p1, const P& p2){
    if(p1.name != p2.name) return p1.name < p2.name;
    else return p1.id < p2.id;
}
bool cmp_3(const P& p1, const P& p2){
    if(p1.g != p2.g) return p1.g < p2.g;
    else return p1.id < p2.id;
}
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d%d", &N, &C);
    _U(i, 0, N){
        char cname[9];
        scanf("%d %s %d", &p[i].id, cname, &p[i].g);
        string name(cname);
        p[i].name = name;
    }
    if(C == 1){
        sort(p, p+N, cmp_1);
    }
    else if(C == 2){
        sort(p, p+N, cmp_2);
    }
    else if(C == 3){
        sort(p, p+N, cmp_3);
    }
    _U(i, 0, N){
        printf("%06d %s %d\n", p[i].id, p[i].name.c_str(), p[i].g);
    }

    return 0;
}