#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <math.h>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

typedef long long ll;

using namespace std;
int K;

struct cmp {
    bool operator()(const int& k1, const int& k2)const {
        return k1 > k2;
    }
};

map<int, double, cmp> ma, mb;

bool is0(double x){
    // printf("\nx=%.1f\n", x);
    if(x >= 0 and x < 1e-9){
        return true;
    }
    if(x < 0 and x > -1e-9){
        return true;
    }
    // if(x == 0) return true;
    return false;
}

// #include <cmath>
// bool is0(double x){
//     if(fabs(x) < 1e-5) return true;
//     else return false;
// }


int main(){
    ios::sync_with_stdio(false);
    cin >> K;
    int Ni;
    double ai;
    for(int i = 0; i < K; i++){
        cin >> Ni >> ai;
        ma[Ni] = ai;
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> Ni >> ai;
        mb[Ni] = ai;
    }

    int cnt0 = 0;
    for(const auto& it : ma){
        int k = it.first;
        double v = it.second;
        if(mb.find(k) != mb.end()){
            v += mb[k];
            mb[k] = 0;

            ma[k] = v;
            if(is0(v)) cnt0++;
        }
        
    }

    for(const auto& it : mb){
        int k = it.first;
        double v = it.second;
        if(!is0(v)){
            ma[k] = v;
        }
    }

    cout<< setiosflags(ios::fixed);
    if(ma.size()-cnt0 == 0){
        cout << 0;
    }
    else{
        cout << ma.size()-cnt0 << " ";
    }
    int cnt = 0;
    for(const auto& it : ma){
        int k = it.first;
        double v = it.second;
        // printf("\nv=%.1f\n", v);
        if(!is0(v)){
            cout << k << " ";
            cout << setprecision(1) << v;    
            cnt += 1;
            if(cnt != ma.size()-cnt0){
                cout << " ";
            }        
        }

    }
    cout << endl;

}