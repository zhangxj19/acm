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

template <typename T>
class SharedPtr {
  public:
  SharedPtr(T* ptr = nullptr):_ptr(ptr), _pcount(new int(1)) {}

  SharedPtr(const SharedPtr& s):_ptr(s._ptr), _pcount(s._pcount) {
    (*_pcount)++;
  }

  SharedPtr<T> operator = (const SharedPtr& s) {
    if (this != &s) {
      if (--(*(this->_pcount)) == 0) {
        delete this->_ptr;
        delete this->_pcount;
      }

      _ptr = s._ptr;
      _pcount = s._pcount;
      *(this->_pount) ++;
    }

    return *this;
  }

  T& operator * () {
    return *(this->_ptr);
  }

  T* operator -> () {
    return this->_ptr;
  }

  ~SharedPtr() {
    --(*(this->_pcount));
    if (*(this->_pcount) == 0) {
      delete this->_pcount;
      this->_pcount = nullptr;
      delete this->_pcount;
      this->_pcount = nullptr;
    }
  }


  private:
  T* _ptr;
  int* _pcount;
};

class B {
  public:
  int a;
  B(int a):a(a){}
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

  B b(1);
  SharedPtr<B> pb(&b);

  cout << pb->a << '\n';

  SharedPtr<B> pbb(pb);
  pbb->a = 2;
  cout << pb->a << '\n';


  



    
  return 0;
}