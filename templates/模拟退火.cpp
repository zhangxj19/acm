#include<bits/stdc++.h>
using namespace std;

#define pdd pair<double, double>
vector<pdd> a;
const double inf = 2e6;
double ans = inf; 

double getd(pdd& x, pdd& y){
    double dx = x.first - y.first;
    double dy = x.second - y.second;
    return sqrt(dx * dx + dy * dy);
}

double getsum(pdd& x){
    double re = 0;
    for(auto& p : a){
        re += getd(x, p);
    }
    ans = min(ans, re);
    return re;
}

double rand(double l, double r){
    return (double)rand() / RAND_MAX * (r - l) + l;
}

void sa(){
    pdd p(rand(0, 1e4), rand(0, 1e4));
    for(double t = 1e4; t > 1e-4; t *= 0.9){
        pdd np(rand(p.first - t, p.first + t), rand(p.second - t, p.second + t));
        double dt = getsum(np) - getsum(p);
        #ifdef DEBUG2
        cout << ans << "\n";
        #endif
        if(exp(-dt/t) > rand(0, 1)){
            p = np;
        }
    }
}

int main(){
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    int n;
    cin >> n;
    a.resize(n);
    srand((unsigned)time(NULL));
    for(int i = 0; i < n ;++i){
        cin >> a[i].first >> a[i].second;
    }
    for(int i  =0 ; i < 100; ++i) sa();
    cout << round(ans) << "\n";
    
}