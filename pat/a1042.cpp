#include <bits/stdc++.h>

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;
int K, cards[54], order[54], _cards[54]; // 0-53

string num2card(int x){
    string re;
    int q = x / 13;
    if(q == 0){
        re += "S";
    }
    else if(q == 1){
        re += "H";
    }
    else if(q == 2){
        re += "C";
    }
    else if(q == 3){
        re += "D";
    }
    else if(q == 4){
        re += "J";
    }
    re += to_string(x%13+1);
    return re;
}

void shuffle(){
    for(int i = 0; i < 54; i++){
        // printf("cards[%d]=%d -> cards[%d]\n", i, cards[i], order[i]-1);
        _cards[order[i]-1] = cards[i];
    }
    memcpy(cards, _cards, 54*sizeof(int));
}


int main(){
    ios::sync_with_stdio(false);
    cin >> K;
    for(int i = 0; i < 54; i++){
        cin >> order[i];
        cards[i] = i;
    }
    while(K--){
        shuffle();
    }
    for(int i = 0; i < 53; i++){
        cout << num2card(cards[i]) << " ";
    }
    cout << num2card(cards[53]) << endl;

    // for(int i = 0; i < 54; i++){
    //     cout << cards[i] << " ";
    // }
    // cout << endl;
}