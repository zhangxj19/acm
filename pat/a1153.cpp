
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define rep(i, n) for (int i = 0, size = (n); i < size; ++i)
#define repu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define repd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define each(it, a) for(auto & (it) : (a))

using namespace std;
int n, m;
struct Node{
    string id;
    int s;
};
vector<Node> node;

int cmp(Node& x, Node& y){
    return x.s != y.s ? x.s > y.s : x.id < y.id;
}


void solve(){
    cin >> n >> m;
    rep(i, n){
        Node x;
        cin >> x.id >> x.s;
        node.push_back(x);
    }

    rep(i, m){
        int type;
        cin >> type;
        cout << "Case " << i + 1 << ": ";
        // printf("Case %d: ", i+1);
        string term;
        cin >> term;
        cout << type << " " << term << '\n';
        // printf("%d %s\n", type, term.c_str());
        vector<Node> ans;
        if(type == 1){
            each(x, node){
                if(x.id.substr(0, 1) == term) ans.push_back(x);
            }
        }
        else if(type == 2){
            int cnt = 0, sum = 0;
            each(x, node){
                if(x.id.substr(1, 3) == term){
                    cnt++;
                    sum += x.s;
                }
            }
            // if(cnt == 0) printf("NA\n");
            // else printf("%d %d\n", cnt, sum);
            if(cnt == 0) cout << "NA\n";
            else cout << cnt << " " << sum << '\n';
            
        }
        else if(type == 3){
            unordered_map<string, int> mp;
            each(x, node){
                if(x.id.substr(4, 6) == term){
                    mp[x.id.substr(1,3)]++;
                }
            }
            each(x, mp) ans.push_back({x.first, x.second});
        }
        else {
            cout << "NA\n";
            // printf("NA\n");
        }
        sort(ans.begin(), ans.end(), cmp);
        if(ans.size() == 0 and (type == 1 or type == 3)){
            cout << "NA\n";
        }
        else{
            each(x, ans){
                // printf("%s %d\n", x.id.c_str(), x.s);
                cout << x.id << " " << x.s << '\n';
            }
        }
    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("o", "w", stdout);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}