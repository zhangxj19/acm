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

int M;

struct Person{
    char id[16];
    int t1[3], t2[3];

    bool operator < (const Person& p) const{
        _U(i, 0, 2){
            if(t1[i] == p.t1[i]) continue;
            else return t1[i] < p.t1[i];
        }
        return false;
    }
    bool operator > (const Person& p) const{
        _U(i, 0, 2){
            if(t2[i] == p.t2[i]) continue;
            else return t2[i] > p.t2[i];
        }
        return false;
    }
};

Person ans1, ans2;

void printp(Person& p){
    printf("id=%s from %d:%d:%d to %d:%d:%d\n", p.id, p.t1[0],p.t1[1],p.t1[2],
    p.t2[0], p.t2[1], p.t2[2]);
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    scanf("%d", &M);

    ans1.t1[0] = 24; ans1.t1[1]=60; ans1.t1[2]=60;
    ans2.t2[0] = 0; ans2.t2[1] = 0; ans2.t2[2] = 0;

    
    _U(i, 0, M){
        // printf("i=%d\n",i);
        Person p;
        scanf("%s %d:%d:%d %d:%d:%d", p.id, &p.t1[0], &p.t1[1], &p.t1[2], &p.t2[0], &p.t2[1], &p.t2[2]);
        
        // printp(p);

        if(p < ans1){
            ans1 = p;
        }

        if(p > ans2){
            ans2 = p;
        }

        // printp(ans1);
        // printp(ans2);

        
    }
    printf("%s %s\n", ans1.id, ans2.id);
}