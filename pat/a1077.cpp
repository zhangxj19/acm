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

char s[101][257];


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d\n", &N); // notice that there's a '\n' left in the buffer.
    int minlen = 257;
    _U(i, 0, N){
        // gets(s[i]);
        // fgets(s[i], 256, stdin);
        scanf("%[^\n]\n", s[i]);

        // scanf("%s[^\n]", s[i]);
        int len = strlen(s[i]);
        minlen = std::min(len, minlen);
        int p=0, q=len-1;
        while(p < q){
            std::swap(s[i][p], s[i][q]);
            p++; q--;
        }
    }   
    _U(i, 0, minlen){
        bool is_end = false;
        _U(j, 1, N){
            // printf("j=%d,i=%d,s[j][i]=%c,s[0][i]=%c\n", j, i, s[j][i], s[0][i]);
            if(s[j][i] != s[0][i]){
                is_end = true;
                break;
            }
        }
        if(is_end){
            // end at i
            // i=0
            // i < minlen
            if(i == 0){
                printf("nai\n");
                return 0;
            }
            else{
                _D(j, i-1, -1){
                    putchar(s[0][j]);
                }
                putchar('\n');
                return 0;
            }
        }
    }
    _D(j, minlen-1, -1){
        putchar(s[0][j]);
    }
    putchar('\n');
    return 0;
    // [0:minlen) 




}