#include<bits/stdc++.h>
using namespace std;

long long visx[20000], visy[20000];
    
long long findPairs(long long a, long long b, long long c, long long d) {
    // write code here
   int cnta = (a - 1) / 2021;
   int cntb = (b) / 2021;
   int cnt = cntb - cnta;
   for (int i = 0; i < 2021; i++) {
       visx[i] = cnt;
   }
   cnt = b % 2021;
   for (int i = 1; i <= cnt; i++) {
       visx[i]++;
   }
   cnt = (a - 1) % 2021;
   for (int i = 1; i <= cnt; i++) {
       visx[i]--;
   }
   cnta = (c - 1) / 2021;
   cntb = d / 2021;
   cnt = cntb - cnta;
   for (int i = 0; i < 2021; i++) {
       visy[i] = cnt;
   }
   cnt = d % 2021;
   for (int i = 1; i <= cnt; i++) {
       visy[i]++;
   }
   cnt = (c - 1) % 2021;
   for (int i = 1; i <= cnt; i++) {
       visy[i]--;
   }
   long long ans = 0;
   for (int i = 0; i < 2021; i++) {
       for (int j = 0; j < 2021; j++) {
           if (i * j % 2021 == 0) {
               ans += visx[i] * visy[j];
           }
       }
   }
   return ans;
    
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << findPairs(a, b, c, d) << endl;
}