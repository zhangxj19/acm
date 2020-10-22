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

int N, m;

struct P{
    int id; // 6digits
    int s[4]; // a c m e
}v[2000];

int now;
bool cmp(const P& v1, const P& v2){
    return v1.s[now] > v2.s[now];
}

int rk[1000000][4]={0};
char course[4] = {'A', 'C', 'M', 'E'};


int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    scanf("%d%d", &N, &m);
    _U(i, 0, N){
        P p;
        scanf("%d%d%d%d", &p.id, &p.s[1], &p.s[2], &p.s[3]);
        p.s[0] = p.s[1] + p.s[2] + p.s[3];
        v[i] = p;
    }
    _U(i, 0, 4){
        now = i;
        sort(v, v+N, cmp);
        rk[v[0].id][now] = 1;
        _U(j, 1, N){
            if(v[j].s[now] != v[j-1].s[now]){
                rk[v[j].id][now] = j + 1;
            }
            else{
                rk[v[j].id][now] = rk[v[j-1].id][now];
            }
        }   
    }

    _U(i, 0, m){
        int id;
        scanf("%d", &id);

        if(rk[id][0] == 0) printf("N/A\n");
        else{
            int k = 0; // suppose that 'A' is the highest rank
            _U(j, 0, 4){
                if(rk[id][j] < rk[id][k]){
                    k = j;
                }
            }
            printf("%d %c\n", rk[id][k], course[k]);
            
        }
    }

    return 0;
}