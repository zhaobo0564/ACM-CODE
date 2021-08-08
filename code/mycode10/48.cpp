#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(l, r) for (int i = l; i <= r; i++)
const int N = 2e5 + 7;
int n;

char a[N];

int work(int x) {
    int ans = 0, sum = 0;
    int f = 1;
    for (int i = 1; i<= n; i++) {
        sum += (a[i] - '0');
        if (sum == x) {
            ans++;
            sum = 0;
            f = i;
        } else if (sum > x) {
            return -1;
        }
    }
    
    if (ans == 1) ans = -1;
    if (f == n) {
        return ans;
    } 
    for (int i = f + 1; i <= n; i++) {
        if (a[i] != '0') {
            return -1;
        }
    }
    return ans;
}



void solve() {
    cin >> n;
    cin >> a + 1;
    int ans = -1000;
  
    for (int i = 0; i <= 10000; i++) {
        ans = max(ans, work(i));
    }
    cout << ans << endl;
}


int main() {
    int t = 1;
    while (t--) {
       solve();
    }

}