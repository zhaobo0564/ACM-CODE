#include<bits/stdc++.h>
using namespace std;

const int N = 1007;

int mp[N][N], n;

int main() {
    scanf("%d", &n);
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << cnt++ << " ";
        }
        cout << endl;
    }   
    for (int i = 1; i <= n - 2; i++) {
        cout << cnt++ << " ";
    }
    cout << n * n << " " << n * n - 1 << endl;
}