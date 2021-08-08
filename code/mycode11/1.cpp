#include<bits/stdc++.h>
using namespace std;

const int N= 1007;
typedef long long ll;
int n;

ll mp[N][N];
ll a[N];

int main() {
    cin >> n;
    ll sum = 0;
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
           cin >> mp[i][j];
          
            sum += mp[i][j];
        }
     //   cout << endl;
    }
 //   cout << endl;
    if (n == 2) {
        cout << 1 << " " << mp[1][2] - 1 << endl;
        return 0;
    }
    ll all = sum / (2 * n - 2);
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += mp[i][j];
        }
        cout << (sum - all) / (n - 2) << " ";
    }
    cout << endl;

}