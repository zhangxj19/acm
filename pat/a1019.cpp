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

int N, b;



bool check(vector<string>& s){
    int i = 0, j = s.size()-1;
    while(i < j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

vector<string> s;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d %d", &N, &b);
    bool ispali = false;
    string re;
    while(N){
        re = to_string(N%b);
        s.push_back(re);
        N = N/b;
    }
    reverse(s.begin(), s.end());
    ispali = check(s);
    if(ispali){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    _U(i, 0, s.size()){
        printf("%s", s[i].c_str());
        if(i != s.size()-1){
            printf(" ");
        }
    }
    printf("\n");
}