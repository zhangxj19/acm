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

char str[81];

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%s", str);
    int len = strlen(str), n1 = ceil(len/3.0), n2 = len+2-2*n1, space = n2-2;
    _U(i, 0, n1-1){
        printf("%c", str[i]);
        _U(j, 0, space){
            printf(" ");
        }
        printf("%c\n", str[len-1-i]);
    }
    _U(i, 0, n2){
        printf("%c", str[n1-1+i]);
    }
    printf("\n");

}