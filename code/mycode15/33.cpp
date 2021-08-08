#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

long long fn[100];



void solve() {
    int s; scanf("%d", &s);
    if ((s / 2 )< 2) {
        cout << -1 << endl;
        return;
    }
    if (s % 2 == 0) {
        cout << s / 2 << endl;
    } else {
        cout << s / 2 << endl;
    } 
    
   
}

int main() {
    fn[0] = 1;
    for (int i = 1; i <= 60; i++) {
        fn[i] = fn[i - 1] * 2;
    }
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}