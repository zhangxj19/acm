#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int N = 3e5 + 5, mod = 1000000007;
int n;
struct Node {
    double x, y;
    int id;
}a[N];

double dist(Node& u, Node& v) {
    double dx = u.x - v.x;
    double dy = u.y - v.y;
    return sqrt(dx * dx + dy * dy);
}


double area2(Node& p, Node& q, Node& s) {
    return p.x * q.y - p.y * q.x
         + q.x * s.y - q.y * s.x
         + s.x * p.y - s.y * p.x;
}

bool between(Node& p, Node& q, Node& s) {
    return (s.x - p.x) * (q.x - s.x) + (s.y - p.y) * (q.y - s.y) > 0;
}

bool left_test(Node& p, Node& q, Node& r) {
    int s = area2(p, q, r);
    if(s > 0) return 1;
    if(s < 0) return 0;
    return between(p, q, r);
}

bool right_test(Node&p, Node& q, Node& r) {
    int s = area2(p, q, r);
    if(s > 0) return 0;
    if(s < 0) return 1;
    return between(p, q, r);
}

struct Stack {
    int a[N];
    int _top;

    void init() {
        memset(a, 0, sizeof a);
        _top = -1;
    }

    Stack() {
        _top = -1;
    }

    int empty() {
        return _top == -1;
    }

    void push(int x) {
        a[++_top] = x;
    }

    int top() {
        return a[_top];
    }
    
    int secondtop() {
        return a[_top - 1];
    }

    int thirdtop() {
        return a[_top - 2];
    }

    int pop() {
        int re = a[_top--];
        return re;
    }

    int size() {
        return _top + 1;
    }
}up, low;


void GrahamScanPoint(Node a[], int n) {
    // produce extreme edges and fill none-extreme points in b
    sort(a, a + n, [&](Node &x, Node &y) {
        return x.x != y.x ? x.x < y.x : x.y < y.y;
    });
    #ifdef DEBUGi
    for(int i = 0; i < n; ++i) {
        cout << "(" << a[i].x << ", " << a[i].y << ") ";
    }
    cout << "\n";
    #endif
    // up.init();
    // low.init();
    up.push(0);
    up.push(1);
    for(int i = 2; i < n; ++i) {
        up.push(i);
        while(up.size() >= 3 and !right_test(a[up.thirdtop()], a[up.secondtop()], a[up.top()])) {
            up.a[up._top - 1] = up.a[up._top];
            up._top--;
        }
    }

    low.push(n - 1);
    low.push(n - 2);
    for(int i = n - 3; i > -1; --i) {
        low.push(i);
        while(low.size() >= 3 and !right_test(a[low.thirdtop()], a[low.secondtop()], a[low.top()])) {
            low.a[low._top - 1] = low.a[low._top];
            low._top--;
        }
    }

    for(int i = 1; i < low.size() - 1; ++i) {
        up.push(low.a[i]);
    }
}


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i + 1;
    }

    GrahamScanPoint(a, n);

    double re = dist(a[up.a[0]], a[up.a[up.size()-1]]);
    for(int i = 1; i < up.size(); ++i) {
        re +=  dist(a[up.a[i]], a[up.a[i-1]]); 
    } 

    cout << re << "\n";
    
}