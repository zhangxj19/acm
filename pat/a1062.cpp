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

int N, L, H;

struct P{
    int id, t, v, sum; // talent, virtue
    int is_sage, is_noble, is_fool, is_small;
}p[100000];

bool cmp_score(const P& p1, const P& p2){
    // same order
    if(p1.sum != p2.sum) return p1.sum > p2.sum;
    else{
        if(p1.v != p2.v) return p1.v > p2.v;
        else{
            return p1.id < p2.id;
        }
    }    
}

bool cmp(const P& p1, const P& p2){
    if(p1.is_sage != p2.is_sage) return p1.is_sage > p2.is_sage;
    else{
        // sage rank
        if(p1.is_sage) return cmp_score(p1, p2);
        if(!p1.is_sage and !p2.is_sage){
            if(p1.is_noble != p2.is_noble) return p1.is_noble > p2.is_noble;
            else{
                // noble rank
                if(p1.is_noble) return cmp_score(p1, p2);

                if(!p1.is_noble){
                    if(p1.is_fool != p2.is_fool) return p1.is_fool > p2.is_fool;
                    else{
                        // fool rank
                        return cmp_score(p1, p2);
                        // if(p1.is_fool) return cmp_score(p1, p2);

                        // if(!p1.is_fool) return cmp_score(p1, p2);
                    }
                }

            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d %d %d", &N, &L, &H);

    _U(i, 0, N){
        scanf("%d %d %d", &p[i].id, &p[i].v, &p[i].t);
        p[i].sum = p[i].t + p[i].v;
        p[i].is_sage = p[i].is_noble = p[i].is_fool = p[i].is_small=0;
        if(p[i].t >= H and p[i].v >= H) p[i].is_sage=1;
        if(p[i].t < H and p[i].v >= H) p[i].is_noble=1;
        if(p[i].t < H and p[i].v < H and p[i].v >= p[i].t) p[i].is_fool=1;
        if(p[i].t < H and p[i].v < H and p[i].v < p[i].t) p[i].is_small=1;

        //delete
        if(p[i].t < L or p[i].v < L){
            i -= 1;
            N -= 1;
        }
    }
    sort(p, p+N, cmp);
    printf("%d\n", N);
    _U(i, 0, N){
        printf("%d %d %d\n", p[i].id, p[i].v, p[i].t);
    }

    return 0;
}