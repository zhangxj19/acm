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

char s1[81], s2[81];

set<char> Set;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%s%s", s1, s2);

    _U(i, 0, strlen(s2)){
        if(s2[i] >= 'a' and s2[i] <= 'z'){
            s2[i] += 'A' - 'a';
        }
        Set.insert(s2[i]);
    }
    _U(i, 0, strlen(s1)){
        if(s1[i] >= 'a' and s1[i] <= 'z'){
            s1[i] += 'A' - 'a';
        }        
        if(Set.find(s1[i]) == Set.end()){
            printf("%c", s1[i]);
            Set.insert(s1[i]);
        }
    }
    printf("\n");
    

    return 0;
}