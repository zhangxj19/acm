#include <bits/stdc++.h>

#define DEBUG

#define _U(i, a, b) for (int i = (a); i < (b); ++i)
#define _D(i, a, b) for (int i = (a); i > (b); --i)

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int N;

struct User{
    char account[11], password[11];
    bool is_replaced;
}users[1001];

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d", &N);
    int cnt=0;
    _U(i, 0, N){
        scanf("%s %s", users[i].account, users[i].password);
        users[i].is_replaced = false;
        _U(j, 0, strlen(users[i].password)){
            switch(users[i].password[j]){
                case '1':{
                    users[i].is_replaced = true;
                    users[i].password[j] = '@';
                    break;
                }
                case '0':{
                    users[i].is_replaced = true;
                    users[i].password[j] = '%';
                    break;
                }
                case 'l':{
                    users[i].is_replaced = true;
                    users[i].password[j] = 'L';
                    break;
                }
                case 'O':{
                    users[i].is_replaced = true;
                    users[i].password[j] = 'o';
                    break;
                }
                default: break;
            }
        }
        if(users[i].is_replaced) cnt++;
    }
    if(cnt){
        printf("%d\n", cnt);
        _U(i, 0, N){
            if(users[i].is_replaced){
                printf("%s %s\n", users[i].account, users[i].password);
            }
        }
    }
    else{
        if(N == 1){
            printf("There is 1 account and no account is modified\n");
        }
        else{
            printf("There are %d accounts and no account is modified\n", N);
        }
    }
}
