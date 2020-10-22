#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

typedef long long ll;

using namespace std;

int a,b;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin >> a >> b;
    a = a+b;
    int cnt = 0, sign = a < 0;
    if(sign) a = -a;
    if(a == 0){
        s = "0";
    }
    else{
        while(a){    
            s += to_string(a%10);
            cnt += 1;
            if(cnt%3==0){
                s += ",";
            }
            a /= 10;
        }
    }
    if(s[s.size()-1] == ','){
        s = s.substr(0, s.size()-1);
    }
    if(sign) s += "-";
    reverse(s.begin(), s.end());
    cout << s << endl;
}