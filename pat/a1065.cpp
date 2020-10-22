#include <bits/stdc++.h>

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

ll A, B, C;
int T;

int main(){
    // ios::sync_with_stdio(false);
    cin >> T;
    // scanf("%d", &T);
    int tcase = 1;
    while(T--){
        scanf("%lld%lld%lld", &A, &B, &C);
        // cin >> A >> B >> C;
        bool is_greater;
        ll re = A+B;
        if(A > 0 and B > 0 and re < 0) is_greater = true;
        else if(A < 0 and B < 0 and re >= 0) is_greater = false;
        else if(re > C) is_greater = true;
        else is_greater = false;

        if(is_greater){
            printf("Case #%d: true\n", tcase++);
            // cout << "Case #" << tcase++ << ": true" << endl;
        }
        else{
            printf("Case #%d: false\n", tcase++);
            // cout << "Case #" << tcase++ << ": false" << endl;
        }
        
    }
    
}