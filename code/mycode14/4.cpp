#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
typedef long long ll; 
int a, b, c;

void solve() {
    cin >> a >> b >> c;
    int aa = a, bb = b;
    if (a < b) {
        swap(a, b);
    }
    vector<int>A, B;
    if (b == c) {
        A.push_back(1);
        for (int i = 1; i < a; i++) {
            A.push_back(0);
        }
        B.push_back(1);
        for (int i = 1; i < b; i++) {
            B.push_back(0);
        }
        
    } else {
        int cnt = b - c;
        A.push_back(1);
        for (int i = 1; i < a; i++) {
            A.push_back(0);
        }
        B.push_back(1);
        for (int i = 1; i <= cnt; i++) {
            B.push_back(1);
        }
        for (int i = 1; i < c; i++) {
            B.push_back(0);
        }
    }
    if (aa < bb) {
        swap(A, B);
    }
    for (int i: A) {
        cout << i;
    }
    cout << " ";
    for (int i: B) {
        cout <<i;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}