#include <bits/stdc++.h>

// #define DEBUG

#define _U(i, a, b) for (int i = (a); i < (b); ++i)
#define _D(i, a, b) for (int i = (a); i > (b); --i)

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;
const int maxn = 10001;

char s1[maxn], s2[maxn];

unordered_set<char> st;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%[^\n]\n", s1);
    scanf("%[^\n]]", s2);
    
    #ifdef DEBUG
    printf("s1=\"%s\"\ns2=\"%s\"\n", s1, s2);
    #endif

    for(int i = 0, n = strlen(s2); i < n; i++){
        if(st.find(s2[i]) == st.end()) st.insert(s2[i]);
    }

    for(int i = 0, n = strlen(s1); i < n; i++){
        if(st.find(s1[i]) != st.end()){
            s1[i] = 1;
        }
    }

    int w=0, r=0, n = strlen(s1);
    while(r < n){
        if(s1[r] != 1){
            s1[w] = s1[r];
            w++;
            r++;
        }
        else{
            r++;
        }
    }

    s1[w] = '\0';
    printf("%s\n", s1);





    return 0;
}