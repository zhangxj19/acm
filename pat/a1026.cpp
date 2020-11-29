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
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}
#define lowbit(x) (x&(-x));

using namespace std;

int N, K, M;

struct Node{
    int a, s, vip, p, w; // arrive time, serve time, vip, play time, waiting time

};

vector<Node> node;

int second(int h, int m, int s){
    return h*3600 + m*60 + s;
}

struct Table{
    int cnt, vip;
    int end;
    Table(){
        cnt = 0; vip = 0; end = 0;
    }
};

vector<Table> table;

int endt, startt, two, p, pvip; // player and vip player

int next_vip_player(int s){
    for(int i = s ; i < N; ++i) if(node[i].vip) return i;
}

void min_end_vip_table(int &idx, int& t){
    idx = -1, t = INT_MAX;
    for(int i = 0; i < K; ++i){
        if(table[i].end < t and table[i].vip){
            t = table[i].end;
            idx = i;
        }
    }
}

void min_end_normal_table(int &idx, int& t){
    idx = -1, t = INT_MAX;
    for(int i = 0; i < K; ++i){
        if(table[i].end < t and !table[i].vip){
            t = table[i].end;
            idx = i;
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
    cin >> N;
    node.resize(N);
    endt = second(21, 0, 0);
    startt = second(8, 0, 0);
    two = second(2, 0, 0);
    uu(i, 0, N){
        int h, m, s, p, tag;
        char c;
        cin >> h >> c >> m >> c >> s >> p >> tag;
        node[i].a = second(h, m, s);
        node[i].p = second(0, p, 0);
        node[i].vip = tag;
    }

    sort(node.begin(), node.end(), [](const Node& n1, const Node& n2){
        return n1.a < n2.a;
    });
    #ifdef DEBUG
    uu(i, 0, N){
        pf("id:%d, a=%d, p=%d, is vip %d\n", i, node[i].a, node[i].p, node[i].vip);
    }
    
    #endif

    cin >> K >> M;

    table.resize(K);
    uu(i, 0, K) table[i].end = startt;
    uu(i, 0, M){
        int id;
        cin >> id;
        id--;
        table[id].vip = 1;
    }

    #ifdef DEBUG
    uu(i, 0, K){
        pf("table %d is vip %d\n", i, table[i].vip);
    }
    #endif

    // pvip = next_vip_player(0);
    for(int i = 0; i < N; ++i){
        int end, endvip, idx, idxvip;
        min_end_normal_table(idx, end);
        min_end_vip_table(idxvip, endvip);

        #ifdef DEBUG
        pf("end =%d idx=%d,  endvip=%d, vipidx = %d\n", end, idx, endvip, idxvip);
        #endif
        // 
        if(node[i].s != 0) continue;

        if(node[i].vip){
            if(endvip <= node[i].a){ // serve 
                node[i].w = 0;
                node[i].s = node[i].a;
                table[idxvip].end = node[i].s + _min(node[i].p, two);      
                continue;
            }            
            
            if(end <= node[i].a){
                node[i].w = 0;
                node[i].s = node[i].a;
                table[idx].end = node[i].s + _min(node[i].p, two);
                table[idx].cnt++;
                continue;
            }

            if(end < endvip){
                node[i].w = end - node[i].a;
                node[i].s = end;
                table[idx].end = node[i].s + _min(node[i].p, two);
                table[idx].cnt++;
            }
            else{
                node[i].w = endvip - node[i].a;
                node[i].s = endvip;
                table[idxvip].end = node[i].s + _min(node[i].p, two);
                table[idxvip].cnt++;
            }

        }
        else{ // not vip
            pvip = next_vip_player(i);
          
            if(end <= node[i].a){
                node[i].s = node[i].a;
                table[idx].end = node[i].s + _min(node[i].p, two);
                table[idx].cnt++;
                continue;
            }
            else{
                if(endvip <= node[pvip].a and node[pvip].s == 0){
                    node[pvip].w = 0;
                    node[pvip].s = endvip;
                    table[idxvip].end = node[pvip].s + _min(node[pvip].p, two);
                    table[idxvip].cnt++;               
                }
                
                node[i].w = end - node[i].a;
                node[i].s = end;
                table[idx].end = node[i].s + _min(node[i].p, two);
                table[idx].cnt++;
                continue;    
            }


         
        }
    }   


    sort(node.begin(), node.end(), [](const Node &n1, const Node &n2){
        return n1.s < n2.s;
    });

    uu(i, 0, node.size()){
        if(node[i].s >= endt) continue;
        cout << setw(2) << setfill('0') << node[i].a/3600 << ":" << setw(2) << setfill('0') << node[i].a/60 % 60 << ":" << setw(2) << setfill('0') << node[i].a%60 << " ";
        cout << setw(2) << setfill('0') << node[i].s/3600 << ":" << setw(2) << setfill('0') << node[i].s/60 % 60 << ":" << setw(2) << setfill('0') << node[i].s%60 << " ";
        cout << (int)ceil(node[i].w / 60) << endl;
    }

    uu(i, 0, K){
        if(i == 0)cout << table[i].cnt;
        else cout << " " << table[i].cnt;
    }
    cout << endl;


    
    return 0;
}