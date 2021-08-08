#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
long long sum[N];

void init(int a, int b){
    for (int i = a; i <= b; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0) {
                sum[j]++;
                if (i / j != j) {
                    sum[i / j]++;
                }
            }
        }
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    init(a, b);
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (sum[i] > 1) {
            ans = i;
        }
    }
    cout << ans << endl;
}