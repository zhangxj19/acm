#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
const int N = 1e3;
int n;
struct Node {
  Node *fa, *left, *right;
  int k, p;
};

Node *root;

void bnInsert(Node *root, Node *x) {

  if (x->k <= root->k) {
    if (root->left == nullptr) {
      root->left = x;
      x->fa = root;
    } 
    else {
      bnInsert(root->left, x);
    }
  }
  else {
    if (root->right == nullptr) {
      root->right = x;
      x->fa = root;
    }
    else {
      bnInsert(root->right, x);
    }
  }
}

void heapUp(Node* x) {
  Node *pa = x->fa;
  if (pa == nullptr) {
    return ;
  }

  if (pa->p < x->p) {
    return ;
  }

  // x->fa->p >= x->p;
  Node *ppa = pa->fa;
  int l = 0;
  if (ppa != nullptr) {
    if (ppa->left == pa) {
      l = 1;
    }
  }
  if (pa->right == x) {
    pa->right = x->left;
    if (x->left != nullptr) {
      x->left->fa = pa;
    }

    x->left = pa;
    pa->fa = x;

    x->fa = nullptr;
  }
  else {

    pa->left = x->right;
    if (x->right != nullptr) {
      x->right->fa = pa;
    }

    x->right = pa;
    pa->fa = x;

    x->fa = nullptr;
  }

  if (ppa != nullptr) {
    if (l) {
      ppa->left = x;
    }
    else {
      ppa->right = x;
    }
    x->fa = ppa;
  }

  heapUp(x);
}



Node* insert(Node* root, Node* x) {
  if (root == nullptr) {
    return x;
  }


  // bninsert
  bnInsert(root, x);

  // heap up

  heapUp(x);

  if (x->fa == nullptr) {
    return x;
  }
  else {
    return root;
  }
}


void dbg(Node *root) {
  vector<pii> res;
  queue<Node *> que;
  que.push(root);
  while (que.size()) {
    Node *cur = que.front();
    que.pop();

    if (cur == nullptr) {
      continue;
    }

    res.push_back({cur->k, cur->p});
    que.push(cur->left);
    que.push(cur->right);
  }

  for (int i = 0; i < res.size(); ++i) {
    cout << "(" << res[i].first << "," << res[i].second << ")";
    if (i != res.size() - 1) {
      cout << " ";
    }
  }
  cout << "\n";
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
  root = nullptr;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    Node * nn = new Node();
    cin >> nn->k >> nn->p;
    root = insert(root, nn);

    #ifdef DEBUG
    cout << "inserted " << "{" << nn->k << ", " << nn->p << "} " << "root now is " << "{" << root->k << ", " << root->p << "}\n";
    dbg(root);
    #endif
  }

  vector<pii> res;
  queue<Node *> que;
  que.push(root);
  while (que.size()) {
    Node *cur = que.front();
    que.pop();

    if (cur == nullptr) {
      continue;
    }

    res.push_back({cur->k, cur->p});
    que.push(cur->left);
    que.push(cur->right);
  }

  for (int i = 0; i < res.size(); ++i) {
    cout << res[i].first;
    if (i != res.size() - 1) {
      cout << " ";
    }
  }
  cout << "\n";

  for (int i = 0; i < res.size(); ++i) {
    cout << res[i].second;
    if (i != res.size() - 1) {
      cout << " ";
    }
  }
  cout << "\n";


    
  return 0;
}