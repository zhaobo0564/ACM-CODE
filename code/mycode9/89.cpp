#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, t, a[2000], b[2000];

int main() {
   cin >> n >> m >> t;
   for (int i = 1; i <= m; i++) {
       cin >> a[i] >> b[i];
   }
   ll sum = n;
   for (int i = 1; i <= m; i++) {
       sum -= (a[i] - b[i - 1]);
       if (sum <= 0) break;
       sum += (b[i] - a[i]);
       if (sum > n) sum = n;
   }
   sum -= (t - b[m]);
   
   if (sum > 0) {
       cout << "Yes\n";
   } else {
       cout << "No\n";
   }
}