#include <bits/stdc++.h>
using namespace std;
clock_t st, ed;

double second() {
    return (double)(ed - st)/CLOCKS_PER_SEC;
}

int isprime(int x) {
    if(x < 2) return 0;
    for(int i = 2; i <= x / i; ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int isprimev2(int x) {
    if(x < 2) return 0;
    for(int i = 2; i * i <= x;  ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int isprimev3(int x) {
    if(x < 2) return 0;
    for(int i = 2; i <= sqrt(x);  ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int isprimev4(int x) {
    if(x < 2) return 0;
    for(int i = 2, ub = sqrt(x); i <= ub;  ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}


void solve() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        st = clock();
        isprime(x);
        ed = clock();
        cout << second() << "\n";
        st = clock();
        isprimev3(x);
        ed = clock();
        cout << second() << "\n";
        st = clock();
        isprimev4(x);
        ed = clock();
        cout << second() << "\n";
        st = clock();
        isprimev2(x);
        ed = clock();
        cout << second() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();    
}