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

char num[10];
char c[10][5]={
    "ling",
    "yi",
    "er",
    "san",
    "si",
    "wu",
    "liu",
    "qi",
    "ba",
    "jiu"
};

void printSpaceUnit(char num[], int i){
    int offset = strlen(num) - 1 - i;
    if(offset / 4 > 0 and offset % 4 != 0){
        printf(" ");
        return;
    }
    for(int j = i+1; j < strlen(num); j++){
        if(num[j] != '0'){
            printf(" ");
            return;
        }
    }
}

void printSpaceNum(char num[], int i){
    //        3    2   1  0
    //       qian bai shi ge
    // unit followed by space

    // number followed by sapce
    if(i != strlen(num) - 1) printf(" ");

}


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    scanf("%s", num);
    if(num[0] == '-'){
        printf("Fu ");
        // num[strlen(num)-1] = '\0'
        _U(i, 0, strlen(num)){
            num[i] = num[i+1];
        }
    }
    _U(i, 0, strlen(num)){
        int offset = strlen(num)-1 - i;
        bool is_print_ling = false;
        if(num[i] - '0' == 0){
            if((i < strlen(num) - 1 and num[i+1] != '0' and offset%4!=0) or (int)strlen(num)==1) is_print_ling = true;
            if(is_print_ling){
                printf("ling");
                printSpaceNum(num, i);
            }
        }
        else{
            printf("%s", c[num[i]-'0']);    
            printSpaceNum(num, i);
        }
        
        if(offset / 4 == 1 and offset%4 == 0){
            bool is_all_ling = true;
            _D(j, i, std::max(i-4, -1)){
                if(num[j] != '0') is_all_ling = false;
            }
            if(!is_all_ling){
                printf("Wan");
                printSpaceUnit(num, i);
            }
        }
        else if(offset / 4 == 2 and offset%4 == 0){
            printf("Yi");
            printSpaceUnit(num, i);
            bool is_all_ling = true;
            _U(j, i+1, strlen(num)){
                if(num[j] != '0'){
                    is_all_ling = false;
                }
            }
            if(is_all_ling) break;
        }

        if(num[i] - '0' != 0){
            if(offset%4 == 1){
                printf("Shi");
                printSpaceUnit(num, i);
            }
            else if(offset%4 == 2){
                printf("Bai");
                printSpaceUnit(num, i);
            }
            else if(offset%4 == 3){
                printf("Qian");
                printSpaceUnit(num, i);
            }

        }
   
    }
    




    return 0;
}