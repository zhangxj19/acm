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

struct P{
    string name, id;
    int g;
};

int N, g1, g2;

vector<P> v;
bool InRange(const P& p){
    if(g1 <= p.g and p.g <= g2) return true;
    else return false; 
}

bool cmp(const P& p1, const P& p2){
    if(InRange(p1) and InRange(p2)){
        return p1.g > p2.g;
    }
    else if(InRange(p1) and !InRange(p2)) return true;
    else if(!InRange(p1) and InRange(p2)) return false;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> N;
    _U(i, 0, N){
        P p;
        cin >> p.name >> p.id >> p.g;
        v.push_back(p);
    }
    cin >> g1 >> g2;
    sort(v.begin(), v.end(), cmp);
    int i = 0;
    bool isprint=false;
    while(InRange(v[i])){
        cout << v[i].name << " " << v[i].id << endl;
        isprint = true;
        i++;
    }
    if(!isprint){
        cout << "NONE" << endl;
    }




    return 0;
}