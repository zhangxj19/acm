#include <iostream>

#include "TutorialConfig.h"

int main(int argc, char* argv[]) {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');

  std::cout << "tutorial.cpp\n";
  std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
            << Tutorial_VERSION_MINOR << std::endl;
  if (argc < 2) {
    // report version
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

    
  return 0;
}