#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5 + 5;
int N, Tdef, Tmax, Tmin;
int n;

struct Data {
    string src, des, type;
    int ip, expr;
}data;

#define UN_ALLOCATE 0
#define TO_ALLOCATE 1 
#define ALLOCATED 2 
#define EXPR 3 

struct Ip {
    int type, expr;
    string user;
};

struct server {
    string name;
    Ip ip[MAXN]; // ip address to IP
}S;
signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Tdef >> Tmax >> Tmin >> S.name;
    int n;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        cin >> data.src >> data.des >> data.type >> data.ip >> data.expr;

        // update S
        for (int i = 1; i <= N; ++i) {
            if (S.ip[i].expr <= t and S.ip[i].expr != 0) {
                if (S.ip[i].type == TO_ALLOCATE) {
                    S.ip[i].type = UN_ALLOCATE;
                    S.ip[i].user = "";
                    S.ip[i].expr = 0;
                }

                if (S.ip[i].type == ALLOCATED) {
                    S.ip[i].type = EXPR;
                    S.ip[i].expr = 0;
                }
            }
        }

        if(data.des == "*" or data.des == S.name) {
            if (!(data.type == "DIS" or data.type == "REQ")) {
                continue;
            }

            if (data.des == "*" and data.type != "DIS") {
                continue; 
            }

            if (data.des == S.name and data.type == "DIS") {
                continue; 
            }


            if (data.type == "DIS") {
                Data ofr;
                ofr.type = "OFR";
                ofr.src = S.name;
                ofr.des = data.src;
                int nip = 0;

                for (int i = 1; i <= N; ++i) {
                    if (S.ip[i].user == data.src) {
                        nip = i;
                        break;
                    }
                }

                if (!nip) {
                    for (int i = 1; i <= N; ++i) {
                        if (S.ip[i].type == UN_ALLOCATE) {
                           nip = i;
                           break; 
                        }
                    }

                    if (!nip) {
                        for (int i = 1; i <= N; ++i) {
                            if (S.ip[i].type == EXPR) {
                                nip = i;
                                break;
                            }
                        }
                    }
                    
                    if (!nip) {
                        continue;
                    }
                }
                ofr.ip = nip;
                S.ip[nip].type = TO_ALLOCATE;
                S.ip[nip].user = data.src;
                if (data.expr == 0) {
                    S.ip[nip].expr = t + Tdef;
                    ofr.expr = t + Tdef;
                }
                else {
                    int dif = data.expr - t;
                    if (dif < Tmin) {
                        dif = Tmin;
                    }
                    else if (dif > Tmax) {
                        dif = Tmax;
                    }
                    S.ip[nip].expr = ofr.expr = t + dif;
                }

                cout << ofr.src << " " << ofr.des << " " << ofr.type << " " << ofr.ip << " " << ofr.expr << "\n";
            }


            if (data.type == "REQ") {

                if (data.ip >= 1 and data.ip <= N and S.ip[data.ip].user == data.src) {
                    int nip = data.ip;
                    S.ip[nip].type = ALLOCATED;
                    Data ofr;
                    if (data.expr == 0) {
                        S.ip[nip].expr = t + Tdef;
                        ofr.expr = t + Tdef;
                    }
                    else {
                        int dif = data.expr - t;
                        if (dif < Tmin) {
                            dif = Tmin;
                        }
                        else if (dif > Tmax) {
                            dif = Tmax;
                        }
                        S.ip[nip].expr = ofr.expr = t + dif;
                    }                    
                    cout << S.name << " " << data.src << " ACK " << nip << " " << ofr.expr << "\n";
                }
                else {
                    cout << S.name << " " << data.src << " NAK " << data.ip << " 0\n";
                }
            }


        }
        else {
            if (data.type != "REQ") {
                continue;
            }
            if (data.des != S.name) {
                // cout << "clear\n";
                for (int i = 1; i <= N; ++i) {
                    if (S.ip[i].user == data.src) {
                        if (S.ip[i].type == TO_ALLOCATE) {
                            S.ip[i].type = UN_ALLOCATE;
                            S.ip[i].user = "";
                            S.ip[i].expr = 0;
                        }
                    }
                }
            }            
        }
        #ifdef DEBUG2
        cout << t << " " <<data.src << " " << data.des << " " << data.type << " " << data.ip << " " << data.expr << "\n";
        for(int i = 1; i <= N; ++i) {
            cout << i << " " << S.ip[i].user << " " << S.ip[i].type << " " <<  S.ip[i].expr << "\n";
        }
        cout << "======\n";
        #endif


    }
    
    
}