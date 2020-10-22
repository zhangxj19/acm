// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


// #define DEBUG

#define _U(i, a, b) for (int i = (a); i < (b); ++i)
#define _D(i, a, b) for (int i = (a); i > (b); --i)
#define _P printf

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int N;
double Cmax, D, Davg;

struct GS{ // gas station
    double p, d;
}gs[500];

bool cmp(const GS& gs1, const GS& gs2){
    return gs1.d < gs2.d;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    // cin >> Cmax >> D >> Davg >> N;
    scanf("%lf%lf%lf%d\n", &Cmax, &D, &Davg, &N);
    _U(i, 0, N){
        // cin >> gs[i].p >> gs[i].d;
        scanf("%lf%lf", &gs[i].p, &gs[i].d);
    }
    
    sort(gs, gs+N, cmp);
    #ifdef DEBUG
    _U(i, 0, N){
        _P("gs[%d]: p=%.2f, d=%.2f\n", i, gs[i].p, gs[i].d);
    }
    #endif

    if(gs[0].d != 0){
        _P("The maximum travel distance = 0.00\n");
        return 0;
    }

    int now = 0;
    double Dmax = Cmax*Davg, Dnow=0, sump = 0, gasremain=0;
    do{
        int k=-1, i=0;
        double gomax = Dnow + Dmax;
        #ifdef DEBUG
        _P("new round Dnow=%.2f, sump=%.2f, gomax=%.2f\n", Dnow, sump, gomax);
        #endif
        //strategy 1
        for(i = now+1; i < N and gs[i].d <= gomax; i++){
            #ifdef DEBUG
            _P("s1: check %d now\n", i);
            #endif 
            if(gs[i].p < gs[now].p){
                k = i;
                break;
            }
        }
        if(k != -1){
            if(gasremain*Davg > (gs[k].d - gs[now].d)){
                gasremain -= (gs[k].d - gs[now].d) / Davg;
            }
            else{
                sump += (gs[k].d - gs[now].d - gasremain*Davg) / Davg * gs[now].p; // fill gas tank just reachable to next gs
                gasremain=0;
            }

            Dnow = gs[k].d;
            now = k;

            #ifdef DEBUG
            _P("go to next gs which is cheaper than before. sump=%.2f, Dnow=%.2f, now=%d\n", sump, Dnow, now);
            #endif 
            continue;
        }
        if(i == N){
            sump += (D-Dnow) / Davg * gs[now].p;
            if(gomax < D){
                _P("The maximum travel distance = %.2lf\n", gomax);
                return 0;
            }
            break;
        }
        //strategy 2  k == -1
        int mini=now+1;
        double minp = gs[mini].p;
        bool isfind=false;
        for(int i = now+1; i < N and gs[i].d <= gomax; i++){
            #ifdef DEBUG
            _P("s2: check %d now\n", i);
            #endif 
            if(gs[i].p <= minp){
                minp = gs[i].p;
                mini = i;
                isfind=true;
            }
        }
        if(isfind){
            // sump += (gs[mini].d - gs[now].d) / Davg * gs[now].p;
            sump += gs[now].p * (Cmax - gasremain); // fill gas tank to full
            gasremain = Cmax - (gs[mini].d - gs[now].d)/Davg; //goto mini, new gasremain
            Dnow = gs[mini].d;
            now = mini;
            #ifdef DEBUG
            _P("go to next gs which is more expensive but the cheapest among next stations. sump=%.2f, Dnow=%.2f, now=%d\n", sump, Dnow, now);
            #endif 
            continue;
        }
        else{
            _P("The maximum travel distance = %.2lf\n", gomax);
            return 0;
        }

    }
    while(1);

    _P("%.2lf\n", sump);



    return 0;
}