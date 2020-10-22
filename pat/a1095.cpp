#include <bits/stdc++.h>

// #define DEBUG

#define _U(i, a, b) for (int i = (a); i < (b); ++i)
#define _D(i, a, b) for (int i = (a); i > (b); --i)

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

struct C{
    string id;
    int s, time; // s=0 for in and s=1 for out
    bool operator == (const C& c) const{
        if(id == c.id and time == c.time and s == c.s) return true;
        else return false;
    }
    C(string id="", int s=0, int time=0){
        id=id;
        s=s;
        time = time;
    }
}c[10001], valid[10001];

int N, K;

bool CmpByIdAndTime(const C& c1, const C& c2){
    if(c1.id != c2.id) return c1.id < c2.id;
    else return c1.time < c2.time;
}

bool CmpByTime(const C& c1, const C& c2){
    // if(c1.time != c2.time) return c1.time < c2.time;
    // else return c1.id < c2.id;
    return c1.time < c2.time;
}

struct CmpByStringKey{
    bool operator()(const string& s1, const string& s2) const{
        return s1 < s2;
    }
};

int TimeToInt(int hh, int mm, int ss){
    return hh*3600 + mm*60 + ss;
}

map<string, int, CmpByStringKey> Map;
// map<string, int> Map;
int maxpark=-1;

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    scanf("%d%d", &N, &K);
    _U(i, 0, N){
        char cid[8], cs[4];
        int hh, mm, ss;
        scanf("%s %d:%d:%d %s", cid, &hh, &mm, &ss, cs);
        string id(cid), s(cs);
        c[i].id = id;
        c[i].time = TimeToInt(hh, mm, ss);
        if(s == "in") c[i].s = 0;
        else c[i].s = 1;
    }

    sort(c, c+N, CmpByIdAndTime);

    int n=0;
    for(int i=0; i < N-1; i++){
        if(c[i].s < c[i+1].s and c[i].id == c[i+1].id){ // 0 1

            valid[n++] = c[i];
            valid[n++] = c[i+1];

            int t = c[i+1].time - c[i].time;
 
            if(Map.find(c[i].id) == Map.end()){
                Map[c[i].id] = t;
            }
            else{
                Map[c[i].id] = Map[c[i].id] + t;
            }
            if(Map[c[i].id] > maxpark) maxpark = Map[c[i].id];
            
        }// 00 11 10

    }


    sort(valid, valid+n, CmpByTime);

    int now = 0, cnt=0;
    _U(i, 0, K){
        int hh, mm, ss, t;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        t = TimeToInt(hh, mm, ss);

        for(int j = now; j < n;j++){
            if(valid[j].time > t){
                // now = j-1;
                now = j;
                break;
            }
            else{
                if(valid[j].s == 0) cnt++;
                else cnt--;
            }
        }
        printf("%d\n", cnt);
    }


    for(const auto& id_t : Map){
        if(id_t.second == maxpark){
            printf("%s ", id_t.first.c_str());
        }
    }
    printf("%02d:%02d:%02d\n", maxpark/3600, maxpark%3600/60, maxpark%60);


    return 0;
}