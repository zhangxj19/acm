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

int a[3];

string dto13(int x){
    string re, tmp;
    if(x == 0){
        re += "0";
    }
    while(x){
        int r = x%13;
        if(r == 10){
            // printf("r=A\n");
            re += "A";
        }
        else if(r == 11){
            // printf("r=B\n");
            re += "B";
        }
        else if(r == 12){
            // printf("r=C\n");
            re += "C";
        }
        else{
            // printf("r < 10 and r =%d\n", r);
            // tmp = to_string(r);
            // char c[2];
            // c[1] = '\0';
            // c[0] = r+'0';
            // printf("tmp=%s\n", tmp.c_str());
            // re += r; 巴嘎！ r是int怎么可以+=到srting上！
            re += to_string(r);
        }
        x = x/13;
    }
    if(re.size()==1) re += "0";    
    reverse(re.begin(), re.end());
    // printf("re=%s\n", re.c_str());
    return re;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    vector<string> re;
    _U(i, 0, 3){
        scanf("%d", &a[i]);
        string to_pack = dto13(a[i]);
        // printf("%d -> %s ", a[i], to_pack.c_str());
        re.push_back(to_pack);
    }
    
    printf("#%s%s%s\n", re[0].c_str(), re[1].c_str(), re[2].c_str());
}