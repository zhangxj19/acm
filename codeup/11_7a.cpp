#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int main()
{
    int V, n, num;
    int a[20005] = {0};
    cin >> V >> n ;
    while(n--)
    {
        cin >> num ;
        for(int i=V; i>=num; i--)
            if( a[i-num] + num > a[i] )
                a[i] = a[i-num] + num ;
    }
    cout << V-a[V] << endl ;
 
    return 0;
}