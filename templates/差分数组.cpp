#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+1;
int n, m;
int a[maxn], b[maxn];

void update(int l, int r, int c){
    b[l] += c;
    if(r+1 < n) b[r+1] -= c;
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        update(i, i, a[i]);
    }
    
    for(int i = 0; i < m; ++i){
        int l, r, c;
        cin >> l >> r >> c;
        l--;
        r--;
        update(l, r, c);
    }
    a[0] = b[0];
    for(int i = 1; i < n; ++i){
        a[i] = a[i-1] + b[i];
    }
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
    
}