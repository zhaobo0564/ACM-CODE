#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int a[N], n, m, x, p ;

bool judge(int y) {
    int left = 0;
    int right = n;
    while (left < right) {
        int middle = (left + right) / 2;
        if (a[middle] <= x) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    if (left > 0 && a[left - 1] == y) {
        return true;
    }
    return false;
}

void solve() {
    cin >> n >> x >> p ;
    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        a[i - 1] = i;
    }
    int ct = 0;
    do{
        ct++;
        
       // cout << endl;
        if (a[p] == x && judge(a[p])) {
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            ans++;
        }
    }while(next_permutation(a, a + n ));
    cout <<"ans = " << ans <<  " " << ct << endl;

}



int main() {
    int t;
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        solve();
    }

}