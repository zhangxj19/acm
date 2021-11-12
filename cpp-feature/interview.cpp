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
#include <iostream>
struct Node {
  int val;
  Node * next;
  Node (int x) {
    val = x;
  }
};

class LRUCache {
   public:
    LRUCache(int capacity) {
      csize = capacity;
      size = 0;
      head = new Node(-1);
    }
    void refer(int x) {
      auto p = head->next;
      auto pre = head;
      int find = -1;
      while (p) {
        if (p->val == x) {
          // find value    
          find = 1;
          size ++;

          if (size == csize + 1) {
            // delete rear
            auto q = p->next;
            auto preq = p; 
            while (q->next) {
              preq = q;
              q = q->next;
            }
            delete q;
            preq->next = nullptr;
            size = csize;
          }

          auto head_next = head->next;
          auto p_next = p->next; 
          head->next = p;
          p->next = head_next;
          pre->next = p_next;

          break;
        }
        pre = p;
        p = p->next;
      }
      if (find == -1) {
        // insert at front
        size ++;
        if (size == csize + 1) {
          //delete rear

          auto q = p->next;
          auto preq = p; 
          while (q->next) {
            preq = q;
            q = q->next;
          }
          delete q;
          preq->next = nullptr;

          size = csize;
        }
        auto n = new Node(x);
        n->next = head->next;
        head->next = n;
      }
    }
    void display() {
      auto p = head->next;
      while (p) {
        cout << p->val << ' ';
      }
      cout << '\n';
    }
    private:
    int csize; // maximum capacity of cache
    int size; // current size
    Node *head;
};

int main(int argc, char *argv[]) {
    LRUCache ca(4);
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display(); //! the output is: 5 4 1 3
} // namespace
