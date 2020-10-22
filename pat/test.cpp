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

struct P{
    char c[100];
};

P p1, p2;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%s", p1.c);
    puts(p1.c);
    p2 = p1;
    puts(p2.c);
    p1.c[0] = 'X';
    puts(p1.c);
    puts(p2.c);

    printf("\n\n");

    char c1[100], c2[100];
    scanf("%s", c1);
    puts(c1);
    
    strcpy(c2, c1);
    c1[0] = 'X';
    puts(c1);
    puts(c2);


}