#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;

vector<int> a, b;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i += 2) {
        a.push_back(i);
    }
    int cnt = 0;
    if (n % 2) {
        cnt = 1;
    } else {
        cnt = 0;
    }
    while (a.size() > 1) {
        if (cnt == 1) {
            for (int i = 1; i < a.size(); i += 2) {
                b.push_back(a[i]);
            }
            if (a.size() % 2 == 0) {
                
            } else {
                cnt = 0;
            }
        } else {
            for (int i = 0; i < a.size(); i += 2) {
                b.push_back(a[i]);
            }
            if (a.size() % 2 == 0) {

            } else {
                cnt = 1;
            }
        }
        a.clear();
        for (int i = 0; i < b.size(); i++) {
            a.push_back(b[i]);
        }
        b.clear();
    }
    cout << a[0] << endl;
}