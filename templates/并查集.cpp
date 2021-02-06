#include <bits/stdc++.h>

using namespace std;
struct UF{
    int cnt;
    vector<int> f, sz;
    UF(int n):f(n), sz(n, 1){
        for(int i = 0 ; i < n; ++i) f[i] = i;
        cnt = n;
    }
    
    int find(int x){
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    
    int connected(int x, int y){
        return find(x) == find(y);
    }
    
    int unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return 0;
        else{
            if(sz[x] < sz[y]) swap(x, y);
            sz[x] += sz[y];
            f[y] = x;
            cnt--;
            return 1;
        }
    }
    
    int size(int x){
        return sz[find(x)];
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n;
    UF uf(n);
    cin >> m;
    while(m--){
        string op;
        cin >> op;
        int x, y;
        if(op == "C"){
           cin >> x >> y;
           uf.unite(x, y);
        }
        else if(op == "Q1"){
            cin >> x >> y;
            cout << (uf.connected(x, y) == 1 ? "Yes" : "No") << "\n";
        }
        else{
            cin >> x;
            cout << uf.size(x) << "\n";
        }
    }

    
}