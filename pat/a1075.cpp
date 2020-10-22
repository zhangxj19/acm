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

int N, K, M, perfect[6];


struct P{
    int id, p[6], pcnt; // perfectly solved problems count
    int inlist; // ever passed compiler
    int sum;
    int rk;
    P(){
        inlist = 0;
        pcnt = 0;
        sum = 0;
        memset(p, -1, 6*sizeof(int));
    }
}p[10001]; 

bool cmp(const P& p1, const P& p2){
    if(p1.inlist != p2.inlist) return p1.inlist > p2.inlist;
    else{
        if(p1.sum != p2.sum) return p1.sum > p2.sum;
        else{
            if(p1.pcnt != p2.pcnt) return p1.pcnt > p2.pcnt;
            else return p1.id < p2.id;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    scanf("%d%d%d", &N, &K, &M);
    _U(i, 1, K+1){
        scanf("%d", &perfect[i]);
    }

    _U(i, 0, M){
        int id, pid, pso;
        scanf("%d%d%d", &id, &pid, &pso);
        if(pso != -1) p[id].inlist = 1;
        if(pso == -1 and p[id].p[pid]==-1) p[id].p[pid] = 0;
        p[id].p[pid] = std::max(pso, p[id].p[pid]);
        
    }

    _U(i, 0, 10001){
        p[i].id = i;
        _U(j, 1, K+1){
            if(p[i].p[j] != -1) p[i].sum += p[i].p[j];
            if(p[i].p[j] == perfect[j]) p[i].pcnt++;
        }
    }   

    sort(p, p+N+1, cmp);

#ifdef DEBUG
    printf("perfect: ");
    _U(i, 1, K+1){
        printf("%d ", perfect[i]);
    }
    printf("\n");
    _U(i, 0, N+1){
        printf("id=%05d sum=%d pcnt=%d ", p[i].id, p[i].sum, p[i].pcnt);
        _U(j, 1, K+1){
            printf("%d ", p[i].p[j]);
        }
        printf("\n");

    }
#endif

    int i = 0;
    p[0].rk = 1;
    while(p[i].inlist){
        if(i > 0 and p[i].sum != p[i-1].sum) p[i].rk = i+1;
        else if(i > 0 and p[i].sum == p[i-1].sum) p[i].rk = p[i-1].rk;
        printf("%d %05d %d ", p[i].rk, p[i].id, p[i].sum);
        _U(j, 1, K+1){
            if(p[i].p[j] != -1){
                printf("%d", p[i].p[j]);
            }
            else{
                printf("-");
            }
            if(j < K){
                printf(" ");
            }
        }
        printf("\n");
        i++;
    }

    return 0;
}