#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;



ll n, len;

ll a[N];

double lsum[N], rsum[N];



void solve() {
    cin >> n >> len;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lsum[i] = 0;
        rsum[i] = 0;
    }
    rsum[n + 1] = 0;

    double v = 1.0;
    for (int i = 1; i <= n; i++) {
        lsum[i] = (double)(a[i] - a[i - 1]) / v;
        lsum[i] = lsum[i] + lsum[i - 1];
        v += 1;
    }
    v = 1;
    a[n + 1] = len;
    for (int i = n; i; i--) {
        rsum[i] = (double)(a[i + 1] - a[i]) / v;
     //   cout << "AA: " << rsum[i] << endl;
        rsum[i] = rsum[i + 1] + rsum[i];
        v += 1;
    }
    double ans =1e15;

    for (int i = n; i ; i--) {
        double t = rsum[i];
        int pos = upper_bound(lsum + 1, lsum + n + 1, t) - lsum;
        pos--;
       // cout << "pos " << pos << " t = " << t << endl;
        double v1 = pos + 1;
        double v = (n - i + 1) + 1;
        double s = a[pos] + (v1 * (t - lsum[pos]));
        if (s >= a[i]) {
            ans = min(ans, t);
        } else {  
            double s1 = a[i];
            double cnt = s1 - s;
           
           
            v += v1;
            double cat = cnt / v;
            ans = min(ans, t + cat);
        }
        
    }
    vector<double>g;
    for (int i = 1; i <= n; i++) {
        g.push_back(rsum[i]);
    }
    reverse(g.begin(), g.end());
    rsum[n + 1] = 0;

     for (int i = 1; i <= n ; i++) {
        double t = lsum[i];
        int pos = upper_bound(g.begin(), g.end(), t) - g.begin();
        pos;
        pos = n - pos;
        pos++;
        double v = i + 1;
        double v1 = (n - pos + 1) + 1;
        double s1 = a[pos] - (t - rsum[pos]) * v1;
     
        if (s1 <= a[i]) {
            ans = min(ans, t);
        } else {
        
            double s = a[i];
            double cnt = s1 - s;
            v += v1;
            //cout << "cnt = " << cnt << endl;
            double cat = cnt / v;
           // cout << "cat " << cat << endl;
            ans = min(ans, t + cat);
        }
        
    }
    
    printf("%.6lf\n", ans);
}

int main() {
   // ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    
}