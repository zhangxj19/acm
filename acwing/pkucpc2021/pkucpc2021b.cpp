#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 105;
int n;
struct Node {
    int rk, id;
    int pt, goal, gd; // total
    int ptl, goall, gdl; // gain
    int win, lose, draw;
}a[N];
int ri, rpt , rptl , rgdl , rgoall , rgd , rgoal , rid ; 

struct Edge {
    int u, v;
    int c, d;
};
vector<Edge> g[N];

void CopyToRe(int j) {
    ri = j;
    rpt = a[j].pt;
    rptl = a[j].ptl;
    rgdl = a[j].gdl;
    rgoall = a[j].goall;
    rgd = a[j].gd;
    rgoal = a[j].goal;
    rid = a[j].id;
}


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    int T;
    cin >> T;
    while (T--) {
        memset(a, 0, sizeof a);
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            a[i].id = i;
            g[i].clear();
        }
        for (int i = 0; i < n * (n-1) / 2; ++i) {
            int A, B, C, D;
            cin >> A >> B >> C >> D;
            g[A].push_back({A, B, C, D});
            g[B].push_back({B, A, D, C});

            a[A].goal += C;
            a[B].goal += D;
            a[A].goall += C;
            a[B].goall += D;

            if (C > D) {
                a[A].pt += 3;
                a[A].ptl += 3;
                a[A].win ++;

                a[B].pt += 0;
                a[B].ptl += 0;
                a[B].lose ++;
            }
            else if(C == D) {
                a[A].pt ++;
                a[A].ptl ++;
                a[A].draw ++;

                a[B].pt ++;
                a[B].ptl ++;
                a[B].draw ++;

            }
            else {
                a[A].pt += 0;
                a[A].ptl += 0;
                a[A].lose ++;

                a[B].pt += 3;
                a[B].ptl += 3;
                a[B].win ++;

            }
            a[A].gd += C - D;
            a[B].gd += D - C;

            a[A].gdl += C - D;
            a[B].gdl += D - C;
        }

        unordered_set<int> st;
        for (int i = 1; i <= n; ++i) {
            // sort here
            ri = -1, rpt = -1e9, rptl = -1e9, rgdl = -1e9, rgoall = -1e9, rgd = -1e9, rgoal = -1e9, rid = 1e9; 
            for (int j = 1; j <= n; ++j) {
                if(!st.count(j)) {
                    if (a[j].pt > rpt) {
                        CopyToRe(j);
                    }
                    else if(a[j].pt == rpt) {
                        if (a[j].ptl > rptl) {
                            CopyToRe(j);
                        }        
                        else if(a[j].ptl == rptl) {
                            if (a[j].gdl > rgdl) {
                                CopyToRe(j);
                            }
                            else if(a[j].gdl == rgdl) {
                                if (a[j].goall > rgoall) {
                                    CopyToRe(j);
                                }
                                else if(a[j].goall == rgoall) {
                                    if (a[j].gd > rgd) {
                                        CopyToRe(j);;
                                    }
                                    else if(a[j].gd == rgd) {
                                        if (a[j].goal > rgoal) {
                                            CopyToRe(j);;
                                        }
                                        else if(a[j].goal == rgoal) {
                                            if (a[j].id < rid) {
                                                CopyToRe(j);;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            st.insert(ri);

            cout << i << " " << a[ri].id << " " << a[ri].pt << " " << a[ri].win << " "  << a[ri].draw << " " << a[ri].lose << " " << a[ri].gd << " " << a[ri].goal << "\n";

            // ri is deleted;
            for (auto& edge : g[ri]) {
                int v = edge.v, c = edge.c, d = edge.d;

                a[v].goall -= d;
                if (c > d) {
                    a[v].ptl -= 0;
                }
                else if (c == d) {
                    a[v].ptl -= 1;
                }
                else {
                    a[v].ptl -= 3;
                }
                a[v].gdl -= c - d;
            }
        }

        
    }
    
    return 0;
}