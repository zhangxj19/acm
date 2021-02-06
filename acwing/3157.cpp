#include <bits/stdc++.h>

using namespace std;

int n[3];
char mem[1001][2][2][2];
int sum;

int cango(int N){
    for(int i = 0; i < 3; ++i) if(N >= n[i]) return true;
    return false;
}

char dp(int N, int s1, int s2, int k){
    if(!cango(N)){
        if(s1 == s2) return '0';
        if(s1 == '+') return '+';
        return '-';
    }
    auto& v = mem[N][s1][s2][k];
    if(v != -1) return v;
    if(k == 0){
        // a
        int bwin = 1;
        for(int i =0; i < 3; ++i){
            if(N - n[i] < 0) continue;
            int ns = (n[i] ^ s1) & 1;
            int f = dp(N - n[i], ns, s2, 1);
            if(f == '+') return v = '+';
            if(f != '-') bwin = 0;
        }
        if(bwin) return v = '-';
        else return '0';
    }
    else{
        // b;
        int awin = 1;
        for(int i = 0; i < 3; ++i){
            if(N - n[i] < 0) continue;
            int ns = (n[i] ^ s2) & 1;
            int f = dp(N-n[i], s1, ns, 0);
            if(f == '-') return v = '-';
            if(f != '+') awin = 0;
        }
        if(awin) return v = '+';
        else return '0';
    }
}    

int main(){
    for(int i = 0; i < 3; ++i){
        cin >> n[i];
    }    
    vector<char> re;
    for(int i = 0; i < 5; ++i){
        int t;
        cin >> t;
        memset(mem, -1, sizeof(mem));
        sum = t;
        re.push_back(dp(t, 0, 0, 0));
        
    }
    
    for(int i = 0; i < 5; ++i){
        if(i != 0) cout << " ";
        cout << re[i];
    }
    cout << '\n';
}