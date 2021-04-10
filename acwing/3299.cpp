#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3e6;
// const int maxn = 1e3;
int n;
vector<string> path;
struct Node {
    int isd;
    int ld, lr, vld, vlr;
    int sz;
    string name;
    // vector<int> c;
    map<string, int> c;
    int p;
    Node() {
        isd = 1;
        ld = lr = 0;
        vld = vlr = 0;
    }
}node[maxn];
int sz, head;
int newnode() {
    return ++sz;
}

int goc(int x, string& y) {
    if(node[x].c.count(y)) return node[x].c[y];
    else return -1;
}

int upsize(int x, int sz, int isld) {
    if(x == 0) {
        int ok = 1;
        if(isld and node[x].ld != 0 and node[x].vld + sz > node[x].ld) ok = 0;
        if(node[x].lr != 0 and node[x].vlr + sz > node[x].lr) ok = 0;
        if(ok) {
            if(isld) node[x].vld += sz;
            node[x].vlr += sz;
            return 1;
        }
        else return 0;
    }
    else {
        int ok = 1;
        if(isld and node[x].ld != 0 and node[x].vld + sz > node[x].ld) ok = 0;
        if(node[x].lr != 0 and node[x].vlr + sz > node[x].lr) ok = 0;
        if(!ok) return 0;
        else {
            if(upsize(node[x].p, sz, 0)) {
                if(isld) node[x].vld += sz;
                node[x].vlr += sz;
                return 1;
            }
            else return 0;
        }
    }
}

int R() {
    int n = head;
    for(int i = 0; i < path.size(); ++i) {
        int nxt = goc(n, path[i]);
        if(nxt == -1 or (i != path.size() - 1 and !node[nxt].isd)) return 1;
        else {
            n = nxt;
        }
    }
    int sz;
    int p = node[n].p;
    if(node[n].isd) {
        sz = node[n].vlr;
        upsize(p, -sz, 0);
    }
    else {
        sz = node[n].sz;
        upsize(p, -sz, 1);
    }
    node[p].c.erase(node[n].name);
    return 1;
}

int C(int sz) {
    int n = head;
    for(int i = 0; i < path.size(); ++i) {
        if(i != path.size() - 1) {
            int nxt = goc(n, path[i]);
            if(nxt == -1) { // create dir
                nxt = newnode();
                node[nxt].name = path[i];

                // node[n].c.push_back(nxt);
                node[n].c[path[i]] = nxt;
                node[nxt].p = n;

                n = nxt;
            }
            else if(!node[nxt].isd){
                return 0; 
            }
            else {
                n = nxt;
            }
        }
        else {
            // normal file
            int nxt = goc(n, path[i]);
            if(nxt == -1) { // new file
                if(upsize(n, sz, 1)) {
                    nxt = newnode();
                    node[nxt].name = path[i];
                    node[nxt].sz = sz;
                    node[nxt].isd = 0;

                    // node[n].c.push_back(nxt);
                    node[n].c[path[i]] = nxt;
                    node[nxt].p = n;
                }
                else return 0;
            }
            else if(node[nxt].isd){
                return 0;
            }
            else { // replace 
                // delete
                string odname = node[nxt].name;
                int odsz = node[nxt].sz;
                R();
                // new file
                if(upsize(n, sz, 1)) {
                    nxt = newnode();
                    node[nxt].name = path[i];
                    node[nxt].sz = sz;
                    node[nxt].isd = 0;

                    node[n].c[path[i]] = nxt;
                    node[nxt].p = n;
                }
                else {
                    nxt = newnode();
                    node[nxt].name = odname;
                    node[nxt].sz = odsz;
                    node[nxt].isd = 0;

                    node[n].c[odname] = nxt;
                    node[nxt].p = n;
                    return 0;
                }
            }
        }
    }
    return 1;
}


int Q(int ld, int lr) {
    int n = head;
    for(int i = 0; i < path.size(); ++i) {
        int c = goc(n, path[i]);
        if(c == -1) return 0;
        else {
            n = c;
        }
    }
    if(!node[n].isd) return 0;
    else { // isd
        if(ld != 0 and node[n].vld > ld) return 0;
        if(lr != 0 and node[n].vlr > lr) return 0;
        node[n].ld = ld;
        node[n].lr = lr;
    }

    return 1;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n--) {
        char c;
        cin >> c;
        string fp;
        int sz;
        int ld, lr;
        cin >> fp;
        path.clear();
        for(int i = 0; i < fp.size(); ){
            if(fp[i] == '/') i++;
            else {
                int idx = fp.find('/', i);
                if(idx != string::npos)
                    path.push_back(fp.substr(i, idx - i));
                else 
                    path.push_back(fp.substr(i, fp.size() - i));
                i = idx;
            }
        }
        #ifdef DEBUG2
        cout << "path : ";
        for(int i= 0 ; i < path.size(); ++i) {
            cout << path[i] << " ";
        }
        cout << "\n";
        #endif
        int t;
        if(c == 'C') {
            cin >> sz;
            t = C(sz);
        }
        else if(c == 'R') {
            t = R();
        }
        else if(c == 'Q') {
            cin >> ld >> lr;
            t = Q(ld, lr);
        }
        if(t) cout << "Y\n";
        else cout << "N\n";
        #ifdef DEBUG2
        cout << c << " " <<  fp << " " << sz << " " << ld << " " << lr << " ";
        cout << "\n=========================================================\n";
        #endif
    }

    
}