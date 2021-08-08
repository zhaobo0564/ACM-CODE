#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;



int a, b, c;
int main() {
    cin >> a >> b >> c;
    if (c == 0) {
        if (a <= b) {
            puts("Aoki");
        } else {
            puts("Takahashi");
        }
    } else {
        if (a >= b) {
            puts("Takahashi");
        } else {
            puts("Aoki");
        }
    }
   
}