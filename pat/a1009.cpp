#include <bits/stdc++.h>

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int k1, k2;
map<int, double> ma, mb;

struct cmp{
    bool operator()(const int& k1, const int& k2) const{
        return k1 > k2;
    }
};
map<int, double, cmp> mc;



int main(){
    ios::sync_with_stdio(false);
    scanf("%d", &k1);
    for(int i = 0; i < k1; i++){
        int Ni;
        double ai;
        scanf("%d %lf", &Ni, &ai);
        ma[Ni] = ai;
    }
    scanf("%d", &k2);
    for(int i = 0; i < k2; i++){
        int Ni;
        double ai;
        scanf("%d %lf", &Ni, &ai);
        mb[Ni] = ai;
    }

    for(const auto & l : ma){
        for(const auto & r : mb){
            int k = l.first + r.first;
            double ai = l.second * r.second;
            if(mc.find(k) == mc.end()){
                mc[k] = ai;
            }
            else{
                mc[k] += ai;
            }
        }
    }

    int cnt0 = 0;
    for(const auto& p : mc){
        // if(p.second == 0){
        if(Equ(p.second, 0)){
            cnt0++;
        }
    }
    if((int)mc.size() - cnt0 == 0){
        printf("0\n");
    }
    else{
        printf("%d ", (int)mc.size() - cnt0);
        int cnt = 0;
        for(const auto& p : mc){
            if(!Equ(p.second, 0)){
                if(cnt++ < mc.size()-cnt0-1){
                    printf("%d %.1lf ", p.first, p.second);
                }
                else{
                    printf("%d %.1lf", p.first, p.second);
                }
            }
        }
        printf("\n");
    }


}