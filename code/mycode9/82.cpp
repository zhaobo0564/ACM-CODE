#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    for (char i: s) {
        if (i == '5') {
            cout << "*";
        } else {
            cout << i;
        }
    }
    cout << endl;
}