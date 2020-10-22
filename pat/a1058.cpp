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

struct HP{ // currency system in Harry Potter
    int g, s, k; // Galleon, Sickle, Knut; 
                 // [0, 10^7] [0, 17), [0, 29)
                 //radix:        17       29
    HP operator +(const HP& hp){
        HP re;
        re.k = re.s = re.g = 0;
        re.k += k + hp.k;
        if(re.k >= 29){
            re.k -= 29;
            re.s += 1;
        }
        re.s += s + hp.s;
        if(re.s >= 17){
            re.s -= 17;
            re.g += 1;
        }
        re.g += g + hp.g;
        return re;
    }
}A, B, C;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d.%d.%d %d.%d.%d", &A.g, &A.s, &A.k, &B.g, &B.s, &B.k);
    C = A+B;
    printf("%d.%d.%d\n", C.g, C.s, C.k);
}