// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <limits>
#include <bits/stdc++.h>

using namespace std;
const int N = 15;
int f[2][N][N][N][N][1005];

int dir[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1},
};

class Solution {
public:
	int s1, s2;
    /* Write Code Here */
	int m, n;
	vector<string> mp;
	int ans;
	int ex, ey;

	int isInMap(int x, int y) {
		return 0 <= x and x < m and 0 <= y and y < n;
  }

	int isMeWin(int isMe, int x1, int y1, int x2, int y2, int step) {
    #ifdef DEBUG2
    if (isMe)
    cout << "now " << isMe << " " << x1 << " " << y1 << " " << x2 << " " << y2  << " " << step << "\n";
    #endif
    auto& v = f[isMe][x1][y1][x2][y2][step];

    #ifdef DEBUG2
    cout << "v = " << v << "\n";
    #endif
    if (v != -1) {
      #ifdef DEBUG2
      cout << "get solved v = " << v << "\n";
      #endif 
      return v;
    }
    else {
      if (x1 == ex and y1 == ey) {
        if (!isMe) {
          ans = min(ans, step - 1);
        }
        else {
          ans = min(ans, step);
        }
        return v = 1;
      }
      if (step >= 1000 or x1 == x2 and y1 == y2) {
                
          return v = 0; // devil win
      }
      if (isMe) {
          // me
          int meWin = false;
          for (int i = 0; i < 4; ++i) {
              int dx = dir[i][0], dy = dir[i][1];
              for (int j = 0; j <= s1; ++j) {
                  int nx = x1 + dx * j;
                  int ny = y1 + dy * j;
                  if (isInMap(nx, ny)) {
                    // 0 1 2
                      if (mp[nx][ny] == '0') {
                          // can go
                          int t = isMeWin(!isMe, nx, ny, x2, y2, step + 1);
                          if (t == 1) {
                              meWin = true;
                          }
                      }
                            
                      // if (mp[nx][ny] == 'e') {
                      //     ans = step + 1;
                      //     return v = 1;
                      // }

                      if (mp[nx][ny] == '1') {
                          break;
                      }
                            
                      // meet '2' then continue;
                  }
              }
          }
          //if (!meWin) {
          if (!meWin) {
            return v = 0;
          }
          else {
            return v = 1;
          }
          //}
      }
      else {
          // devil
				  int devilWin = false;
          for (int i = 0; i < 4; ++i) {
              int dx = dir[i][0], dy = dir[i][1];
              for (int j = 0; j <= s2; ++j) {
                  int nx = x2 + dx * j;
                  int ny = y2 + dy * j;
                  if (isInMap(nx, ny)) {
                    // 0 1 2 
                      if (mp[nx][ny] == '0') {
                          int t = isMeWin(!isMe, x1, y1, nx, ny, step + 1);
                          if (t == 0) {
                              return v = 0;
                          }
                      }
                      if (nx == x1 and ny == y1) {
                          // catch me 
                          return v = 0;
                      }
                            
                      if (mp[nx][ny] == '2') {
                        break;
                      }
                            
                      // meet '1' then continue;
                            
                  }
                        
                        
              }
          }
          //if (!devilWin) {
            return v = 1;
          //}
      }
    }
  }
	

  int throughMaze(int yourSteps, int devilSteps, vector < string > maze) {
      m = maze.size();
      n = maze[0].size();
      s1 = yourSteps;
      s2 = devilSteps;
      mp = maze;
      ans = 0;
      int sx, sy;
      int dx, dy;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j){
              if (mp[i][j] == 's') {
                  sx = i;
                  sy = j;
                  mp[i][j] = '0';
              }
              if (mp[i][j] == 'e') {
                  ex = i;
                  ey = j;
                  mp[i][j] = '0';
              }
              if (mp[i][j] == 'd') {
                  dx = i;
                  dy = j;
                  mp[i][j] = '0';
              }
        }
      }
      #ifdef DEBUG2
      for (int i = 0; i < m; ++i) {
        cout << mp[i] << "\n";
      } 
      cout << sx << " " << sy << " " << dx << " " << dy << "\n";
      cout << m << " " << n << "\n";
      #endif
      memset(f, -1, sizeof f);
      ans = 1e9;
      if (isMeWin(1, sx, sy, dx, dy, 0)) {
          return ans;
      }
      else {
          return -1;
      }
  }
};

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  int res;

  int _yourSteps;
  cin >> _yourSteps;
  cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


  int _devilSteps;
  cin >> _devilSteps;
  cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


  int _maze_size = 0;
  cin >> _maze_size;
  cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
  vector<string> _maze;
  string _maze_item;
  for(int _maze_i=0; _maze_i<_maze_size; _maze_i++) {
      getline(cin, _maze_item);
      _maze.push_back(_maze_item);
  }
  Solution *s = new Solution();
  res = s->throughMaze(_yourSteps, _devilSteps, _maze);
  cout << res << endl;
    
  return 0;

}
