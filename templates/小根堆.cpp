#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+1;
#define lc(x) (2*x + 1)
#define rc(x) (2*x + 2)
#define p(x) ((x-1)/2)
struct Heap{
    int size;
    int a[maxn];
    Heap(){
        size = 0;
        memset(a, 0, sizeof a);
    }
    int havelc(int x) {return lc(x) < size;}
    int haverc(int x) {return rc(x) < size;}
    int isleaf(int x) {return !havelc(x) and !haverc(x);}
    int top(){return a[0];} 

    void _swap(int& x, int y){
        swap(a[x], a[y]);
        x = y;      
    }
    
    void up(int k){
        while(k != 0 and a[k] < a[p(k)]) _swap(k, p(k));
    }
    void down(int k){
        while((havelc(k) and a[lc(k)] < a[k]) or (haverc(k) and a[rc(k)] < a[k])){
            if(!haverc(k) or a[lc(k)] <= a[rc(k)]) _swap(k, lc(k));
            else _swap(k, rc(k));
        }
    }

    void make_heap() {for(int i = (size-1) / 2; i > -1; --i) down(i);}

    void insert(int x) {
        a[size++] = x;
        up(size-1);
    }
    
    void pop() {
        a[0] = a[size-1];
        size--;
        down(0);
    }
    
    void revise(int k, int x){
        a[k] = x;
        up(k);
        down(k);
    }
    
    void remove(int k){
        a[k] = a[size-1];
        size--;
        up(k);
        down(k);
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    Heap hp;
    hp.size = n;
    for(int i = 0; i < n; ++i){
        cin >> hp.a[i];
    }
    hp.make_heap();
    for(int i = 0; i < m; ++i){
        cout << hp.top() << " ";
        hp.pop();
    }
    cout <<"\n";
}