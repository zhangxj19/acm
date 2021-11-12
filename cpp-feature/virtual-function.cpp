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

using namespace std;
using pii = pair<int, int>;
class Base {
  public:
  virtual void virtualFunc() {
    cout << "(Base) virtualFunc (virtual)" << '\n';
  }
  virtual void virtualFunc2() {
    cout << "(Base) virtualFunc2 (virtual)" << '\n';
  }
  void normalFunc() {
    cout << "(Base) normalFunc (normal)" << '\n';
  }
};

class Derived: public Base {
  public:
  void virtualFunc() {
    cout << "(Derived) virtualFunc (virtual)" << '\n';
  }  
  void normalFunc() {
    cout << "(Derived) normalFunc (normal)" << '\n'; 
  }
};

class A {
  int a;
  public:
  void print() {
  }
};

class B {
  int b;
  public:
  virtual void print() {
  }
};

class Father {
  virtual void funcFather(){};
};

class Father2: Father {
  virtual void funcFather2(){};
};

class Son: Father, Father2 {
  virtual void funcFather(){ cout << "son call funcFather()" << '\n';}
  virtual void funcFather2(){ cout << "son call funcFather()" << '\n';}

  virtual void funcSon(){};
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

  Derived d;
  cout << "call from derived class object: \n";
  d.virtualFunc();
  d.virtualFunc2();
  d.normalFunc();

  Base *b = &d;
  cout << "call from base class pointer (bind derived class object): \n";
  b->virtualFunc();
  b->virtualFunc2();
  b->normalFunc();


  cout << '\n';
  A sza;
  cout << "size of object (A) = " << sizeof(sza) << '\n';
  B szb;
  cout << "size of object (B) = " << sizeof(szb) << '\n';

  Father fa;
  cout << "sizeof father (vptr) = " << sizeof (fa) << '\n';
  Son son;
  cout << "sizeof son (vptr) = " << sizeof (son) << '\n';
    
  return 0;
}