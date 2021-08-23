#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double 
double a, b, c;
const double eps = 1e-8;

int getXr(double x) {
  return b * x + c - sqrt(2 * a * x) > 0;
}

int getXl(double x) {
  return b * x + c + sqrt(2 * a * x) > 0;
}

double integralParabola(double x1, double x2) {
  return sqrt(2 * a) * 2 / 3 * (powf(x2, 1.5) - powf(x1, 1.5));
}

double integralLine(double x1, double x2, int sign) {
  if (sign) {
    return -integralLine(x1, x2, 0);
  }
  else {
    return b / 2 * (x2 * x2 - x1 * x1) + c * (x2 - x1);
  }
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
  int T;
  cin >> T;
  while (T--) {
    cin >> a >> b >> c;
    // a >= 1 b >= 1
    double xm = -c / b;
    if (xm < 0) {
      double delta = powf(2 * b * c - a * a, 2) - 4 * b * b * c * c;
      if (delta < 0) {
        cout << "0\n";
        continue;
      }  
      double xl = (-(2 * b * c - 2 * a) - sqrt(delta)) / (2 * a);
      double xr = (-(2 * b * c - 2 * a) + sqrt(delta)) / (2 * a);

      double ans =0 ;
      ans += integralParabola(xl, xr) - integralLine(xl, xr, 0);

      cout << ans << "\n";
    } 
    else if(xm > 0) {
      double l = 0, r = 1e5;

      while (r - l > eps) {
        double mid = (l + r) / 2;
        if (getXr(mid)) {
          r = mid;
        }
        else {
          l = mid;
        }
      }
      double xr = l;

      l = 0, r = 1e5 + 5;
      while (r - l > eps) {
        double mid = (l + r) / 2;
        if (getXl(mid)) {
          r = mid;
        }
        else {
          l = mid;
        }
      }

      double xl = l;

      double ans = 0;
      ans += integralParabola(0, xl) + integralLine(xl, xm, 1) + integralParabola(0, xm) + integralParabola(xm, xr) - 
            integralLine(xm, xr, 0);

      cout << ans << "\n";

    }
    else if (abs(xm) < eps){
      // xm == 0
      double l = 0, r = 1e5;

      while (r - l > eps) {
        double mid = (l + r) / 2;
        if (getXr(mid)) {
          r = mid;
        }
        else {
          l = mid;
        }
      }
      double xr = l;

      double ans = 0;
      ans += integralParabola(0, xr) - integralLine(0, xr, 0); 
      cout << ans << "\n";
    }

  }
    
  return 0;
}