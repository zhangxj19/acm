#include <iostream>
#include <algorithm>

using namespace std;


#define lcm(a, b) (a / __gcd(a, b) * b)

int main(){

    int a, b, c;
    cin >> a >> b >> c;
    cout << lcm(lcm(a, b), c) << endl;
}