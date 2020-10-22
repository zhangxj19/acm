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

int N, K;

struct P{
    char name[9];
    int age, nw; // net worth
}p[100000]; // 100,000 -> 200*100=20,000

vector<P> pre;
int Age[201]={0};

int M, Amin, Amax;

bool inrange(const P& p){
    if(Amin <= p.age and p.age <= Amax) return true;
    else return false;
}

bool cmp(const P& p1, const P& p2){
    if(p1.nw != p2.nw) return p1.nw > p2.nw;
    else if(p1.age != p2.age) return p1.age < p2.age;
    else if(strcmp(p1.name, p2.name) < 0) return true;
    else return false;
}


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d%d", &N, &K);
    _U(i, 0, N){
        scanf("%s%d%d", p[i].name, &p[i].age, &p[i].nw);
    }
    sort(p, p+N, cmp);
    _U(i, 0, N){
        if(Age[p[i].age] < 100){
            pre.push_back(p[i]);
            Age[p[i].age]++;
        }
    }

#ifdef DEBUG
    _U(age, 1, 201){
        printf("age:%d ", age);
        _U(i, 0, pre[age].size()){
            printf("%s %d;", pre[age][i].name, pre[age][i].nw);
        }
        printf("\n");
    }
#endif
    _U(i, 1, K+1){ // K query
        printf("Case #%d:\n", i);
        scanf("%d%d%d", &M, &Amin, &Amax);
        bool is_print=false;
        int cnt = 0, j = 0;
        while(cnt < M and j < pre.size()){
            if(inrange(pre[j])){
                printf("%s %d %d\n", pre[j].name, pre[j].age, pre[j].nw);
                is_print = true;
                cnt += 1;
            }
            j += 1;
        }
        if(!is_print){
            printf("None\n");
        }
    }
    return 0;
}