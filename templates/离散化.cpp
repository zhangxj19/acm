#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+1;
int a[maxn], s[maxn];
vector<int> alls;
#define pii pair<int, int>
vector<pii> add, query;

int n, m;

int find(int x){
    int l = 0, r = alls.size()-1;
    while(l < r){
        int m = (l + r) >> 1;
        if(alls[m] >= x) r = m;
        else l = m + 1;
    }
    return l;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for(int j = 0; j < m; ++j){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    for(auto& x : add){
        int id = find(x.first);
        a[id] += x.second;
    }   
    
    for(int i = 0; i < alls.size(); ++i) s[i + 1] = s[i] + a[i];

    for(auto& [l, r] : query){
        int idl = find(l), idr = find(r);
        cout << s[idr + 1] - s[idl] << "\n";
    } 
}