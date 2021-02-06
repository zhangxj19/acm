#include <bits/stdc++.h>

using namespace std;

int randint(int a, int b){ //[a, b)
    return rand() % (b - a) + a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand((unsigned)time(NULL));

    int n = randint(10, 21);
    cout << n << "\n";

    for(int i = 0; i < n; ++i){
        if(i != 0) cout << " ";
        cout << randint(0, 101);
    }
    cout << "\n";




    
}