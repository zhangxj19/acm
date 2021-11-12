#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#include <memory>

using namespace std;
using pii = pair<int, int>;

int sizeOf(char *arr) {
  return sizeof(arr);
}

class A{};

class B {
  char a;
  int b, c;
  short d;
};

class C {
  int a, b;
  char c;
  short d;
};

class D {
  int mem;
  virtual void func() {

  }
};

class E : D {
  
};

class F : virtual D {

};



signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  char c[20] = "12345";
  cout << "sizeof char c[20] = " << sizeof(c) << '\n';
  cout << "strlen of char c[20] = \"12345\" = " << strlen(c) << '\n';

  cout << "sizeof char* = " << sizeOf(c) << '\n';

  cout << "sizeof empty class A = " << sizeof(A) << '\n';
  A a;
  cout << "sizeof empty class A a = " << sizeof(a) << '\n';
  B b;
  cout << "sizeof class (char int int short) = " << sizeof(b) << '\n';
  C cc;
  cout << "sizeof class (int int char short) = " << sizeof(cc) << '\n';

  E e;
  cout << "sizeof derived class (origal int + vptr) = " << sizeof(e) << "\n";
  F f;
  cout << "sizeof virtual derived class (origal int + vptr) = " << sizeof(f) << "\n";

    
  return 0;
}