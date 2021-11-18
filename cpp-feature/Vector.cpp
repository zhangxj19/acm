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

template<typename T>
class Vector {
  public:
  Vector(int vol): vol(vol) {
    sz = 0;
  }

  void push_back(const T& x) {
    if (sz == vol) {
      expand();
    }
    _a[sz++] = x;
  }

  void expand() {
    T* n = new T[vol * 2];

    for (int i = 0; i < sz; ++i) {
      n[i] = _a[i];
    }

    vol = 2 * vol;
    delete a;
    a = n;
  }

  void pop_back() {
    if (sz) {
      sz --;
      if (sz < vol / 2) {
        // shrink
        shrink();
      }
    }
  }

  void shrink() {
    vol /= 2;
    T* n = new T[vol];
    for (int i = 0; i < sz; ++i) {
      _a[i] = n[i];
    }
    delete a;
    _a = n;
  }


  private:
  T* _a;
  int sz, vol;
}

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');

    
  return 0;
}