#include <bits/stdc++.h>

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

double a[3][3], b[3], w, t, l;

int main(){
    ios::sync_with_stdio(false);
    for(int i = 0; i < 3; i++){

        scanf("%lf %lf %lf", &w, &t, &l);
 
        b[i] = std::max(w, std::max(t, l));
        // printf("b[%d]=%.2lf\n", i, b[i]);

        if(b[i] == w){
            printf("W ");
        }
        else if(b[i] == t){
            printf("T ");
        }
        else{
            printf("L ");
        }
    }
    printf("%.2lf\n", (b[0]*b[1]*b[2]*0.65-1)*2);
}
