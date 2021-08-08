#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        puts("champion");
    } else {
        int au = n * 10;
        if (au % 100) {
            au = au / 100 + 1;
        } else {
            au = au / 100;
        }
        int ag = n * 15;
        if (ag % 100) {
            ag = ag / 100 + 1;
        } else {
            ag = ag / 100;
        }
        ag += au;
        int cu = n * 25;
        if (cu % 100) {
            cu = cu / 100 + 1;
        } else {
            cu = cu / 100;
        }
        cu += ag;
        if (k <= au) {
            puts("au");
        } else if (k <= ag) {
            puts("ag");
        } else if (k <= cu) {
            puts("cu");
        } else {
            puts("fe");
        }
    }
    return 0;
}