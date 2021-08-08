#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

int n;
double a[N];

int main() {
    ios::sync_with_stdio(0);
    while (1) {

    
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        while (1) {
            int f = 0;
            for (int i = 2; i < n; i++) {
                double cnt = a[i - 1] + a[i + 1];
                cnt = cnt / 2.0;
                if (cnt < a[i]) {
                    a[i] = cnt;
                    f = 1;
                }
            }
            if (f == 0) break;
        }
        double sum = 0;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
            sum += a[i];
        }
        cout << endl;
        cout << sum << endl;
    }
}