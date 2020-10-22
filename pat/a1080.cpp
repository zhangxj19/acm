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

//M number of graduate schools[0, 100]
int N, M, K, quota[100], lastrk[100];
vector<int> re[100];


struct MaxHeapCmp{
    inline bool operator()(const int& x, const int& y){
        return x > y;
    }
};

void init(){
    _U(i, 0, M){
        make_heap(re[i].begin(), re[i].end(), MaxHeapCmp());
    }
}


void push(int x, int y){
    re[x].push_back(y);
    push_heap(re[x].begin(), re[x].end(), MaxHeapCmp());
}

int pop(int x){
    pop_heap(re[x].begin(), re[x].end(), MaxHeapCmp());
    int tmp = re[x][re[x].size()-1];
    re[x].pop_back();
    return tmp;
}


struct P{
    int id, rk;
    int ge, gi, sum;
    int ps[5]; // preferred schools
}p[40000];

bool isadmitted(int x, int rk){
    if(re[x].size() < quota[x] || lastrk[x] == rk){
        #ifdef DEBUG
        printf("school(quota is %d) %d accepted the rk %d\n", quota[x], x, rk);
        #endif
        
        
        return true;
    }
    else return false;
}

bool cmp(const P& p1, const P& p2){
    if(p1.sum != p2.sum) return p1.sum > p2.sum;
    else{
        if(p1.ge != p2.ge) return p1.ge > p2.ge;
        else return p1.id < p2.id;
    }
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    cin >> N >> M >> K;
    _U(i, 0, M){
        cin >> quota[i];
    }
    _U(i, 0, N){
        cin >> p[i].ge >> p[i].gi;
        _U(j, 0, K){
            cin >> p[i].ps[j];
        }
        p[i].id = i;
        p[i].sum = p[i].ge + p[i].gi;
    }

    sort(p, p+N, cmp);
    #ifdef DEBUG
    _U(i, 0, N){
        printf("id=%d, sum=%d, ge=%d\n", p[i].id, p[i].sum, p[i].ge);
    }
    #endif

    init();

    p[0].rk = 1;
    _U(i, 0, N){
        if(i > 0){
            if(p[i].sum == p[i-1].sum and p[i].ge == p[i-1].ge) p[i].rk = p[i-1].rk;
            else p[i].rk = i+1;
        }
        _U(j, 0, K){
            if(isadmitted(p[i].ps[j], p[i].rk)){
                lastrk[p[i].ps[j]] = p[i].rk;
                // re[p[i].ps[j]].push_back(p[i].id);
                push(p[i].ps[j], p[i].id);
                break;
            }
        }
    }
    _U(i, 0, M){
        if(re[i].size()){
            while(re[i].size()){
                int tmp = pop(i);
                cout << tmp;
                if(re[i].size() != 0) cout << " ";
                // if(j < re[i].size()-1) cout << " ";
            }
            cout << endl;
        }
        else{
            cout << endl;
        }
    }



    return 0;
}