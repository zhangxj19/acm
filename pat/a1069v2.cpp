// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

// #define DEBUG

#define uu(i, a, b) for (int i = (a); i < (b); ++i)
#define dd(i, a, b) for (int i = (a); i > (b); --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int a, b, num[4];

bool cmp(const int& i1, const int& i2){
    return i1 > i2;
}

void to_array(int x, int num[]){
    int i = 3;
    while(x){
        num[i--] = x%10;
        x/=10;
    }
}

int to_num(int num[]){
    int re = 0;
    uu(i, 0, 4){
        re = re*10 + num[i];
    }
    return re;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    scanf("%d", &a);
    while(1){
        to_array(a, num);
        sort(num, num+4, cmp);
        a = to_num(num);
        sort(num, num+4);
        b = to_num(num);
        pf("%04d - %04d = %04d\n", a, b, a-b);
        a = a-b;
        if(a == 0 or a == 6174) break;
    }


    return 0;
}