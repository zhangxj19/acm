#include <bits/stdc++.h>

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int N, M;
vector<int> dis, l2r;

int sp(int x, int y){ // shortest path
    if(x == y) return 0;
    if(x > y) std::swap(x, y);
    // printf("l2r[%d]=%d, l2r[%d]=%d, dis[%d]=%d\n", x, l2r[x], y, l2r[y], x, dis[x]);
    y -= 1;
    int clk_wise = l2r[y] - l2r[x] + dis[x], anti_clk_wise = l2r[N-1] - clk_wise;
    if(clk_wise <= anti_clk_wise){
        return clk_wise;
    } 
    else{
        return anti_clk_wise;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    dis.resize(N);
    l2r.resize(N);
    // r2l.resize(N);
    for(int i = 0; i < N; i++){
        int d;
        cin >> d;
        dis[i] = d;
    }
    l2r[0] = dis[0];
    for(int i = 1; i < N; i++){
        l2r[i] = l2r[i-1] + dis[i];
    }
    // for(const auto& num : dis){
    //     cout << num << " ";
    // }
    // cout << endl;
    // for(const auto& num : l2r){
    //     cout << num << " ";
    // }
    // cout << endl;
    // r2l[N-1] = dis[N-1];
    // for(int i = N-2; i > -1; i--){
    //     r2l[i] = r2l[i+1] + dis[i];
    // }

    cin >> M;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        cout << sp(x-1, y-1) << endl;
    }
    
}