#include <bits/stdc++.h>

using namespace std;

void print(vector<int>& a){
    for(int i = 0; i < a.size(); ++i){
        if(i != 0) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}

void quick_sort(vector<int>& a, int l, int r){
    if(l >= r) return ;
    // 以j作划分不能以a[r]为中界,否则死循环;
    // 同理i作划分(l, i-1) / (i, r)不能以a[l]作中介且
    // 如果取中点需要(l+r+1)>>1
    int x = a[rand() % (r-l) + l]; 
    int i = l-1, j = r+1;
    while(i < j){
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) swap(a[i], a[j]);
    }

    // [l ... j][j + 1 ... r]

    quick_sort(a, l, j);
    quick_sort(a, j+1, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; ++i) cin >> a[i];

    print(a);

    quick_sort(a, 0, n-1);

    print(a);

    
}