#include <bits/stdc++.h>
using namespace std;

// const int maxn = 50;
const int maxn = 1e5+1;
#define lc(x) (2*x + 1)
#define rc(x) (2*x + 2)
#define p(x) ((x-1)/2)


struct Heap{
    int size, t;;
    int a[maxn];
    // kth insert map to index of heap, and index of heap to kth insert
    // unordered_map<int, int> mp_ph, mp_hp; 
    int mp_ph[maxn], mp_hp[maxn];
    Heap(){
        size = 0;
        memset(a, 0, sizeof a);
        memset(mp_ph, -1, sizeof mp_ph);
        memset(mp_hp, -1, sizeof mp_hp);
        t = 0;
    }
    int havelc(int x) {return lc(x) < size;}
    int haverc(int x) {return rc(x) < size;}
    int isleaf(int x) {return !havelc(x) and !haverc(x);}
    int top(){return a[0];} 
    
    void _swap(int &x, int y, int assign = 1){
        int kx = mp_hp[x], ky = mp_hp[y];
        swap(mp_hp[x], mp_hp[y]);
        swap(mp_ph[kx], mp_ph[ky]);
        
        swap(a[x], a[y]);
        if(assign) x = y;
    }
    
    void up(int k){
        while(k != 0 and a[k] < a[p(k)]){
            // swap(a[k], a[p(k)]);
            // k = p(k);
            _swap(k, p(k));
        }
    }
    
    void down(int k){
        while((havelc(k) and a[lc(k)] < a[k]) or (haverc(k) and a[rc(k)] < a[k])){
            if(!haverc(k) or a[lc(k)] <= a[rc(k)]){
                // swap(a[k], a[lc(k)]);
                // k = lc(k);
                _swap(k, lc(k));
            }
            else {
                // swap(a[k], a[rc(k)]);
                // k = rc(k);
                _swap(k, rc(k));
            }
        }
    }

    void make_heap() {for(int i = (size-1) / 2; i > -1; --i) down(i);}

    void insert(int x) {
        a[size++] = x;
        mp_ph[++t] = size-1;
        mp_hp[size-1] = t;
        up(size-1);
    }
    
    void pop() {
        int k = 0;
        _swap(k, size-1, 0);
        size--;
        down(0);
    }
    
    void revise(int k, int x){
        a[k] = x;
        up(k);
        down(k);
    }
    
    void remove(int k){
        _swap(k, size-1, 0);
        size--;
        up(k);
        down(k);
    }
};


int main() {
    // freopen("in", "r", stdin);
    // freopen("o", "w", stdout);
    int n; cin >> n;
    Heap hp;
    while(n--){
        // “I x”，插入一个数x；
        // “PM”，输出当前集合中的最小值；
        // “DM”，删除当前集合中的最小值（数据保证此时的最小值唯一）；
        // “D k”，删除第k个插入的数；
        // “C k x”，修改第k个插入的数，将其变为x；
        string op;
        cin >> op;
        int k, x;
        if(op == "I") {
            cin >> x;
            hp.insert(x);
        }
        else if (op == "PM") {
            cout << hp.top() << "\n";
        }
        else if (op == "DM") {
            hp.pop();
        }
        else if (op == "D") {
            cin >> k;
            hp.remove(hp.mp_ph[k]);
        }
        else if (op == "C") {
            cin >> k >> x;
            hp.revise(hp.mp_ph[k], x);
        }
        #ifdef DEBUG
        cout << op << " " << k << " " << x << "\n";
        for(int i = 0; i < hp.size; ++i){
            cout << "(" << hp.a[i] << ", " << hp.mp_hp[i] << ", " << hp.mp_ph[hp.mp_hp[i]] << " " << i << ") ";
        }
        cout << "\n";
        #endif
    }
}