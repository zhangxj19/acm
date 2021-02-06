#include <bits/stdc++.h>

using namespace std;
#define int long long

int merge_sort(vector<int>& a, int l, int r){
    // return number of reversion pairs;
    if(l >= r) return 0;
    int mid = (l + r) >> 1;
    
    int re = 0;
    
    re += merge_sort(a, l, mid);
    re += merge_sort(a, mid+1, r);
    
    vector<int> t(r - l + 1, 0);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid and j <= r){
        if(a[i] <= a[j]) t[k++] = a[i++];
        else{
            t[k++] = a[j++];
            re += mid - i + 1;
        }
    }
    while(i <= mid) t[k++] = a[i++];
    while(j <= r) t[k++] = a[j++];
    for(int i = l; i <= r; ++i) a[i] = t[i - l];
    
    return re;
}

void merge_sort_save_space(vector<int>& a, int l, int r){
    if(l >= r) return;
    
    int m = (l + r) >> 1;
    merge_sort(a, l, m);
    merge_sort(a, m+1, r);

    int len1 = (m - l + 1), len2 = (r - (m+1) + 1);
    vector<int> t(m - l + 1, 0);
    
    for(int i = 0; i < len1; ++i) t[i] = a[i + l];
    
    int i = 0, j = (m+1), k = l;
    while(i < len1 and j - (m+1) < len2){
        if(t[i] <= a[j]) a[k++] = t[i++];
        else a[k++] = a[j++];
    }
    while(i < len1) a[k++] = t[i++];
    while(j - (m+1) < len2) a[k++] = a[j++];

}
signed main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    merge_sort(a, 0, n-1);
    for(int i = 0 ; i < n; ++i) cout << a[i] << " ";
    cout << "\n";
}