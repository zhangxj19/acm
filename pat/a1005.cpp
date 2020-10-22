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

char s[101];
int sum;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%s", s);
    int i = strlen(s) - 1;
    sum = 0;
    while(i > -1){
        sum += s[i]-'0';
        i -= 1;
    }
    vector<int> v;
    if(sum == 0){
        v.push_back(0);
    }
    while(sum){
        int re = sum%10;
        v.push_back(re);
        sum /= 10;
    }
    _D(i, v.size()-1, -1){
        switch (v[i])
        {
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
        case 0:
            printf("zero");
            break;
        default:
            break;
        }
        if(i != 0){
            printf(" ");
        }
    }
    printf("\n");

}