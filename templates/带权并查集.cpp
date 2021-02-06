#include <bits/stdc++.h>

using namespace std;

struct UF{
    int cnt;
    vector<int> f, sz, d;
    UF(int n):f(n), d(n, 0) {
        for(int i = 0; i < n; ++i) f[i] = i;
    }

    int find(int x){
        if(f[x] == x) return x;
        else {
            int rt = find(f[x]);
            d[x] += d[f[x]];
            f[x] = rt;
            return f[x];
        }
    }
    int connected(int x, int y){
        return find(x) == find(y);
    }
    int unite(int x, int y, int eat = 0){
        // eat = 0 same kind
        // eat = 1 x eat y
        // mod 0 eat 1 eat 2 eat 0
        int px = find(x);
        int py = find(y);
        if(px == py) return 0;
        else{
            f[py] = px;
            if(eat){
                d[py] = d[x] + 1 - d[y];
            }
            else{
                d[py] = d[x] - d[y];
            }
            cnt--;
            return 1;
        }
    }
    
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    UF uf(n);
    int re = 0;
    while(k--){
        int op;
        int x, y;
        cin >> op >> x >> y;
        x--; y--;
        if(x >= n or y >= n){
            re++;
        }
        else{
            if(op == 1) {
                if(uf.connected(x, y)) {
                    if((uf.d[y] - uf.d[x]) % 3) re++;
                }
                else{
                    uf.unite(x, y);
                }
            }
            else {
                if(x == y){
                    re++;
                    continue;
                }
                if(uf.connected(x, y)){
                    if((uf.d[y] - uf.d[x] - 1) % 3) re++;
                }
                else uf.unite(x, y, 1);
            }
        }
    }
    cout << re << "\n";
    
}