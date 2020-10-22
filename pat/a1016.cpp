#include <bits/stdc++.h>

#define DEBUG

#define _U(i, a, b) for (int i = (a); i < (b); ++i)
#define _D(i, a, b) for (int i = (a); i > (b); --i)

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int rate[24], radix[4]={0, 30, 24, 60}; // MM:dd:HH:mm

struct P{ // person
    string name;
    int t[4], state;
    P(string n="", int M=0, int d=0, int H=0, int m=0, int st=0){
        name = n;
        t[0] = M;
        t[1] = d;
        t[2] = H;
        t[3] = m;
        state = st;
    }
}v[1000];

bool cmp_P(const P& p1, const P& p2){
    if(p1.name != p2.name) return p1.name < p2.name;
    else{
        if(p1.t[0] != p2.t[0]) return p1.t[0] < p2.t[0];
        else if(p1.t[1] != p2.t[1]) return p1.t[1] < p2.t[1];
        else if(p1.t[2] != p2.t[2]) return p1.t[2] < p2.t[2];
        else if(p1.t[3] != p2.t[3]) return p1.t[3] < p2.t[3];
        else return false;
    }
}

vector<double> charge(const int t1[], const int t2[]){ // charge and minutes
    // t1 < t2
    // time[0][1][2][3]
    //      M  d  H  m
    // perform t1 grow up to t2
    vector<double> re(2, 0);
    // printf("from %d:%d:%d to %d:%d:%d\n", t1[1],t1[2],t1[3],
                                        //   t2[1],t2[2],t2[3]);
    int tmp[4];
    _U(i, 0, 4) tmp[i]=t1[i];
    while(tmp[1] != t2[1] || tmp[2] != t2[2] || tmp[3] != t2[3]){ // grow minute
        // tmp[3]++; re[1] += 1;
        // re[0] += rate[tmp[2]];
        // if(tmp[3] == 60){
        //     tmp[3] = 0;
        //     tmp[2] += 1;
        // }
        // if(tmp[2] == 24){
        //     tmp[2] = 0;
        //     tmp[1] += 1;
        // }

        if(tmp[1] == t2[1] and tmp[2] == t2[2]){ // day and hour are the same, final grow
            re[0] += rate[tmp[2]] * (t2[3] - tmp[3]);
            re[1] += (t2[3] - tmp[3]);
            break;
        }
        else{ // grow minute
            // printf("minute grow\n");
            re[0] += rate[tmp[2]] * (60 - tmp[3]);
            re[1] += (60 - tmp[3]);
            tmp[3] = 0;
            tmp[2] += 1;
            if(tmp[2] == 24){
                tmp[2] = 0;
                tmp[1] += 1;
            }
        }
    }
    re[0] /= 100;
    return re;
}

int N;

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    _U(i, 0, 24){
        scanf("%d", &rate[i]);
    }
    scanf("%d", &N);
    _U(i, 0, N){
        char cname[21], cstate[21];
        scanf("%s %d:%d:%d:%d %s", cname, &v[i].t[0], &v[i].t[1], &v[i].t[2], &v[i].t[3], cstate);
        string name(cname), state(cstate);
        if(state == "off-line") v[i].state = 1;
        else v[i].state = 0;
        v[i].name = name;
    }
    sort(v, v+N, cmp_P);
    // for(int i = 0; i < N; i++){
    //     printf("name=%s, %d:%d%d:%d, state=%d\n", v[i].name.c_str(),
    //     v[i].t[0],
    //     v[i].t[1],
    //     v[i].t[2],
    //     v[i].t[3],
    //     v[i].state);
    // }
    for(int j = 0; j < N-1;){
        // printf("j=%d\n", j);
        double sum = 0;
        vector<double> cg;
        int i = j;
        bool is_print = false;
        while(i < N-1 and v[i].name == v[j].name){
            // printf("i=%d\n", i);
            if( v[i].name == v[i+1].name and v[i].state < v[i+1].state){ // 0 < 1
                if((j == 0 or v[j].name != v[j-1].name) and !is_print){
                    printf("%s %02d\n", v[j].name.c_str(), v[j].t[0]);
                    is_print = true;
                }
                cg = charge(v[i].t, v[i+1].t);
                sum += cg[0];
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                v[i].t[1], v[i].t[2], v[i].t[3],
                v[i+1].t[1], v[i+1].t[2], v[i+1].t[3],
                (int)cg[1],
                cg[0]
                );
                i += 2;
            }
            else{
                i += 1;
            }
        }
        if(is_print) printf("Total amount: $%.2lf\n", sum);
        j = i;
    }

    return 0;
}