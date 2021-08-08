#include<bits/stdc++.h>
using namespace std;
string str;
typedef long long ll;

int main() {
    srand(time(0));
    int n = 100;
    int last = -1;
    for (int i = 1; i <= n; i++) {
        int x = rand() % 4;
        while (x == last) {
            x = rand() % 4;
        }
        if (x == 0) {
            printf("W");
        } else if (x == 1) {
            printf("A");
        } else if (x == 2) {
            printf("S");
        } else {
            printf("D");
        }
        last = x;
    }
    puts("");
}