#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 8;

char s[N];
int n;

int main() {
    cin >> n;
    cin >> (s + 1);
    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R') {
            a++;
        } else if (s[i] == 'P') {
            b++;
        } else {
            c++;
        }
    }
    cout << max({a, b, c}) << endl;
    return 0;
}