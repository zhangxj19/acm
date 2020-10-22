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

const int maxbreads=1001;

char so[maxbreads], eva[maxbreads]; // shop owner

map<char, int> mso, meva;

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    scanf("%s%s", so, eva);

    for(int i=0, n=strlen(so); i < n; i++){
        if(mso.find(so[i]) == mso.end()) mso[so[i]] = 0;
        mso[so[i]] += 1;
    }

    for(int i=0, n=strlen(eva); i < n; i++){
        if(meva.find(eva[i]) == meva.end()) meva[eva[i]] = 0;
        meva[eva[i]] += 1;
    }

    #ifdef DEBUG
    printf("mso:\n");
    for(const auto& c_n : mso){
        printf("%c:%d ", c_n.first, c_n.second);
    }
    printf("\n");

    printf("meva:\n");
    for(const auto& c_n : meva){
        printf("%c:%d ", c_n.first, c_n.second);
    }
    printf("\n");
    #endif 

    bool isYes = true;
    for(const auto& c_n : meva){
        char c = c_n.first;
        if(mso.find(c) == mso.end() or (mso.find(c) != mso.end() and mso[c] < c_n.second)){
            isYes = false;
            break;
        }   
    }


    if(isYes){
        printf("Yes ");
        int cnt = 0;
        for(const auto& c_n : mso){
            char c = c_n.first; // breeds from so
            if(meva.find(c) == meva.end()){
                cnt += c_n.second;
            }
            else{
                cnt += c_n.second - meva[c];
            }
        }
        printf("%d\n", cnt);
    }
    else{
        printf("No ");
        int cnt = 0;
        for(const auto& c_n : meva){
            char c = c_n.first; // breeds from eva
            if(mso.find(c) == mso.end()){
                cnt += c_n.second;
                #ifdef DEBUG
                printf("no %c in so\n", c_n.first);
                #endif 
            }
            else{
                if(c_n.second > mso[c]) cnt += c_n.second - mso[c];
                #ifdef DEBUG
                if(c_n.second > mso[c])
                printf("%c in so, %d in so, %d of eva in need, cnt += %d\n", c_n.first, mso[c], c_n.second, c_n.second - mso[c]);
                #endif 
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}