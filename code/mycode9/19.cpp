#include<bits/stdc++.h>
using namespace std;


int main() {
    long long fn[1000];
    cout << LLONG_MAX << endl;
    fn[1] = 1, fn[2] = 1;
    for (int i = 3; i <= 150; i++) {
        fn[i] = fn[i - 1] + fn[i - 2];
        cout << fn[i] << " "<<i << endl;
    }
}