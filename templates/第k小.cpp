#include <bits/stdc++.h>

using namespace std;

int kth(vector<int>& a, int l, int r, int k){
    if(l >= r) return a[r];
    
    int i = l - 1, j = r + 1;
    int x = a[rand()%(r - l) + l];
    
    while(i < j){
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) swap(a[i], a[j]);
    }
    // [l ... j] [j + 1 ... r]
    int sl = j - l + 1;
    if(k <= sl) return kth(a, l, j, k);
    
    return kth(a, j+1, r, k - sl);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
       cin >> a[i]; 
    }
    int re = kth(a, 0, n-1, k);
    cout << re << '\n';
}