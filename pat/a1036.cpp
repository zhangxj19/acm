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

struct Stu{
    char name[11], id[11], g[2];
    int s;

}minM, maxF, tmp;
int N;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d", &N);
    minM.s = 101;
    maxF.s = -1;

    _U(i, 0, N){
        scanf("%s %s %s %d", tmp.name, tmp.g, tmp.id, &tmp.s);
        if(tmp.g[0] == 'M' && tmp.s < minM.s){
            minM = tmp;
        }
        else if(tmp.g[0] == 'F' && tmp.s > maxF.s){
            maxF = tmp;
        }
    }
    if(maxF.s == -1)printf("Absent\n");
    else printf("%s %s\n", maxF.name, maxF.id);

    if(minM.s == 101)printf("Absent\n");
    else printf("%s %s\n", minM.name, minM.id);

    if(minM.s == 101 or maxF.s == -1)printf("NA\n");
    else printf("%d\n", maxF.s - minM.s);

}