#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N_OPTR 7
const int N = 1e5 + 5;
char S[N];


const char pri[N_OPTR][N_OPTR] = {
//          +    -    *    /    (    )
/*  +  */ {'>', '>', '<', '<', '<', '>', '>'}, 
/*  -  */ {'>', '>', '<', '<', '<', '>', '>'}, 
/*  *  */ {'>', '>', '>', '>', '<', '>', '>'}, 
/*  /  */ {'>', '>', '>', '>', '<', '>', '>'}, 
/*  (  */ {'<', '<', '<', '<', '<', '=', ' '}, 
/*  )  */ {' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
/* '\0'*/ {'<', '<', '<', '<', '<', ' ', '='},  
};

bool isoptr(char x) {
    return x == '+' or x == '-' or x == '*' or x == '/' or x == '('
        or x == ')' or x == '\0';
}

int offset(char c) {
    if(c == '+') return 0;
    else if(c == '-') return 1;
    else if(c == '*') return 2;
    else if(c == '/') return 3;
    else if(c == '(') return 4;
    else if(c == ')') return 5;
    else if(c == '\0') return 6;
    
    exit(-1);
}

char compare(char a, char b) {
    return pri[offset(a)][offset(b)];
}


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> S;
    char *s = S;
    int num = 0;
    stack<int> opnd, optr;
    optr.push('\0');
    while(!optr.empty()) {
        if(!isoptr(*s)) {
            num *= 10;
            num += *s - '0';
            s++;
            if(*s == '\0' or isoptr(*s)) {
                opnd.push(num);
                num = 0;
            }
        }
        else {
            switch(compare(optr.top(), *s)) {
                case '<': {
                    optr.push(*s);
                    s++;
                    break;
                }
                case '=': {
                    optr.pop();
                    s++;
                    break;
                }
                case '>': {
                    char op = optr.top(); optr.pop();
                    int b = opnd.top(); opnd.pop();
                    int a = opnd.top(); opnd.pop();
                    int c = 0;
                    if(op == '+') c = a + b;
                    else if(op == '-') c = a - b;
                    else if(op == '*') c = a * b;
                    else if(op == '/') c = a / b;
                    opnd.push(c);
                    break;
                }
                default: exit(-1);
            }
        }
    }
    cout << opnd.top() << "\n";

    
}