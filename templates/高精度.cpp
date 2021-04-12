#include <bits/stdc++.h>

using namespace std;

void print(vector<int>& a){
    for(int i = 0; i < a.size(); ++i){
        if(i != 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

const int maxn = 1e6+1;
struct bign{
    int d[maxn];
    int len;
    bign(){
        memset(d, 0, sizeof d);
        len = 0;
    }
};

bign change(string x){
    bign re;
    re.len = x.size();
    for(int i = 0; i < re.len; ++i){
        re.d[i] = x[re.len - 1 - i] - '0';
    }
    return re;
}

int compare(bign a, bign b){
    if(a.len != b.len) return a.len > b.len ? 1 : -1;
    for(int i = a.len-1; i > -1; --i){
        if(a.d[i] != b.d[i]) return a.d[i] > b.d[i] ? 1 : -1;
    }
    return 0;
}

bign add(bign a, bign b){
    bign re;
    int c = 0;
    for(int i = 0; i < a.len or i < b.len; ++i){
        int sum = a.d[i] + b.d[i] + c;
        re.d[re.len++] = sum % 10;
        c = sum / 10;
    }
    if(c != 0) re.d[re.len++] = c;
    return re;
}


bign sub(bign a, bign b){
    bign re;
    for(int i = 0; i < a.len or i < b.len; ++i){
        if(a.d[i] < b.d[i]){
            a.d[i+1]--;
            a.d[i] += 10;
        }
        re.d[re.len++] = a.d[i] - b.d[i];
    }
    while(re.len > 1 and re.d[re.len-1] == 0) re.len--;
    return re;
}

bign multi(bign a, int b){
    bign re;
    int c = 0;
    for(int i = 0; i < a.len; ++i){
        int sum = a.d[i] * b + c;
        re.d[re.len++] = sum % 10;
        c = sum / 10;
    }
    while(c){
        re.d[re.len++] = c%10;
        c /= 10;
    }
    while(re.len > 1 and re.d[re.len-1] == 0) re.len--;
    return re;
}

bign divide(bign a, int b, int& r){
    bign re;
    re.len = a.len;
    for(int i = a.len-1; i > -1; --i){
        r = r * 10 + a.d[i];
        if(r < b) re.d[i] = 0;
        else{
            re.d[i] = r / b;
            r = r % b;
        }
    }
    while(re.len > 1 and re.d[re.len-1] == 0) re.len--;
    return re;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
}