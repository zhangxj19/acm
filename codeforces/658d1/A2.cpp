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

#define int long long
using namespace std;
using pii = pair<int, int>;

int n;
char a[100005], b[100005];
bool flipped[100005], tmp[100005];


void flip(int p) {
  memcpy(tmp, flipped, p * sizeof(bool));
  for (int i = 0; i < p; ++i) {
    flipped[i] = !tmp[p - 1 - i];
  }
}

void flip(int p, char a[]) {
  int i=  0, j = p - 1;
  while (i < j) {
    swap(a[i], a[j]);
    a[i] = !(a[i] - '0') + '0';
    a[j] = !(a[j] - '0') + '0';
    i ++;
    j --;
  }
  if (i == j) a[i] = !(a[i] - '0') + '0';
}

char get_a(int i) {
  return flipped[i] ? (!(a[i] - '0')) + '0' : a[i]; 
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
  int tt;
  cin >> tt;
  while (tt--) {
    memset(flipped, false, sizeof flipped);
    cin >> n >> a >> b;
    vector<int> res;
    for (int i = n - 1; i >= 0; --i) {
      char ai = get_a(i), a0 = get_a(0);
      if (i) {
        if (ai != b[i]) {
          if (a0 != ai) {
            flip(1);
            res.push_back(1);
          }
          flip(i + 1);
          res.push_back(i + 1);
        }
      }
      else {
        if (ai != b[i]) {
          flip(1);
          res.push_back(1);
        }
      }
    }

    cout << res.size();
    for (auto &x : res) {
      cout << " " << x;
    }
    cout << '\n';

    #ifdef LOCAL
    cout << "simulation begins\n";
    cout << a << " " << b << "\n";
    for (auto &x : res) {
      flip(x, a);
      cout << a << '\n';
    }
    #endif

  }



    
  return 0;
}