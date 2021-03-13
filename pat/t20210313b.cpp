#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 5;
int n;
int a[N], f[N], f2[N];
vector<int> c[N], c2[N]; // chain
int vis[N];

vector<vector<int>> gre;
vector<int> t;

void dfs(int x) {
    if(c[x].size() == 0) {
        gre.push_back(t);
        return ;
    }

    for(auto& nxt: c[x]) {
        t.push_back(nxt);
        dfs(nxt);
        t.pop_back();
    }

    return ;
}

void rdfs(int x) {
    if(c2[x].size() == 0) {
        gre.push_back(t);
        return ;
    }

    for(auto& nxt: c2[x]) {
        t.push_back(nxt);
        dfs(nxt);
        t.pop_back();
    }

    return ;
}

int replace(vector<int>& v) {
    memset(vis, 0, sizeof vis);
    for(auto& x : v) vis[x] = 1;
    int re = 0;
    if(v.size() == 1) return 0;
    else {
        if(v[0] == v.back()) {
            for(int i = 1; i <= n; ++i) {
                int ok = 0;
                if(!vis[i]) {
                    for(int j = i - 1; j >= 1; --j) {
                        if(a[j] > a[i]) {
                            re ++;
                            ok = 1;
                            break;
                        }
                    }
                    if(!ok) {
                        for(int j = i + 1; j <= n; ++j) {
                            if(a[j] > a[i]) {
                                re ++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        else if(v[0] < v.back()) {
            for(int i = 1; i <= n; ++i) {
                if(!vis[i]) {
                    for(int j = i - 1; j >= 1; --j) {
                        if(a[j] > a[i]) {
                            re ++;
                            break;
                        }
                    }
                }
            }
        }
        else if(v[0] > v.back()) {
            for(int i = 1; i <= n; ++i) {
                if(!vis[i]) {
                    for(int j = i + 1; j <= n; ++j) {
                        if(a[j] > a[i]) {
                            re ++;
                            break;
                        }
                    }
                }
            }

        }
    }

    return re;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];


    for(int i = 1; i <= n; ++i) {
        f[i] = 1;
        for(int j = i - 1; j >= 1; --j) {
            if(a[j] <= a[i]) {
                if(f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                    c[i].clear();
                    c[i].push_back(j);
                }
                else if(f[j] + 1 == f[i]) {
                    c[i].push_back(j);
                }
            }
        }
    }

    for(int i = n; i >= 1; --i) {
        f2[i] = 1;
        for(int j = i + 1; j <= n; ++j) {
            if(a[j] <= a[i]) {
                if(f2[j] + 1 > f2[i]) {
                    f2[i] = f2[j] + 1;
                    c2[i].clear();
                    c2[i].push_back(j);
                }
                else if(f2[j] + 1 == f2[i]) {
                    c2[i].push_back(j);
                }
            }
        }
    }
    #ifdef DEBUG
    for(int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << '\n';
    for(int i = 1; i <= n; ++i) {
        cout << f[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; ++i) {
        cout << f2[i] << " ";
    }
    cout << "\n";
    #endif
    int mx = 0, rev = 0, rmx = 0;
    vector<int> idx, ridx;
    for(int i = 1; i <= n; ++i) {
        if(f[i] > mx) {
            mx = f[i];
            idx.clear();
            idx.push_back(i);
        }
        else if(f[i] == mx) {
            idx.push_back(i);
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(f2[i] > rmx) {
            rmx = f2[i];
            ridx.clear();
            ridx.push_back(i);
            rev = 1;
        }
        else if(f2[i] == rmx) {
            rev = 1;
            ridx.push_back(i);
        }
    }

    #ifdef DEBUG
    cout << mx << " " << rev << "\n";
    cout << "idxs : ";
    for(auto& x : idx) cout << x << " ";
    cout << "\n";
    for(int i = 1; i <= n; ++i) {
        cout << i << ": ";
        for(auto& x : c[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
    for(int i = 1; i <= n; ++i) {
        cout << i << ": ";
        for(auto& x : c2[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
    #endif
    if(mx > rmx) {
        for(auto& x : idx) {
            t.push_back(x);
            dfs(x);
            t.pop_back();
        }
    }
    else if(mx < rmx){
        for(auto& x : ridx) {
            t.push_back(x);
            rdfs(x);
            t.pop_back();
        }
    }
    else {
        for(auto& x : idx) {
            t.push_back(x);
            dfs(x);
            t.pop_back();
        }
        for(auto& x : ridx) {
            t.push_back(x);
            rdfs(x);
            t.pop_back();
        }

    }
    #ifdef DEBUG
    for(auto& v : gre) {
        for(auto& x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
    #endif

    vector<int> tre;
    int mind = 1e9;
    for(auto& v : gre) {
        int x = replace(v);
        if(x < mind) {
            mind = x;
            tre = v;
        }
    }
    memset(vis, 0, sizeof vis);
    for(auto& x : tre) {
        vis[x] = 1;
    }
  
    if(f[n] == n) cout << "Non-descending\n";
    else if(f2[1] == n) cout << "Non-ascending\n";
    else {
        cout << n - tre.size() << "\n";
        int isprint = 0;
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                if(isprint) cout << " ";
                cout << i;
                isprint = 1;
            }
        }
        cout << "\n";
    }



    
    
}