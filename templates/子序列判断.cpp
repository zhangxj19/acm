// 判断a是否是b的子序列(双指针)
// 线性扫描,在b中一一寻找a中映射关系
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];
    int i = 0, j = 0;
    while(i < n and j < m){
        if(a[i] == b[j]) i++; 
        j++;
    }
    
    cout << (i == n ? "Yes" : "No") << "\n";
    
}