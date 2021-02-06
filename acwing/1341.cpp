#include <bits/stdc++.h>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isleap(int y){
    return (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0);
}

struct Date{
    int y, m, d, w;
    int leap;
    Date():y(1900), m(1), d(1), w(1){ leap = isleap(1900);}
    void one(){
        w++; if(w == 8) w = 1;
        
        d++;
        if(m == 2 and leap and days[m] + 2 == d){
            m++;
            d = 1;
        }
        if(!(m == 2 and leap) and days[m] + 1 == d){
            m++;
            d = 1;
        }
        
        if(m == 13){
            y++;
            m = 1;
        }
        
        leap = isleap(y);
    }
    
};

int main(){
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif 
    int n;
    cin >> n;
    vector<int> re(8, 0);
    Date date;
    if(date.d == 13) re[date.w]++;
    while(!(date.d == 31 and date.m == 12 and date.y == 1900 + n - 1)){
        date.one();
        cout << date.y << " " << date.m << " " << date.d << " " << date.w << "\n";
        if(date.d == 13) re[date.w]++;
    }
    cout << re[6] << " " << re[7];
    for(int i = 1; i <= 5; ++i){
        cout << " " << re[i];
    }
    cout << "\n";
}