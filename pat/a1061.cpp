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

char s[4][61];

vector<int> decode_1(char s1[], char s2[]){
    vector<int> re;
    int start=0, l1=strlen(s1), l2=strlen(s2);
    _U(i, 0, std::min(l1, l2)){
        if(s1[i]==s2[i] and s1[i] >= 'A' and s1[i] <= 'G'){
            // printf("Week = %c\n", s1[i]);
            re.push_back(s1[i] - 'A' + 1);
            start = i+1;
            break;
        }
    }
    _U(i, start, std::min(strlen(s1), strlen(s2))){
        if(s1[i] == s2[i] and ((s1[i] >= '0' and s1[i] <= '9') or (s1[i] >= 'A' and s1[i] <= 'N'))){
            // printf("HH = %c\n", s1[i]);
            if(s1[i] >= '0' and s1[i] <= '9'){
                re.push_back(s1[i] - '0');
            }
            else{
                re.push_back(s1[i] - 'A' + 10);
            }
            break;
        }
    }
    return re;
}

vector<int> decode_2(char s1[], char s2[]){
    vector<int> re;
    int l1=strlen(s1), l2=strlen(s2);
    _U(i, 0, std::min(l1, l2)){
        if(s1[i]==s2[i] and ((s1[i] >= 'A' and s1[i] <= 'Z') or (s1[i] >= 'a' and s1[i] <= 'z'))){
            // printf("MM=%c\n", s1[i]);
            re.push_back(i);
            return re;
        }
    }
    return re;
}


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    _U(i, 0, 4){
        scanf("%s", s[i]);
    }
    vector<int> a1, a2;
    a1 = decode_1(s[0], s[1]);
    a2 = decode_2(s[2], s[3]);
    switch(a1[0]){
        case 1:{
            printf("MON ");
            break;
        }
        case 2:{
            printf("TUE ");
            break;
        }
        case 3:{
            printf("WED ");
            break;
        }
        case 4:{
            printf("THU ");
            break;
        }
        case 5:{
            printf("FRI ");
            break;
        }
        case 6:{
            printf("SAT ");
            break;
        }
        case 7:{
            printf("SUN ");
            break;
        }
        default: break;
    }
    printf("%02d:%02d\n", a1[1], a2[0]);
    return 0;
}
