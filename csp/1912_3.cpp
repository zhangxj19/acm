#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

typedef long long ll;

using namespace std;

map<string, int> L, R;

int n;
string equation;

bool isDigit(char c){
    if(c >= '0' and c <= '9') return true;
    else return false;
}

bool isLowerCase(char c){
    if(c >= 'a' and c <= 'z') return true;
    else return false;
}

bool isUpperCase(char c){
    if(c >= 'A' and c <= 'Z') return true;
    else return false;
}

void printDfsHead(const char* str1, string& str2, int COEF=1){
    // printf("in ");
    // cout << str1 << ": ";
    // cout << str2;
    // printf(", COEF=%d\n", COEF);
}

int coef(string str){
    // char from str is from '0' to '1'
    int base = 0;
    for(int i = 0; i < str.size(); i++){
        base *= 10;
        base += str[i]-'0';
    }
    if(base == 0) base=1;
    return base;
}

void element(string str, int COEF, map<string, int>& M){
    if(M.find(str) == M.end()){
        M[str] = COEF;
    }
    else{
        M[str] = M[str] + COEF;
    }
}

void formula(string str, int COEF, map<string, int>& M);

void term(string str, int COEF, map<string, int>& M){
    // <term> ::= <element> | "(" <formula> ")"

    if(str == "") return;
    printDfsHead("term", str, COEF);
    if(str[0] == '('){
        // formula[1:size]
        formula(str.substr(1, str.size()-2), COEF, M);
    }
    else{
        // element[0, :]
        element(str, COEF, M);
    }
}

void formula(string str, int COEF, map<string, int>& M){
    // <term> <cofe> | <formula> <term> <coef>

    printDfsHead("formula", str, COEF);

    if(str == "") return;
    int term_start, coef_start;

    if(!isDigit(str[str.size()-1])) coef_start=str.size();
    else{
        for(coef_start = str.size()-1; coef_start > -1 && isDigit(str[coef_start]); coef_start--);
        coef_start += 1;
    }
    
    //<coef> [coef_start:] may be none

    for(term_start = coef_start-1; term_start > -1;){
        if(isUpperCase(str[term_start])) break;
        else if(isLowerCase(str[term_start])){
            term_start -= 1;
            break;
        }
        else if(str[term_start] == ')'){
            stack<char> S;
            S.push(str[term_start]);
            while(!S.empty()){
                term_start--;
                if(str[term_start] == ')') S.push(str[term_start]);
                else if(str[term_start] == '(') S.pop();
            }
            break;
        }
    }
    // formula[0:term_start] term[term_start, coef_start] coef[coef_start:]
    // cout << str << endl;
    // printf("term_start=%d, coef_start=%d, COEF=%d\n", term_start, coef_start, COEF);
    formula(str.substr(0, term_start), COEF, M);
    term(str.substr(term_start, coef_start-term_start), COEF * coef(str.substr(coef_start, str.size()-coef_start)), M);
    
}

// start from expr
void expr(string str, map<string, int>& M){

    // <coef> <formula> | <expr> "+" <coef> <formula>
    if(str == "") return;
    printDfsHead("term", str);
    int plus;
    for(plus = str.size()-1; plus > -1; plus--){
        if(str[plus] == '+'){
            expr(str.substr(0, plus), M);
            break;
        }
    }
    
    // str[plus+1:] is <coef> <formula>
    int formula_start;
    for(formula_start = plus+1; formula_start < str.size() && isDigit(str[formula_start]); formula_start++);
    // printf("plus=%d, formula_start=%d\n", plus, formula_start);
    // <coef>[plus+1:formula_start] fomula[formula_start:]
    int COEF = coef(str.substr(plus+1, formula_start-1-plus));

    formula(str.substr(formula_start, str.size()-formula_start), COEF, M);

}

void printm(map<string, int>& M){
    // for(const auto& it : M){
    //     cout << it.first;
    //     printf("-> %d;", it.second);
    // }
    // cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    while(n--){
        L.clear(); R.clear();
        cin >> equation;
        for(int i = 0; i < equation.size(); i++){
            if(equation[i] == '='){
                // printf("left part\n");
                expr(equation.substr(0, i), L);
                // printf("right part\n");
                expr(equation.substr(i+1, equation.size()-i-1), R);
                break;
            }
        }
        printm(L); 
        printm(R);
        bool is_equal= true;
        for(const auto& it : L){
            if(it.second != R[it.first]){
                is_equal = false;
            }
        }
        for(const auto& it : R){
            if(it.second != L[it.first]){
                is_equal = false;
            }
        }
        if(is_equal){
            cout << "Y" << endl;
        }
        else{
            cout << "N" << endl;
        }
    }
}