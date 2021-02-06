#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<double>> a;
const double inf = 1e12;
double ans = inf;
vector<double> ansv;

double rand(double l, double r){
    return (double) rand() / RAND_MAX * (r - l) + l;
}

double getd(vector<double>& x, vector<double>& y){
    double re  = 0;
    for(int i = 0 ; i< n; ++i){
        double d = x[i] - y[i];
        re += d * d;
    }
    return sqrt(re);
}

double getc(vector<double>& x){
    vector<double> r;
    double mind = 1e9, maxd = 0;
    for(auto& y : a){
        double d = getd(x, y);
        mind = min(mind, d);
        maxd = max(maxd, d);
        r.push_back(d);
    }
    double re = abs(mind - maxd);
    if(re < ans){
        ans = re;
        ansv = x;
    }
    return re;
}

void sa(){
    vector<double> p(n);
    for(int i = 0; i < n; ++i) p[i] = rand(-2e4, 2e4);
    // for(int i = 0; i < n; ++i) p[i] = rand(-1, 1);
    // for(double t = 2e4; t > 1e-4; t *= 0.99){
    for(double t = 1; t > 1e-4; t *= 0.99){
        vector<double> np(n);
        for(int i =0 ; i < n ;++i) np[i] = rand(p[i] - t, p[i] + t);
        double dt = getc(np) - getc(p);

        #ifdef DEBUG
        cout << ans << " ";
        for(int i = 0; i < n; ++i) cout << ansv[i] << " ";
        cout << "\n";
        #endif
        if(exp(-dt / t) > rand(0, 1)) p = np;

    }
    
}


int main(){
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    srand((unsigned)time(NULL));
    cin >> n;
    a.resize(n+1, vector<double>(n, 0));
    for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < 100; ++i) sa();
    // sa();
    
    cout << setiosflags(ios::fixed) << setprecision(3);
    for(int i = 0; i < n; ++i){
        if(i != 0) cout << " ";
        cout << ansv[i];
    }
    cout << "\n";
}