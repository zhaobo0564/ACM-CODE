#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int a[N], n;

int b[10];

bool judge(int pos) {
    for (int i = 1; i <= 6; i++) {
        if (a[pos + i - 1] != b[i]) {
            return false;
        } 
    }
    return true;
}

int main() {
    b[1] = 1, b[2] = 1, b[3] = 4, b[4] = 5, b[5] = 1, b[6] = 4;
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i + 5 <= n) {
            if (judge(i)) {
                a[i + 5] = 5;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}