#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
typedef long long ll;

char a[N], b[N];

int visa[200], visb[200];

void solve() {
    int n, k;
    for (int i = 'a'; i <= 'z'; i++) {
        visa[i] = visb[i] = 0;
    }
    cin >> n >> k;
    cin >> (a + 1) >> (b + 1);
    for (int i = 1; i <= n; i++) {
        visa[a[i]]++;
        visb[b[i]]++;
    }
    for (int i = 'a'; i <= 'z'; i++){
        if (visb[i] <= visa[i]) {
            visa[i] -= visb[i];
            continue;
        }
        int cnt = visb[i] - visa[i];
      //  visa[i] = 0;
       // cout << char(i) << " " << cnt << endl;
    
        for (int j = i - 1; j >= 'a'; j--) {
            if (visa[j] >= k) {
                int cn = visa[j] / k;
                if (cnt >= cn * k) {
                    cnt -= cn * k;
                    visa[j] -= cn * k;
                } else if (visa[j] >= cnt && cnt % k == 0) {
                  //  cout << "AA  " << char(j) << endl;
                   
                    visa[j] -= cnt; cnt = 0;
                }
                
            }
        }
        if (cnt == 0) {
            visa[i] = 0;
        }
     
    }

    for (int i = 'a'; i <= 'z'; i++) {
        if (visa[i]) {
            cout << "NO\n";
            return;
           // cout << char(i) << " " << visa[i] << endl;
        }
    }
    cout << "YES\n";
    

}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}