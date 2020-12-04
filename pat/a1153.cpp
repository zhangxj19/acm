// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define each(it, a) for(auto & (it) : (a))
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define lowbit(x) (x&(-x))
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(std::vector<int> &v){
    uu(i, 0, v.size()){
        if(i == 0) std::cout << v[i];
        else std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

using namespace std;
int N, M;

int toint(const string &x){
    int re = 0;
    each(c, x){
        re *= 10;
        re += c-'0';
    }
    return re;
}

struct Node{
    string level; 
    string site;
    string date;
    int s;
    string card;
    Node(const string &x, int s):s(s){
        card = x;
        level = x.substr(0, 1);
        site = x.substr(1, 3);
        date = x.substr(4, 6);
    }
};

struct Site{
    string site;
    int s;
    int cnt;
};

#define psi pair<string, int>
struct Date{

    vector<psi> v;
    string date;
    map<string, int> mp; // site to index 

    void add_site(string &x){
        if(mp.find(x) == mp.end()){
            mp[x] = v.size();
            v.push_back({x, 1});
        }
        else{
            v[mp[x]].second += 1;
        }
    }

    void sort(){
        std::sort(v.begin(), v.end(), [](psi &p1, psi &p2){
            if(p1.second != p2.second) return p1.second > p2.second;
            else return p1.first < p2.first;
        });
    }
};


bool cmp_score(Node & n1, Node & n2){
    if(n1.s != n2.s) return n1.s > n2.s;
    else return n1.card < n2.card;
}

int bn_search_site(vector<Site> & v, const string &site){ // v is site sorted 
    int l = 0, r = v.size()-1;
    while(l < r){
        int mid = (l+r)>>1;
        if(site <= v[mid].site){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return l;
}

int bn_search_date(vector<Date> & v, const string &date){ // v is date sorted 
    int l = 0, r = v.size()-1;
    while(l < r){
        int mid = (l+r)>>1;
        if(date <= v[mid].date){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return l;
}

void solve(){
    cin >> N >> M;
    vector<Node> T, A, B; // for 1
    vector<Node> nsite;
    vector<Site> site;
    vector<Node> ndate;
    vector<Date> date;
    uu(i, 0, N){
        string x;
        int s;
        cin >> x >> s;
        Node n(x, s);
        if(n.level == "T" or n.level == "A" or n.level == "B"){
            if(n.level == "T") T.push_back(n);
            else if(n.level == "A") A.push_back(n);
            else if(n.level == "B") B.push_back(n);

            nsite.push_back(n);
            ndate.push_back(n);
        }

    }

    sort(T.begin(), T.end(), cmp_score);
    sort(A.begin(), A.end(), cmp_score);
    sort(B.begin(), B.end(), cmp_score);

    sort(nsite.begin(), nsite.end(), [](Node &n1, Node &n2){  
        return n1.site < n2.site;
    });

    // preprocess for site
    
    Site tmp;
    tmp.site = nsite[0].site;
    tmp.cnt = 1;
    tmp.s = nsite[0].s;
    site.push_back(tmp);
    uu(i, 1, nsite.size()){
        if(nsite[i].site != nsite[i-1].site){
            Site tmp;
            tmp.site = nsite[i].site;
            tmp.cnt  = 1;
            tmp.s = nsite[i].s;
            site.push_back(tmp);
        }
        else{
            site[site.size()-1].cnt++;
            site[site.size()-1].s += nsite[i].s;
        }
    }

    sort(ndate.begin(), ndate.end(), [](Node &n1, Node &n2){  
        return n1.date < n2.date;
    });

    Date dtmp;
    dtmp.add_site(ndate[0].site);
    dtmp.date = ndate[0].date;
    date.push_back(dtmp);

    uu(i, 1, ndate.size()){
        if(ndate[i].date != ndate[i-1].date){
            //time to sort
            date[date.size()-1].sort();
            
            Date tmp;
            tmp.add_site(ndate[i].site);
            tmp.date = ndate[i].date;
            date.push_back(tmp);
        }
        else{
            date[date.size()-1].add_site(ndate[i].site);
        }
    }
    date[date.size()-1].sort();





    uu(num, 1, M+1){
        
        string cmd, v;
        cin >> cmd >> v;
        cout << "Case " << num << ": " << cmd << " " << v << endl;
        if(cmd == "1"){
            if(v == "T") each(p, T) cout << p.card << " " << p.s << endl;
            else if(v == "A") each(p, A) cout << p.card << " " << p.s << endl;
            else if(v == "B") each(p, B) cout << p.card << " " << p.s << endl;
            else cout << "NA" << endl;
        }
        else if(cmd == "2"){
            int i = 0;
            // for(; i < site.size() and site[i].site != v; ++i);
            i = bn_search_site(site, v);

            
            if(site[i].site == v)
                cout << site[i].cnt << " " << site[i].s << endl;
            else
                cout << "NA" << endl;
        }
        else if(cmd == "3"){
            int i = 0;
            // for(; i < date.size() and date[i].date != v; ++i);
            i = bn_search_date(date, v);

            if(date[i].date != v) cout << "NA" << endl;
            else{
                each(it, date[i].v) cout << it.first << " " << it.second << endl;
            }


        }
        else{
            cout << "NA" << endl;
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