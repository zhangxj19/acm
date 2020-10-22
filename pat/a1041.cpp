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

int N;

int a[100000];
map<int, int> mp;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d", &N);
    _U(i, 0, N){
        scanf("%d", &a[i]);
        if(mp.find(a[i]) == mp.end()) mp[a[i]] = 0;
        mp[a[i]] += 1;
    }

    #ifdef DEBUG
    for(const auto& i_i : mp){
        printf("(%d, %d) ", i_i.first, i_i.second);
    }
    printf("\n");
    #endif 

    bool isprint = false;
    _U(i, 0, N){
        if(mp[a[i]] == 1){
            printf("%d\n", a[i]);
            isprint = true;
            break;
        }
    }
    if(!isprint){
        printf("None\n");
    }

    return 0;
}