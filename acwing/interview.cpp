#include <bits/stdc++.h>
using namespace std;


class A {
  public:
  virtual void func() const {
    cout << "A" << '\n';
  }
};

class B: public A {
  public:
  void func() {
    cout << "B" << '\n';
  }
};

void print(const A& x) {
  x.func();
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    A a, ar[2];

    B b;
    ar[0] = b;

    print(a);
    print(ar[0]);
    prine(b);

    return 0;
}