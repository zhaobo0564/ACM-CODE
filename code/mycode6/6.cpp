#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int n; scanf("%d", &n);
    ll ans = 1;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= j; k++) {
                sum += i % 199999 * j % 199999* k % 199999;
                sum %= 199999;
             //   cout << i << " " << j << " "<< k << endl;
            }
        }
       // cout << "sum " << sum << endl;
        ans = ans * sum;
        ans = ans  % 199999;
    }    
    cout << ans << endl;
}
//126044963295251