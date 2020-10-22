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

char a[10000];

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    scanf("%s", a);
    if(a[0] == '-') printf("-");
    int E=0;
    _U(i, 0, strlen(a)){
        if(a[i] == 'E'){
            E = i;
            break;
        }
    }

    // [0-9].[0-9]+E[+-][0-9]+
    int exp=0;
    _U(i, E+2, strlen(a)){
        exp *= 10;
        exp += a[i] - '0';
    }
    // printf("abs of exp=%d\n", exp);
    // int i = 0;

    if(exp == 0){
        _U(i, 1, E){
            printf("%c", a[i]);
        }
    }
    
    if(a[E+1] == '+'){
        // +1.2345E+2
        _U(i, 1, E){
            if(a[i] == '.') continue;
            printf("%c", a[i]);
            if(i == exp+2 && i != E-1) printf(".");
        }
        _U(i, 0, exp-(E-1-3+1)){
            printf("0");
        }
    }
    else{
        printf("0.");
        _U(i, 0, exp-1){
            printf("0");
        }
        printf("%c", a[1]);
        _U(i, 3, E){
            printf("%c", a[i]);
        }
    }
    printf("\n");
    return 0;
}