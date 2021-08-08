#include<bits/stdc++.h>
using namespace std;

int visx[200000], visy[200000];

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long ans1 = 0;
    for (int i = a; i <= b; i++) {
        for (int j = c; j <= d; j++) {
            if (i * j % 2021 == 0) {
                ans1++;
            }
        }
    }
    cout << ans1 << endl;
    long long ans = 0;
    for (int i = a; i <= b; i++) {
        visx[i % 2021]++;
    }
    for (int i = c; i <= d; i++) {
        visy[i % 2021]++;
    }
    for (int i = 0; i < 2021; i++) {
        for (int j = 0; j < 2021; j++) {
            if (i * j % 2021 == 0) {
                ans += visx[i] * visy[j];
            } 
        }
    }


    cout << ans << endl;
}