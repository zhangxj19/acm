#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 1;
string inod, lod;
struct Node{
    char ch;
    int l, r;
    Node():l(-1), r(-1){}
}node[maxn];
int n;
void init(){
    n = 0;
}
int newnode(){
    return n++;
}
unordered_map<int, int> mp;
int create(int l, int r){
    // cout << l << " " << r << "\n";
    if(l > r) return -1;
    if(l == r) {
        int id = newnode();
        node[id].ch = inod[l];
        return id;
    }
    else {
        int mid = 0;
        for(int i = 0; i < lod.size(); ++i){
            if(l <= mp[lod[i]] and mp[lod[i]] <= r){
                mid = mp[lod[i]];
                break;
            }
        }
        int id = newnode();
        node[id].ch = inod[mid];
        node[id].l = create(l, mid-1);
        node[id].r = create(mid + 1, r);
        return id;
    }
}

void preorder(int cur){
    if(cur == -1) return;
    cout << node[cur].ch;
    preorder(node[cur].l);
    preorder(node[cur].r);
}

void solve() {
    int rt = create(0, inod.size() - 1);
    preorder(rt);
}

int main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> inod >> lod;    
    for(int i = 0 ; i <inod.size(); ++i){
        mp[inod[i]] = i;
    }
    solve(); 
}